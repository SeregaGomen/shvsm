#include <QSqlQueryModel>
#include <QPainter>
#include "archiveteamshvsmdialog.h"
#include "ui_archiveteamshvsmdialog.h"

ArchiveTeamSHVSMDialog::ArchiveTeamSHVSMDialog(QSqlDatabase* pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveTeamSHVSMDialog)
{
    ui->setupUi(this);
    db = pdb;
    setupForm();
}

ArchiveTeamSHVSMDialog::~ArchiveTeamSHVSMDialog()
{
    delete ui;
    delete modelTeam;
    delete modelDate;
    delete modelSurveyed;
}

void ArchiveTeamSHVSMDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}


void ArchiveTeamSHVSMDialog::setupForm(void)
{

    // Список обследуемых команд
    modelTeam = new QSqlQueryModel(this);
    modelTeam->setQuery("SELECT * FROM team");
    modelTeam->setHeaderData(1, Qt::Horizontal, tr("Team"));
    ui->twTeam->setModel(modelTeam);
    ui->twTeam->setColumnHidden(0, true);
    ui->twTeam->horizontalHeader()->setResizeMode(1,QHeaderView::Stretch);
    ui->twTeam->verticalHeader()->setDefaultSectionSize(ui->twTeam->verticalHeader()->minimumSectionSize());
    ui->twTeam->setCurrentIndex(ui->twTeam->model()->index(0, 0));


    // Список дат обследования
    team_id = ui->twTeam->model()->data(ui->twTeam->model()->index(ui->twTeam->selectionModel()->currentIndex().row(),0)).toInt();
    modelDate = new QSqlQueryModel(this);
    modelDate->setQuery(QString("SELECT surveyed_id, dt FROM surveySHVSM, surveyed, team WHERE surveyed_id = surveyed.id AND surveyed.team_id = %1 GROUP BY dt").arg(team_id));
    modelDate->setHeaderData(1, Qt::Horizontal, tr("Date"));
    ui->twDate->setModel(modelDate);
    ui->twDate->setColumnHidden(0, true);
    ui->twDate->horizontalHeader()->setResizeMode(1,QHeaderView::Stretch);
    ui->twDate->verticalHeader()->setDefaultSectionSize(ui->twDate->verticalHeader()->minimumSectionSize());
    ui->twDate->setCurrentIndex(ui->twDate->model()->index(0, 0));

    // Список обследованных в команде на заданную дату
    dt = ui->twDate->model()->data(ui->twDate->model()->index(ui->twDate->selectionModel()->currentIndex().row(),1)).toString();
    modelSurveyed = new QSqlQueryModel(this);
    modelSurveyed->setQuery(QString("SELECT surveyed.name,sex.name,qualification.name,old,weight,growth,N1,N2,n_1,n_2,HR1,HR2,aPWC170,oPWC170,aMPK,oMPK,ALAKm,ALAKe,LAKm,LAKe, \
                                            PANO,CHSSpano,OME,TE,SE,SPE,SPS,RP,UFP  \
                                     FROM surveySHVSM,surveyed,sex,qualification \
                                     WHERE surveySHVSM.surveyed_id = surveyed.id AND surveyed.team_id = %1 AND dt = \"%2\" AND surveyed.sex_id = sex.id AND \
                                     surveyed.qualification_id = qualification.id \
                                     ORDER BY dt").arg(team_id).arg(dt));
    modelSurveyed->setHeaderData(0, Qt::Horizontal, tr("Name"));
    modelSurveyed->setHeaderData(1, Qt::Horizontal, tr("Sex"));
    modelSurveyed->setHeaderData(2, Qt::Horizontal, tr("Qualification"));
    modelSurveyed->setHeaderData(3, Qt::Horizontal, tr("Old"));
    modelSurveyed->setHeaderData(4, Qt::Horizontal, tr("Weight"));
    modelSurveyed->setHeaderData(5, Qt::Horizontal, tr("Height"));
    modelSurveyed->setHeaderData(6, Qt::Horizontal, tr("N1"));
    modelSurveyed->setHeaderData(7, Qt::Horizontal, tr("N2"));
    modelSurveyed->setHeaderData(8, Qt::Horizontal, tr("n1"));
    modelSurveyed->setHeaderData(9, Qt::Horizontal, tr("n2"));
    modelSurveyed->setHeaderData(10, Qt::Horizontal, tr("HR1"));
    modelSurveyed->setHeaderData(11, Qt::Horizontal, tr("HR2"));

    modelSurveyed->setHeaderData(12, Qt::Horizontal, tr("aPWC170"));
    modelSurveyed->setHeaderData(13, Qt::Horizontal, tr("oPWC170"));
    modelSurveyed->setHeaderData(14, Qt::Horizontal, tr("aMPK"));
    modelSurveyed->setHeaderData(15, Qt::Horizontal, tr("oMPK"));
    modelSurveyed->setHeaderData(16, Qt::Horizontal, tr("ALAKm"));
    modelSurveyed->setHeaderData(17, Qt::Horizontal, tr("ALAKe"));
    modelSurveyed->setHeaderData(18, Qt::Horizontal, tr("LAKm"));
    modelSurveyed->setHeaderData(19, Qt::Horizontal, tr("LAKe"));
    modelSurveyed->setHeaderData(20, Qt::Horizontal, tr("PANO"));
    modelSurveyed->setHeaderData(21, Qt::Horizontal, tr("CHSSpano"));
    modelSurveyed->setHeaderData(22, Qt::Horizontal, tr("OME"));
    modelSurveyed->setHeaderData(23, Qt::Horizontal, tr("TE"));
    modelSurveyed->setHeaderData(24, Qt::Horizontal, tr("SE"));
    modelSurveyed->setHeaderData(25, Qt::Horizontal, tr("SPE"));
    modelSurveyed->setHeaderData(26, Qt::Horizontal, tr("SPS"));
    modelSurveyed->setHeaderData(27, Qt::Horizontal, tr("RP"));
    modelSurveyed->setHeaderData(28, Qt::Horizontal, tr("UFP"));



    ui->twSurveyed->setModel(modelSurveyed);
//    ui->twSurveyed->horizontalHeader()->setDefaultSectionSize(ui->twSurveyed->horizontalHeader()->minimumSectionSize());
    ui->twSurveyed->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());

    ui->twSurveyed->horizontalHeader()->resizeSection(0, 170);
    ui->twSurveyed->horizontalHeader()->resizeSection(2, 100);
    ui->twSurveyed->horizontalHeader()->resizeSection(3, 75);
    ui->twSurveyed->horizontalHeader()->resizeSection(4, 65);
    ui->twSurveyed->horizontalHeader()->resizeSection(5, 65);

    for (int i = 12; i < 29; i++)
        ui->twSurveyed->setColumnHidden(i, true);

    ui->twSurveyed->resizeColumnsToContents();
    ui->twSurveyed->setCurrentIndex(ui->twSurveyed->model()->index(0, 0));

    // ------------------------------------------------
    ui->twSurveyedOutput1->setModel(modelSurveyed);
    ui->twSurveyedOutput1->horizontalHeader()->setDefaultSectionSize(ui->twSurveyed->horizontalHeader()->minimumSectionSize());
    ui->twSurveyedOutput1->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());
    for (int i = 0; i < 12; i++)
        ui->twSurveyedOutput1->setColumnHidden(i, true);
    for (int i = 23; i < 29; i++)
        ui->twSurveyedOutput1->setColumnHidden(i, true);

    for (int i = 12; i < 23; i++)
        ui->twSurveyedOutput1->horizontalHeader()->resizeSection(i, 60);

    ui->twSurveyedOutput1->setCurrentIndex(ui->twSurveyedOutput1->model()->index(0, 0));

//    ui->twSurveyedOutput1->horizontalHeader()->setResizeMode(13,QHeaderView::ResizeToContents);
    ///////////////
    ui->twSurveyedOutput1->setItemDelegate(new ColorDelegateSHVSM(this,this));
    ///

    // -------------------------------------------------------
    ui->twSurveyedOutput2->setModel(modelSurveyed);
    ui->twSurveyedOutput2->horizontalHeader()->setDefaultSectionSize(ui->twSurveyed->horizontalHeader()->minimumSectionSize());
    ui->twSurveyedOutput2->verticalHeader()->setDefaultSectionSize(ui->twSurveyed->verticalHeader()->minimumSectionSize());
    for (int i = 0; i < 23; i++)
        ui->twSurveyedOutput2->setColumnHidden(i, true);

    for (int i = 23; i < 29; i++)
        ui->twSurveyedOutput2->horizontalHeader()->resizeSection(i, 60);

    ui->twSurveyedOutput2->setCurrentIndex(ui->twSurveyedOutput2->model()->index(0, 0));

    ///////////////
    ui->twSurveyedOutput2->setItemDelegate(new ColorDelegateSHVSM(this,this));
    ///

    connect(ui->twTeam->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedTeam(const QItemSelection&, const QItemSelection&)));
    connect(ui->twSurveyed->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&)));
    connect(ui->twDate->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), this, SLOT(slotSelectionChangedDate(const QItemSelection&, const QItemSelection&)));
}

void ArchiveTeamSHVSMDialog::slotSelectionChangedTeam(const QItemSelection&, const QItemSelection&)
{
    team_id = ui->twTeam->model()->data(ui->twTeam->model()->index(ui->twTeam->selectionModel()->currentIndex().row(),0)).toInt();
    modelDate->setQuery(QString("SELECT surveyed_id, dt FROM surveySHVSMIntegral, surveyed, team WHERE surveyed_id = surveyed.id AND surveyed.team_id = %1 GROUP BY dt").arg(team_id));
    ui->twDate->setCurrentIndex(ui->twDate->model()->index(0, 0));
}

void ArchiveTeamSHVSMDialog::slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&)
{
    ui->twSurveyedOutput1->setCurrentIndex(ui->twSurveyedOutput2->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),0));
    ui->twSurveyedOutput2->setCurrentIndex(ui->twSurveyedOutput2->model()->index(ui->twSurveyed->selectionModel()->currentIndex().row(),0));
}

void ArchiveTeamSHVSMDialog::slotSelectionChangedDate(const QItemSelection&, const QItemSelection&)
{
    dt = ui->twDate->model()->data(ui->twDate->model()->index(ui->twDate->selectionModel()->currentIndex().row(),1)).toString();
    modelSurveyed->setQuery(QString("SELECT surveyed.name,sex.name,qualification.name,old,weight,growth,HR,SAD,DAD,T1,T2,VL,VLN,VLD,V1,V2,V3,V4,V5,V6,V7,V8,V9,V10,V11,V12,V13 \
                                     FROM surveySHVSMIntegral,surveyed,sex,qualification \
                                     WHERE surveySHVSMIntegral.surveyed_id = surveyed.id AND surveyed.team_id = %1 AND dt = \"%2\" AND surveyed.sex_id = sex.id AND \
                                     surveyed.qualification_id = qualification.id \
                                     ORDER BY dt").arg(team_id).arg(dt));
    ui->twSurveyed->setCurrentIndex(ui->twSurveyed->model()->index(0, 0));
}

void ColorDelegateSHVSM::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    float val = 0;

    if (qVariantCanConvert<float>(index.data()))
        val = qVariantValue<float>(index.data());
    if ((index.column() == 25 || index.column() == 26) && val)
        painter->fillRect(option.rect, ptr->getIndicatorColor(val,33.0,49.6,66.1,82.6));
    QItemDelegate::paint(painter,option,index);
}

QColor ArchiveTeamSHVSMDialog::getIndicatorColor(float indicator,float val1, float val2,float val3, float val4)
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
