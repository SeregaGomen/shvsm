#include <QSqlQueryModel>
#include <QMessageBox>
#include <QPainter>
#include <QScrollBar>
#include <QSqlQuery>
#include "archivesurveyedshvsmdialog.h"
#include "ui_archivesurveyedshvsmdialog.h"

ArchiveSurveyedSHVSMDialog::ArchiveSurveyedSHVSMDialog(QSqlDatabase* pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveSurveyedSHVSMDialog)
{
    ui->setupUi(this);
    db = pdb;
    setupForm();
}

ArchiveSurveyedSHVSMDialog::~ArchiveSurveyedSHVSMDialog()
{
    delete ui;
    delete modelSurveyed;
    delete modelSurvey;
}

void ArchiveSurveyedSHVSMDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}


void ArchiveSurveyedSHVSMDialog::setupForm(void)
{
    // Список обследованных
    modelSurveyed = new QSqlQueryModel(this);
    modelSurveyed->setQuery(QString("SELECT surveyed.id,surveyed.name,sex.name FROM surveyed, sex WHERE surveyed.sex_id = sex.id ORDER BY surveyed.name"));
    modelSurveyed->setHeaderData(1, Qt::Horizontal, tr("Name"));
    modelSurveyed->setHeaderData(2, Qt::Horizontal, tr("Sex"));

    ui->twSurveyed->setModel(modelSurveyed);
    ui->twSurveyed->setColumnHidden(0, true);
    ui->twSurveyed->resizeColumnsToContents();
    ui->twSurveyed->setCurrentIndex(ui->twSurveyed->model()->index(0, 0));

    // Обследование 'ШВСМ'
    surveyedId = ui->twSurveyed->model()->data(ui->twSurveyed->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),0)).toInt();

    modelSurvey = new QSqlQueryModel(this);
    modelSurvey->setQuery(QString("SELECT dt,qualification.name,old,weight,growth,N1,N2,n_1,n_2,HR1,HR2,aPWC170,oPWC170,aMPK,oMPK,ALAKm,ALAKe,LAKm,LAKe,PANO,CHSSpano,OME,TE,SE,SPE,SPS,RP,UFP \
                                   FROM surveySHVSM,surveyed,qualification \
                                   WHERE surveySHVSM.surveyed_id = surveyed.id AND surveyed.qualification_id = qualification.id AND surveyed.id = %1\
                                   ORDER BY dt").arg(surveyedId));
    modelSurvey->setHeaderData(0, Qt::Horizontal, tr("Date"));
    modelSurvey->setHeaderData(1, Qt::Horizontal, tr("Qualification"));
    modelSurvey->setHeaderData(2, Qt::Horizontal, tr("Old"));
    modelSurvey->setHeaderData(3, Qt::Horizontal, tr("Weight"));
    modelSurvey->setHeaderData(4, Qt::Horizontal, tr("Growth"));
    modelSurvey->setHeaderData(5, Qt::Horizontal, tr("N1"));
    modelSurvey->setHeaderData(6, Qt::Horizontal, tr("N2"));
    modelSurvey->setHeaderData(7, Qt::Horizontal, tr("n1"));
    modelSurvey->setHeaderData(8, Qt::Horizontal, tr("n2"));
    modelSurvey->setHeaderData(9, Qt::Horizontal, tr("HR1"));
    modelSurvey->setHeaderData(10, Qt::Horizontal, tr("HR2"));

    modelSurvey->setHeaderData(11, Qt::Horizontal, tr("aPWC170"));
    modelSurvey->setHeaderData(12, Qt::Horizontal, tr("oPWC170"));
    modelSurvey->setHeaderData(13, Qt::Horizontal, tr("aMPK"));
    modelSurvey->setHeaderData(14, Qt::Horizontal, tr("oMPK"));
    modelSurvey->setHeaderData(15, Qt::Horizontal, tr("ALAKm"));
    modelSurvey->setHeaderData(16, Qt::Horizontal, tr("ALAKe"));
    modelSurvey->setHeaderData(17, Qt::Horizontal, tr("LAKm"));
    modelSurvey->setHeaderData(18, Qt::Horizontal, tr("LAKe"));
    modelSurvey->setHeaderData(19, Qt::Horizontal, tr("PANO"));
    modelSurvey->setHeaderData(20, Qt::Horizontal, tr("CHSSpano"));
    modelSurvey->setHeaderData(21, Qt::Horizontal, tr("OME"));
    modelSurvey->setHeaderData(22, Qt::Horizontal, tr("TE"));
    modelSurvey->setHeaderData(23, Qt::Horizontal, tr("SE"));
    modelSurvey->setHeaderData(24, Qt::Horizontal, tr("SPE"));
    modelSurvey->setHeaderData(25, Qt::Horizontal, tr("SPS"));
    modelSurvey->setHeaderData(26, Qt::Horizontal, tr("RP"));
    modelSurvey->setHeaderData(27, Qt::Horizontal, tr("UFP"));


    // -------------------------------------------------------
    ui->twSurveyedOutput1->setModel(modelSurvey);
    ui->twSurveyedOutput1->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());

    for (int i = 11; i < 28; i++)
        ui->twSurveyedOutput1->setColumnHidden(i, true);

    ui->twSurveyedOutput1->resizeColumnsToContents();
    ui->twSurveyedOutput1->setCurrentIndex(ui->twSurveyedOutput1->model()->index(0, 0));

    // -------------------------------------------------------
    ui->twSurveyedOutput2->setModel(modelSurvey);
    ui->twSurveyedOutput2->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());
    for (int i = 0; i < 11; i++)
        ui->twSurveyedOutput2->setColumnHidden(i, true);
    for (int i = 22; i < 28; i++)
        ui->twSurveyedOutput2->setColumnHidden(i, true);

    ui->twSurveyedOutput2->resizeColumnsToContents();
    ui->twSurveyedOutput2->setCurrentIndex(ui->twSurveyedOutput2->model()->index(0, 0));

    ///////////////
    ui->twSurveyedOutput2->setItemDelegate(new ColorDelegateSurveyedSHVSM(this,this));
    ///

    // -------------------------------------------------------
    ui->twSurveyedOutput3->setModel(modelSurvey);
    ui->twSurveyedOutput3->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());
    for (int i = 0; i < 22; i++)
        ui->twSurveyedOutput3->setColumnHidden(i, true);

    ui->twSurveyedOutput3->resizeColumnsToContents();
    ui->twSurveyedOutput3->setCurrentIndex(ui->twSurveyedOutput3->model()->index(0, 0));

    ///////////////
    ui->twSurveyedOutput3->setItemDelegate(new ColorDelegateSurveyedSHVSM(this,this));
    ///

    connect(ui->twSurveyed->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&)));

    connect(ui->twSurveyedOutput1->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurvey1(const QItemSelection&, const QItemSelection&)));
    connect(ui->twSurveyedOutput2->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurvey2(const QItemSelection&, const QItemSelection&)));
    connect(ui->twSurveyedOutput3->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurvey3(const QItemSelection&, const QItemSelection&)));

    ui->widgetPlot->legend->setVisible(true);
    ui->widgetPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->widgetPlot->xAxis->setAutoTickLabels(false);
    ui->widgetPlot->xAxis->setAutoTicks(false);
    ui->widgetPlot->xAxis->setLabel(tr("Date"));
    ui->widgetPlot->yAxis->setLabel(tr("Point"));

    connect(ui->widgetPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));


    rePlot();
}


void ColorDelegateSurveyedSHVSM::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    float val;

    if (qVariantCanConvert<float>(index.data()))
        val = qVariantValue<float>(index.data());
    if ((index.column() == 25 || index.column() == 26) && val)
        painter->fillRect(option.rect, ptr->getIndicatorColor(val,33.0,49.6,66.1,82.6));
    QItemDelegate::paint(painter,option,index);
}

QColor ArchiveSurveyedSHVSMDialog::getIndicatorColor(float indicator,float val1, float val2,float val3, float val4)
{
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

void ArchiveSurveyedSHVSMDialog::slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&)
{
    surveyedId = ui->twSurveyed->model()->data(ui->twSurveyed->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),0)).toInt();
    modelSurvey->setQuery(QString("SELECT dt,qualification.name,old,weight,growth,N1,N2,n_1,n_2,HR1,HR2,aPWC170,oPWC170,aMPK,oMPK,ALAKm,ALAKe,LAKm,LAKe,PANO,CHSSpano,OME,TE,SE,SPE,SPS,RP,UFP \
                                   FROM surveySHVSM,surveyed,qualification \
                                   WHERE surveySHVSM.surveyed_id = surveyed.id AND surveyed.qualification_id = qualification.id AND surveyed.id = %1\
                                   ORDER BY dt").arg(surveyedId));
    ui->twSurveyedOutput1->setCurrentIndex(ui->twSurveyedOutput1->model()->index(0, 0));
    ui->twSurveyedOutput2->setCurrentIndex(ui->twSurveyedOutput2->model()->index(0, 0));
    ui->twSurveyedOutput3->setCurrentIndex(ui->twSurveyedOutput3->model()->index(0, 0));
    rePlot();
}

void ArchiveSurveyedSHVSMDialog::slotSelectionChangedSurvey1(const QItemSelection&, const QItemSelection&)
{

    currentRow = ui->twSurveyedOutput1->selectionModel()->currentIndex().row();
    scrollView();
}

void ArchiveSurveyedSHVSMDialog::slotSelectionChangedSurvey2(const QItemSelection&, const QItemSelection&)
{
    currentRow = ui->twSurveyedOutput2->selectionModel()->currentIndex().row();
    scrollView();
}

void ArchiveSurveyedSHVSMDialog::slotSelectionChangedSurvey3(const QItemSelection&, const QItemSelection&)
{
    currentRow = ui->twSurveyedOutput3->selectionModel()->currentIndex().row();
    scrollView();
}

void ArchiveSurveyedSHVSMDialog::scrollView(void)
{
    ui->twSurveyedOutput1->setCurrentIndex(ui->twSurveyedOutput1->model()->index(currentRow, 0));
    ui->twSurveyedOutput1->verticalScrollBar()->setValue(ui->twSurveyedOutput1->selectionModel()->currentIndex().row());

    ui->twSurveyedOutput2->setCurrentIndex(ui->twSurveyedOutput2->model()->index(currentRow, 0));
    ui->twSurveyedOutput2->verticalScrollBar()->setValue(ui->twSurveyedOutput2->selectionModel()->currentIndex().row());

    ui->twSurveyedOutput3->setCurrentIndex(ui->twSurveyedOutput3->model()->index(currentRow, 0));
    ui->twSurveyedOutput3->verticalScrollBar()->setValue(ui->twSurveyedOutput3->selectionModel()->currentIndex().row());
}

void ArchiveSurveyedSHVSMDialog::rePlot(void)
{
    QPen graphPen;
    QColor color[6] = { "reg", "green", "orange", "yellow", "cyan", "magenta" };
    QSqlQuery query;
    QString grName[6];
    QVector<QString> dt;
    QVector<double> x[6],
                    y[6];


    ui->widgetPlot->clearGraphs();
    // Считываем данные для графика
    if (!query.exec(QString("SELECT dt,te,se,spe,sps,rp,ufp FROM surveySHVSM WHERE surveyed_id = %1 ORDER BY dt").arg(surveyedId)))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        return;
    }
    while (query.next())
    {
        dt << query.value(0).toString();
        for (unsigned i = 0; i < 6; i++)
            y[i].push_back(query.value(i + 1).toFloat());
    }
    for (unsigned i = 0; i < 6; i++)
        for (unsigned j = 0; j < (unsigned)dt.size(); j++)
            x[i].push_back(j);


    ui->widgetPlot->xAxis->setRange(0, dt.size() - 1);
    ui->widgetPlot->yAxis->setRange(0, 100);
    ui->widgetPlot->axisRect()->setupFullAxesBox();

    grName[0] = tr("Total endurance");
    grName[1] = tr("Speed endurance");
    grName[2] = tr("Speed and power endurance");
    grName[3] = tr("Cost of power supply");
    grName[4] = tr("Reserve possibilities");
    grName[5] = tr("UFP");
    ui->widgetPlot->xAxis->setTickVectorLabels(dt);

    for (unsigned i = 0; i < 6; i++)
    {
        ui->widgetPlot->addGraph();
        ui->widgetPlot->graph()->setName(grName[i]);
        ui->widgetPlot->graph(i)->setData(x[i], y[i]);
        graphPen.setColor(color[i]);
        if (i < 5)
            graphPen.setWidthF(2);
        else
            graphPen.setWidthF(4);
        ui->widgetPlot->graph(i)->setPen(graphPen);
    }



    ui->widgetPlot->replot();
}

void ArchiveSurveyedSHVSMDialog::selectionChanged()
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
