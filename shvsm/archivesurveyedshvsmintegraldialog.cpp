#include <QMenu>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPainter>
#include <QScrollBar>
#include "archivesurveyedshvsmintegraldialog.h"
#include "ui_archivesurveyedshvsmintegraldialog.h"

extern float normalize(float);
extern void getIR(int,int,bool,float&,float&,float&,float&);
extern void getIS(int,int,bool,float&,float&,float&,float&);
extern void getIG(int,int,bool,float&,float&,float&,float&);
extern void getSOK(int,int,bool,float&,float&,float&,float&);
extern void getMOK(int,int,bool,float&,float&,float&,float&);
extern void getOPSS(int,int,bool,float&,float&,float&,float&);
extern void getVC(int,int,bool,float&,float&,float&,float&);
extern void getKEK(int,int,bool,float&,float&,float&,float&);


ArchiveSurveyedSHVSMIntegralDialog::ArchiveSurveyedSHVSMIntegralDialog(QSqlDatabase* pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveSurveyedSHVSMIntegralDialog)
{
    ui->setupUi(this);
    db = pdb;
    isLegend = isGraph[0] = isGraph[1] = true;
    setupForm();
}

ArchiveSurveyedSHVSMIntegralDialog::~ArchiveSurveyedSHVSMIntegralDialog()
{
    delete ui;
    delete modelSurveyed;
    delete modelSurvey;
}

void ArchiveSurveyedSHVSMIntegralDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}


void ArchiveSurveyedSHVSMIntegralDialog::setupForm(void)
{
    // Список обследованных
    modelSurveyed = new QSqlQueryModel(this);
    modelSurveyed->setQuery(QString("SELECT surveyed.id,surveyed.name,sex.name,sex_id,qualification_id FROM surveyed, sex WHERE surveyed.sex_id = sex.id ORDER BY surveyed.name"));
    modelSurveyed->setHeaderData(1, Qt::Horizontal, tr("Name"));
    modelSurveyed->setHeaderData(2, Qt::Horizontal, tr("Sex"));

    ui->twSurveyed->setModel(modelSurveyed);
    ui->twSurveyed->setColumnHidden(0, true);
    ui->twSurveyed->setColumnHidden(3, true);
    ui->twSurveyed->setColumnHidden(4, true);
    ui->twSurveyed->resizeColumnsToContents();
    ui->twSurveyed->setCurrentIndex(ui->twSurveyed->model()->index(0, 0));


    // Обследование 'ШВСМ-интеград'
    surveyedId = ui->twSurveyed->model()->data(ui->twSurveyed->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),0)).toInt();

    modelSurvey = new QSqlQueryModel(this);
    modelSurvey->setQuery(QString("SELECT dt,qualification.name,old,weight,growth,HR,SAD,DAD,T1,T2,VL,VLN,VLD,V1,V2,V3,V4,V5,V6,V7,V8,V9,V10,V11,V12,V13  \
                                   FROM surveySHVSMIntegral,surveyed,qualification \
                                   WHERE surveySHVSMIntegral.surveyed_id = surveyed.id AND surveyed.id = %1 AND \
                                   surveyed.qualification_id = qualification.id \
                                   ORDER BY dt").arg(surveyedId));
    modelSurvey->setHeaderData(0, Qt::Horizontal, tr("Date"));
    modelSurvey->setHeaderData(1, Qt::Horizontal, tr("Qualification"));
    modelSurvey->setHeaderData(2, Qt::Horizontal, tr("Old"));
    modelSurvey->setHeaderData(3, Qt::Horizontal, tr("Weight"));
    modelSurvey->setHeaderData(4, Qt::Horizontal, tr("Height"));
    modelSurvey->setHeaderData(5, Qt::Horizontal, tr("HR"));
    modelSurvey->setHeaderData(6, Qt::Horizontal, tr("SBP"));
    modelSurvey->setHeaderData(7, Qt::Horizontal, tr("DBP"));
    modelSurvey->setHeaderData(8, Qt::Horizontal, tr("DTE"));
    modelSurvey->setHeaderData(9, Qt::Horizontal, tr("DTBE"));
    modelSurvey->setHeaderData(10, Qt::Horizontal, tr("VCL"));
    modelSurvey->setHeaderData(11, Qt::Horizontal, tr("VCLN"));
    modelSurvey->setHeaderData(12, Qt::Horizontal, tr("VCLD"));
    modelSurvey->setHeaderData(13, Qt::Horizontal, tr("SBV"));
    modelSurvey->setHeaderData(14, Qt::Horizontal, tr("MVB"));
    modelSurvey->setHeaderData(15, Qt::Horizontal, tr("CI"));
    modelSurvey->setHeaderData(16, Qt::Horizontal, tr("TPR"));
    modelSurvey->setHeaderData(17, Qt::Horizontal, tr("VH"));
    modelSurvey->setHeaderData(18, Qt::Horizontal, tr("IR"));
    modelSurvey->setHeaderData(19, Qt::Horizontal, tr("CEBC"));
    modelSurvey->setHeaderData(20, Qt::Horizontal, tr("DSBP"));
    modelSurvey->setHeaderData(21, Qt::Horizontal, tr("DDBP"));
    modelSurvey->setHeaderData(22, Qt::Horizontal, tr("HI"));
    modelSurvey->setHeaderData(23, Qt::Horizontal, tr("IS"));
    modelSurvey->setHeaderData(24, Qt::Horizontal, tr("LFSCS"));
    modelSurvey->setHeaderData(25, Qt::Horizontal, tr("LFSSER"));


    // -------------------------------------------------------
    ui->twSurveyedOutput1->setModel(modelSurvey);
    ui->twSurveyedOutput1->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());

    for (int i = 11; i < 26; i++)
        ui->twSurveyedOutput1->setColumnHidden(i, true);

    ui->twSurveyedOutput1->resizeColumnsToContents();
    ui->twSurveyedOutput1->setCurrentIndex(ui->twSurveyedOutput1->model()->index(0, 0));

    // -------------------------------------------------------
    ui->twSurveyedOutput2->setModel(modelSurvey);
    ui->twSurveyedOutput2->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());
    for (int i = 0; i < 13; i++)
        ui->twSurveyedOutput2->setColumnHidden(i, true);
    ui->twSurveyedOutput2->setColumnHidden(22, true);
    ui->twSurveyedOutput2->setColumnHidden(23, true);
    ui->twSurveyedOutput2->setColumnHidden(25, true);

    ui->twSurveyedOutput2->resizeColumnsToContents();
    ui->twSurveyedOutput2->setCurrentIndex(ui->twSurveyedOutput2->model()->index(0, 0));

    ///////////////
    ui->twSurveyedOutput2->setItemDelegate(new ColorDelegateSurveyedSHVSMIntegral(this,this));
    ///

    // -------------------------------------------------------
    ui->twSurveyedOutput3->setModel(modelSurvey);
    ui->twSurveyedOutput3->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());
    for (int i = 0; i < 22; i++)
        ui->twSurveyedOutput3->setColumnHidden(i, true);
    ui->twSurveyedOutput3->setColumnHidden(24, true);
    ui->twSurveyedOutput3->setColumnHidden(11, false);
    ui->twSurveyedOutput3->setColumnHidden(12, false);

    ui->twSurveyedOutput3->resizeColumnsToContents();
    ui->twSurveyedOutput3->setCurrentIndex(ui->twSurveyedOutput3->model()->index(0, 0));

    ///////////////
    ui->twSurveyedOutput3->setItemDelegate(new ColorDelegateSurveyedSHVSMIntegral(this,this));
    ///

    connect(ui->twSurveyed->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&)));

    connect(ui->twSurveyedOutput1->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurvey1(const QItemSelection&, const QItemSelection&)));
    connect(ui->twSurveyedOutput2->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurvey2(const QItemSelection&, const QItemSelection&)));
    connect(ui->twSurveyedOutput3->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurvey3(const QItemSelection&, const QItemSelection&)));

    ui->widgetPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->widgetPlot->xAxis->setAutoTickLabels(false);
    ui->widgetPlot->xAxis->setAutoTicks(false);
    ui->widgetPlot->xAxis->setLabel(tr("Date"));
    ui->widgetPlot->yAxis->setLabel(tr("Point"));

    connect(ui->widgetPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));

    ui->widgetPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->widgetPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));

    isSportsman = (ui->twSurveyed->model()->data(ui->twSurveyed->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),4)).toInt() == 1) ? true : false;
    sex = ui->twSurveyed->model()->data(ui->twSurveyed->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),3)).toInt();
    old = ui->twSurveyedOutput1->model()->data(ui->twSurveyedOutput1->model()->index(ui->twSurveyedOutput1->selectionModel()->currentIndex().row(),2)).toInt();

    rePlot();
}


void ColorDelegateSurveyedSHVSMIntegral::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    float val = 0;

    if (qVariantCanConvert<float>(index.data()))
        val = qVariantValue<float>(index.data());
    if (/*val &&*/ ((index.column() > 12 && index.column() < 15) || (index.column() > 15 && index.column() < 20) || (index.column() > 21 && index.column() < 26)))
        painter->fillRect(option.rect, ptr->getIndicatorColor(index.column(), val));
    QItemDelegate::paint(painter,option,index);
}

QColor ArchiveSurveyedSHVSMIntegralDialog::getIndicatorColor(int index, float indicator)
{
    float val1 = 0,
          val2 = 0,
          val3 = 0,
          val4 = 0;

    switch (index)
    {
        case 13:
            getSOK(sex,old,isSportsman,val1,val2,val3,val4);
            break;
        case 14:
            getMOK(sex,old,isSportsman,val1,val2,val3,val4);
            break;
        case 16:
            getOPSS(sex,old,isSportsman,val1,val2,val3,val4);
            break;
        case 17:
            getVC(sex,old,isSportsman,val1,val2,val3,val4);
            break;
        case 18:
            getIR(sex,old,isSportsman,val1,val2,val3,val4);
            break;
        case 19:
            getKEK(sex,old,isSportsman,val1,val2,val3,val4);
            break;
        case 22:
            getIG(sex,old,isSportsman,val1,val2,val3,val4);
            break;
        case 23:
            getIS(sex,old,isSportsman,val1,val2,val3,val4);
            break;
        case 24:
        case 25:
            val1 = 33.0;
            val2 = 49.6;
            val3 = 66.1;
            val4 = 82.6;
    }

    if (indicator < val1)
        return QColor("red");
    else if (indicator >= val1 && indicator <= val2)
        return QColor("gray");
    else if (indicator > val2 && indicator <= val3)
        return QColor("yellow");
    else if (indicator > val3 && indicator <= val4)
        return QColor("aqua");
    else
        return QColor("lime");
}

void ArchiveSurveyedSHVSMIntegralDialog::slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&)
{
    surveyedId = ui->twSurveyed->model()->data(ui->twSurveyed->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),0)).toInt();
    modelSurvey->setQuery(QString("SELECT dt,qualification.name,old,weight,growth,HR,SAD,DAD,T1,T2,VL,VLN,VLD,V1,V2,V3,V4,V5,V6,V7,V8,V9,V10,V11,V12,V13  \
                                   FROM surveySHVSMIntegral,surveyed,qualification \
                                   WHERE surveySHVSMIntegral.surveyed_id = surveyed.id AND surveyed.id = %1 AND \
                                   surveyed.qualification_id = qualification.id \
                                   ORDER BY dt").arg(surveyedId));
    ui->twSurveyedOutput1->setCurrentIndex(ui->twSurveyedOutput1->model()->index(0, 0));
    ui->twSurveyedOutput2->setCurrentIndex(ui->twSurveyedOutput2->model()->index(0, 0));
    ui->twSurveyedOutput3->setCurrentIndex(ui->twSurveyedOutput3->model()->index(0, 0));

    isSportsman = (ui->twSurveyed->model()->data(ui->twSurveyed->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),4)).toInt() == 1) ? true : false;
    sex = ui->twSurveyed->model()->data(ui->twSurveyed->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),3)).toInt();
    old = ui->twSurveyedOutput1->model()->data(ui->twSurveyedOutput1->model()->index(ui->twSurveyedOutput1->selectionModel()->currentIndex().row(),2)).toInt();

    rePlot();
}

void ArchiveSurveyedSHVSMIntegralDialog::slotSelectionChangedSurvey1(const QItemSelection&, const QItemSelection&)
{
    currentRow = ui->twSurveyedOutput1->selectionModel()->currentIndex().row();
    old = ui->twSurveyedOutput1->model()->data(ui->twSurveyedOutput1->model()->index(ui->twSurveyedOutput1->selectionModel()->currentIndex().row(),2)).toInt();
    scrollView();
}

void ArchiveSurveyedSHVSMIntegralDialog::slotSelectionChangedSurvey2(const QItemSelection&, const QItemSelection&)
{
    currentRow = ui->twSurveyedOutput2->selectionModel()->currentIndex().row();
    scrollView();
}

void ArchiveSurveyedSHVSMIntegralDialog::slotSelectionChangedSurvey3(const QItemSelection&, const QItemSelection&)
{
    currentRow = ui->twSurveyedOutput3->selectionModel()->currentIndex().row();
    scrollView();
}

void ArchiveSurveyedSHVSMIntegralDialog::scrollView(void)
{
    ui->twSurveyedOutput1->setCurrentIndex(ui->twSurveyedOutput1->model()->index(currentRow, 0));
    ui->twSurveyedOutput1->verticalScrollBar()->setValue(ui->twSurveyedOutput1->selectionModel()->currentIndex().row());

    ui->twSurveyedOutput2->setCurrentIndex(ui->twSurveyedOutput2->model()->index(currentRow, 0));
    ui->twSurveyedOutput2->verticalScrollBar()->setValue(ui->twSurveyedOutput2->selectionModel()->currentIndex().row());

    ui->twSurveyedOutput3->setCurrentIndex(ui->twSurveyedOutput3->model()->index(currentRow, 0));
    ui->twSurveyedOutput3->verticalScrollBar()->setValue(ui->twSurveyedOutput3->selectionModel()->currentIndex().row());
}

void ArchiveSurveyedSHVSMIntegralDialog::rePlot(void)
{
    QPen graphPen;
    QColor color[2] = { "reg", "green" };
    QSqlQuery query;
    QString grName[2];
    QVector<QString> dt;
    QVector<double> x[2],
                    y[2];


    ui->widgetPlot->legend->setVisible(isLegend);
    ui->widgetPlot->clearGraphs();
    // Считываем данные для графика
    if (!query.exec(QString("SELECT dt,v12,v13 FROM surveySHVSMIntegral WHERE surveyed_id = %1 ORDER BY dt").arg(surveyedId)))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        return;
    }
    while (query.next())
    {
        dt << query.value(0).toString();
        for (unsigned i = 0; i < 2; i++)
            y[i].push_back(query.value(i + 1).toFloat());
    }
    for (unsigned i = 0; i < 2; i++)
        for (unsigned j = 0; j < (unsigned)dt.size(); j++)
            x[i].push_back(j);


    ui->widgetPlot->xAxis->setRange(0, dt.size() - 1);
    ui->widgetPlot->yAxis->setRange(0, 100);
    ui->widgetPlot->axisRect()->setupFullAxesBox();

    grName[0] = tr("Circulatory system");
    grName[1] = tr("System of external respiration");
    ui->widgetPlot->xAxis->setTickVectorLabels(dt);

    for (unsigned i = 0; i < 2; i++)
        if (isGraph[i])
        {
            ui->widgetPlot->addGraph();
            ui->widgetPlot->graph()->setName(grName[i]);
//            ui->widgetPlot->graph(i)->setData(x[i], y[i]);
            ui->widgetPlot->graph()->setData(x[i], y[i]);
            graphPen.setColor(color[i]);
            graphPen.setWidthF(2);
//            ui->widgetPlot->graph(i)->setPen(graphPen);
            ui->widgetPlot->graph()->setPen(graphPen);
        }
    ui->widgetPlot->replot();
}

void ArchiveSurveyedSHVSMIntegralDialog::selectionChanged()
{

  // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (ui->widgetPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->widgetPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      ui->widgetPlot->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->widgetPlot->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
  {
    ui->widgetPlot->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    ui->widgetPlot->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }
  // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
  if (ui->widgetPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->widgetPlot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
      ui->widgetPlot->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->widgetPlot->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
  {
    ui->widgetPlot->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    ui->widgetPlot->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
  }

  // synchronize selection of graphs with selection of corresponding legend items:
  for (int i=0; i<ui->widgetPlot->graphCount(); ++i)
  {
    QCPGraph *graph = ui->widgetPlot->graph(i);
    QCPPlottableLegendItem *item = ui->widgetPlot->legend->itemWithPlottable(graph);
    if (item->selected() || graph->selected())
    {
      item->setSelected(true);
      graph->setSelected(true);
    }
  }
}

void ArchiveSurveyedSHVSMIntegralDialog::contextMenuRequest(QPoint pos)
{
    QMenu* menu = new QMenu(this);
//    QAction* action;

    menu->setAttribute(Qt::WA_DeleteOnClose);
    if (ui->widgetPlot->legend->selectTest(pos, false) >= 0) // context menu on legend requested
    {
        menu->addAction(tr("Move to top left"), this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignLeft));
        menu->addAction(tr("Move to top center"), this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
        menu->addAction(tr("Move to top right"), this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignRight));
        menu->addAction(tr("Move to bottom right"), this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignRight));
        menu->addAction(tr("Move to bottom left"), this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
    }
    else  // general context menu on graphs requested
    {

        menu->addAction(tr("Circulatory system"),this, SLOT(shovGraph1()));
        menu->actions()[0]->setCheckable(true);
        menu->actions()[0]->setChecked(isGraph[0]);

        menu->addAction(tr("System of external respiration"),this, SLOT(shovGraph2()));
        menu->actions()[1]->setCheckable(true);
        menu->actions()[1]->setChecked(isGraph[1]);

        menu->addSeparator();

        menu->addAction(tr("Show legend"),this, SLOT(shovLegend()));
        menu->actions()[3]->setCheckable(true);
        menu->actions()[3]->setChecked(isLegend);
    }

    menu->popup(ui->widgetPlot->mapToGlobal(pos));
}

void ArchiveSurveyedSHVSMIntegralDialog::moveLegend(void)
{
    bool ok;
    int dataInt;

    if (QAction* contextAction = qobject_cast<QAction*>(sender())) // make sure this slot is really called by a context menu action, so it carries the data we need
    {
        dataInt = contextAction->data().toInt(&ok);
        if (ok)
        {
            ui->widgetPlot->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment)dataInt);
            ui->widgetPlot->replot();
        }
    }
}

void ArchiveSurveyedSHVSMIntegralDialog::shovGraph1(void)
{
    isGraph[0] = !isGraph[0];
    rePlot();
}

void ArchiveSurveyedSHVSMIntegralDialog::shovGraph2(void)
{
    isGraph[1] = !isGraph[1];
    rePlot();
}

void ArchiveSurveyedSHVSMIntegralDialog::shovLegend(void)
{
    isLegend = !isLegend;
    rePlot();
}
