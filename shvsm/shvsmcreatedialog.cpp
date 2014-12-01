#include <QItemSelectionModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlDatabase>
#include <math.h>
#include "shvsmcreatedialog.h"
#include "ui_shvsmcreatedialog.h"

extern void normalize(double&);

SHVSMCreateDialog::SHVSMCreateDialog(QSqlDatabase* pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SHVSMCreateDialog)
{
    ui->setupUi(this);
    db = pdb;
    setupForm();
}

SHVSMCreateDialog::~SHVSMCreateDialog()
{
    delete ui;
    delete model;
}

void SHVSMCreateDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}

void SHVSMCreateDialog::setupForm(void)
{
    QString query = "SELECT surveyed.id, surveyed.name,team.name,sex.name,qualification.name,surveyed.DOB,sex_id,qualification_id \
                     FROM surveyed, team, sex, qualification \
                     WHERE team_id = team.id AND sex_id = sex.id AND qualification_id = qualification.id";


    ui->textBrowser->hide();
    ui->pbSave->setEnabled(false);

    // Задание цвета легенды
    // "Низкий" - красный
    ui->labelLow->setStyleSheet("QLabel { background-color : red; }");
    // "Ниже среднего" - серый
    ui->labelBAverage->setStyleSheet("QLabel { background-color : gray; }");
    // "Cредний" - желтый
    ui->labelAverage->setStyleSheet("QLabel { background-color : yellow; }");
    // "Выше среднего" - бирюзовый
    ui->labelAAverage->setStyleSheet("QLabel { background-color : aqua; }");
    // "Вышсокий" - лайм
    ui->labelHigh->setStyleSheet("QLabel { background-color : lime; }");


    // Текущая дата
    ui->deDate->setDate(QDate::currentDate());

    // Список обследуемых
    model = new QSqlQueryModel(this);
    model->setQuery(query);
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Team"));
    model->setHeaderData(3, Qt::Horizontal, tr("Sex"));
    model->setHeaderData(4, Qt::Horizontal, tr("Qualification"));
    model->setHeaderData(5, Qt::Horizontal, tr("DOB"));
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(6, true);
    ui->tableView->setColumnHidden(7, true);
    ui->tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->resizeSection(2, 60);
    ui->tableView->horizontalHeader()->resizeSection(3, 60);
    ui->tableView->horizontalHeader()->resizeSection(4, 95);
    ui->tableView->horizontalHeader()->resizeSection(5, 95);
    ui->tableView->setWordWrap(true);

    ui->tableView->verticalHeader()->setDefaultSectionSize(ui->tableView->verticalHeader()->minimumSectionSize());
    ui->tableView->setCurrentIndex(ui->tableView->model()->index(0, 0));


    sex = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),6)).toInt();
    isSportsman = (ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),7)).toInt() == 1) ? true : false;
}

// Расчет параметров "ШВСМ"
void SHVSMCreateDialog::slotCalcSHVSM(void)
{
    bool isOk;
    double p_opwc170,
           p_ompk,
           p_alakm,
           p_alake,
           p_lakm,
           p_lake,
           p_pano,
           p_chsspano,
           p_ome;
    QString dob = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString();



    if (ui->leWeight->text().trimmed().isEmpty())
    {
        QMessageBox::critical(this, tr("Error"),tr("Do not set the 'Weight'!"), QMessageBox::Ok);
        ui->leWeight->setFocus();
        return;
    }
    weight = ui->leWeight->text().toFloat(&isOk);
    if (!isOk || weight <= 0)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Weight'!"), QMessageBox::Ok);
        ui->leWeight->setFocus();
        return;
    }
    if (ui->leGrowth->text().trimmed().isEmpty())
    {
        QMessageBox::critical(this, tr("Error"),tr("Do not set the 'Growth'!"), QMessageBox::Ok);
        ui->leGrowth->setFocus();
        return;
    }
    growth = ui->leGrowth->text().toFloat(&isOk);
    if (!isOk || growth <= 0)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Growth'!"), QMessageBox::Ok);
        ui->leGrowth->setFocus();
        return;
    }
    hr1 = ui->leHR1->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'HR1'!"), QMessageBox::Ok);
        ui->leHR1->setFocus();
        return;
    }
    hr2 = ui->leHR2->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'HR2'!"), QMessageBox::Ok);
        ui->leHR2->setFocus();
        return;
    }

    // Определяем возраст человека
    old = QDate::currentDate().year() - dob.right(4).toInt();
    if (old <= 0 || old > 120)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the birthday or date survey!"), QMessageBox::Ok);
        return;
    }

    if (ui->cbManual->isChecked())
    {
        // Ручной ввод параметров
        N1 = ui->leN1->text().toFloat(&isOk);
        if (!isOk)
        {
            QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'N1'!"), QMessageBox::Ok);
            ui->leN1->setFocus();
            return;
        }
        N2 = ui->leN2->text().toFloat(&isOk);
        if (!isOk)
        {
            QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'N2'!"), QMessageBox::Ok);
            ui->leN2->setFocus();
            return;
        }
        n1 = ui->len1->text().toFloat(&isOk);
        if (!isOk)
        {
            QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'n1'!"), QMessageBox::Ok);
            ui->len1->setFocus();
            return;
        }
        n2 = ui->len2->text().toFloat(&isOk);
        if (!isOk)
        {
            QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'n2'!"), QMessageBox::Ok);
            ui->len2->setFocus();
            return;
        }
    }

    apwc170 = 6.12*(N1 + (N2 - N1)*(170 - hr1)/(hr2 - hr1));
    opwc170 = apwc170/weight;

    if (isSportsman)
        ampk = 2.2*apwc170+1070;
    else
        ampk = 1.7*apwc170+1240;
    ompk = ampk/weight;

    alakm = (1.98 + 1.63*pow(N1 + (N2 - N1)*(180 - hr1)/(hr2 - hr1),1.017) + 0.018*weight + 0.008*growth - 0.005*old)/weight;
    alake = 0.73 + 5.84*pow(alakm,0.993) + 0.0009*weight + 0.0007*growth - 0.00032*old;

    lakm = (1.87 + 1.56*pow(N1 + (N2 - N1)*(160 - hr1)/(hr2 - hr1),1.015) + 0.011*weight + 0.0069*growth - 0.0035*old)/weight;
    lake = 0.91 + 5.87*pow(lakm,0.987) + 0.0008*weight + 0.00011*growth - 0.00054*old;

    panof = 100.0*pow(ompk,0.941)/(pow(ompk,0.941) + pow(lake,1.087));
    if (ompk <= 40)
        pano = panof - 20;
    else if (ompk > 40 && ompk <= 50)
        pano = panof - 10;
    else if (ompk > 50 && ompk <= 60)
        pano = panof;
    else if (ompk > 60 && ompk <= 70)
        pano = panof + 10;
    else
        pano = panof + 20;

    chsspano = pow(ompk,1.014) + pow(lake,1.012) + pano;
    ome = pano + ompk + alake + lake;

    //--------------------------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
        {
            p_opwc170  = (100.0*(1.0 - (32.0 - opwc170)/22.0));
            p_ompk = (100.0*(1.0 - (75.0 - ompk)/35.0));
            p_alakm = (100.0*(1.0 - (11.0 - alakm)/8.5));
            p_alake = (100.0*(1.0 - (60.0 - alake)/35.0));
            p_lakm = (100.0*(1.0 - (8.0 - lakm)/6.5));
            p_lake = (100.0*(1.0 - (45.0 - lake)/30.0));
            p_pano = (100.0*(1.0 - (75.0 - pano)/45.0));
            p_chsspano = (100.0*(1.0 - (180.0 - chsspano)/65.0));
            p_ome = (100.0*(1.0 - (258.0 - ome)/138.0));
        }
        else
        {
            p_opwc170  = (100.0*(1.0 - (27.0 - opwc170)/19.0));
            p_ompk = (100.0*(1.0 - (70.0 - ompk)/30.0));
            p_alakm = (100.0*(1.0 - (9.0 - alakm)/6.5));
            p_alake = (100.0*(1.0 - (50.0 - alake)/25.0));
            p_lakm = (100.0*(1.0 - (7.0 - lakm)/5.5));
            p_lake = (100.0*(1.0 - (40.0 - lake)/25.0));
            p_pano = (100.0*(1.0 - (70.0 - pano)/40.0));
            p_chsspano = (100.0*(1.0 - (175.0 - chsspano)/60.0));
            p_ome = (100.0*(1.0 - (220.0 - ome)/110.0));
        }
    }
    else
    {
        if (sex == 1)
        {
            p_opwc170  = (100.0*(1.0 - (25.0 - opwc170)/20.0));
            p_ompk = (100.0*(1.0 - (65.0 - ompk)/40.0));
            p_alakm = (100.0*(1.0 - (8.5 - alakm)/7.0));
            p_alake = (100.0*(1.0 - (50.0 - alake)/40.0));
            p_lakm = (100.0*(1.0 - (6.5 - lakm)/5.5));
            p_lake = (100.0*(1.0 - (40.0 - lake)/30.0));
            p_pano = (100.0*(1.0 - (65.0 - pano)/45.0));
            p_chsspano = (100.0*(1.0 - (160.0 - chsspano)/70.0));
            p_ome = (100.0*(1.0 - (200.0 - ome)/100.0));
        }
        else
        {
            p_opwc170 = (100.0*(1.0 - (20.0 - opwc170)/16.0));
            p_ompk = (100.0*(1.0 - (60.0 - ompk)/40.0));
            p_alakm = (100.0*(1.0 - (6.5 - alakm)/5.0));
            p_alake = (100.0*(1.0 - (40.0 - alake)/30.0));
            p_lakm = (100.0*(1.0 - (6.0 - lakm)/5.0));
            p_lake = (100.0*(1.0 - (30.0 - lake)/20.0));
            p_pano = (100.0*(1.0 - (55.0 - pano)/40.0));
            p_chsspano = (100.0*(1.0 - (150.0 - chsspano)/70.0));
            p_ome = (100.0*(1.0 - (190.0 - ome)/110.0));
        }
    }

    normalize(p_opwc170);
    normalize(p_ompk);
    normalize(p_alakm);
    normalize(p_alake);
    normalize(p_lakm);
    normalize(p_lake);
    normalize(p_pano);
    normalize(p_chsspano);
    normalize(p_ome);

    ufp = ((p_opwc170 + p_ompk + p_alakm + p_alake + p_lakm + p_lake + p_pano + p_chsspano + p_ome)/9.0);


    //--------------------------------------------------------

    ui->leN1->setText(QString("%1").arg(N1,0,'f',2));
    ui->leN2->setText(QString("%1").arg(N2,0,'f',2));
    ui->len1->setText(QString("%1").arg(n1,0,'f',2));
    ui->len2->setText(QString("%1").arg(n2,0,'f',2));
    ui->labelaPWC170->setText(QString("%1").arg(apwc170,0,'f',2));
    ui->labeloPWC170->setText(QString("%1").arg(opwc170,0,'f',2));
    ui->labelaMPK->setText(QString("%1").arg(ampk,0,'f',2));
    ui->labeloMPK->setText(QString("%1").arg(ompk,0,'f',2));
    ui->labelALAKm->setText(QString("%1").arg(alakm,0,'f',2));
    ui->labelALAKe->setText(QString("%1").arg(alake,0,'f',2));
    ui->labelLAKm->setText(QString("%1").arg(lakm,0,'f',2));
    ui->labelLAKe->setText(QString("%1").arg(lake,0,'f',2));
    ui->labelPANO->setText(QString("%1").arg(pano,0,'f',2));
    ui->labelCHSSpano->setText(QString("%1").arg(chsspano,0,'f',2));
    ui->labelOME->setText(QString("%1").arg(ome,0,'f',2));

    // ---------------------------------- oPWC170 ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labeloPWC170,opwc170,15.25,18.49,25.00,28.25);
        else
            showIndicator(ui->labeloPWC170,opwc170,12.00,15.50,22.51,26.00);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labeloPWC170,opwc170,9.75,12.50,18.00,20.75);
        else
            showIndicator(ui->labeloPWC170,opwc170,7.00,9.49,14.50,17.00);
    }
    // ---------------------------------- oMPK ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labeloMPK,ompk,50,55,65,70);
        else
            showIndicator(ui->labeloMPK,ompk,40,44.99,55,60);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labeloMPK,ompk,40,44.99,55,60);
        else
            showIndicator(ui->labeloMPK,ompk,27.5,34.99,55,60);
    }
    // ---------------------------------- ALAKm ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labelALAKm,alakm,3.91,5.32,8.17,9.69);
        else
            showIndicator(ui->labelALAKm,alakm,3.59,4.66,6.83,7.91);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labelALAKm,alakm,2.41,3.57,5.92,7.09);
        else
            showIndicator(ui->labelALAKm,alakm,2.34,3.16,4.83,5.66);
    }
    // ---------------------------------- ALAKe ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labelALAKe,alake,32,37.99,50,56);
        else
            showIndicator(ui->labelALAKe,alake,29.5,32.99,40,43.5);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labelALAKe,alake,20.00,24.99,35,40);
        else
            showIndicator(ui->labelALAKe,alake,15.00,19.99,30,35);
    }
    // ---------------------------------- LAKm ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labelLAKm,alakm,2.59,3.66,5.83,6.91);
        else
            showIndicator(ui->labelLAKm,alakm,2.41,3.32,5.17,6.09);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labelLAKm,alakm,1.91,2.82,4.67,5.59);
        else
            showIndicator(ui->labelLAKm,alakm,1.84,2.66,4.33,5.16);
    }
    // ---------------------------------- LAKe ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labelLAKe,alake,25.00,29.99,40.00,45.00);
        else
            showIndicator(ui->labelLAKe,alake,20.00,24.99,35.00,40.00);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labelLAKe,alake,15.00,19.99,30.00,35.00);
        else
            showIndicator(ui->labelLAKe,alake,10.00,14.99,25.00,30.00);
    }
    // ---------------------------------- PANO ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labelPANO,pano,47.50,54.99,70.00,77.50);
        else
            showIndicator(ui->labelPANO,pano,37.50,44.99,60.00,67.50);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labelPANO,pano,40.00,44.99,55.00,60.00);
        else
            showIndicator(ui->labelPANO,pano,35.00,39.99,50.00,55.00);
    }
    // ---------------------------------- CHSSpano ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labelCHSSpano,chsspano,147,154,170,178);
        else
            showIndicator(ui->labelCHSSpano,chsspano,142,149,165,173);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labelCHSSpano,chsspano,85,109,160,173);
        else
            showIndicator(ui->labelCHSSpano,chsspano,85,109,150,170);
    }
    // ---------------------------------- OME ------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            showIndicator(ui->labelOME,ome,150,169.99,210,230);
        else
            showIndicator(ui->labelOME,ome,142.5,159.99,195,212.5);
    }
    else
    {
        if (sex == 1)
            showIndicator(ui->labelOME,ome,125,139.99,170,185);
        else
            showIndicator(ui->labelOME,ome,115,129.99,160,175);
    }


    showIndicatorTxt(ui->labelV1,ui->labelF1,0.5*(p_opwc170 + p_ompk));
    showIndicatorTxt(ui->labelV2,ui->labelF2,0.5*(p_alakm + p_alake));
    showIndicatorTxt(ui->labelV3,ui->labelF3,0.5*(p_lakm + p_lake));
    showIndicatorTxt(ui->labelV4,ui->labelF4,0.5*(p_pano + p_chsspano));
    showIndicatorTxt(ui->labelV5,ui->labelF5,p_ome);
    showIndicatorTxt(ui->labelV6,ui->labelF6,ufp);


    ui->textBrowser->show();
    ui->pbSave->setEnabled(true);
}

void SHVSMCreateDialog::slotSaveSHVSM(void)
{
    QSqlQuery query;
    QString dt = ui->deDate->text();
    int surveyed_id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();

    // Проверяем, есть ли уже такая запись
    if (!query.exec(QString("SELECT * FROM surveySHVSM WHERE surveyed_id = %1 AND dt = '%2'").arg(surveyed_id).arg(dt)))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        return;
    }
    if (query.next())
    {
        // Такая запись уже есть, перезаписываем ее
        if (!query.exec(QString("UPDATE surveySHVSM SET weight=%3,growth=%4,N1=%5,N2=%6,n_1=%7,n_2=%8,HR1=%9,HR2=%10,aPWC170=%11,oPWC170=%12,aMPK=%13,oMPK=%14,ALAKm=%15,ALAKe=%16,LAKm=%17,\
                                 LAKe=%18,PANO=%19,CHSSpano=%20,OME=%21,TE=%22,SE=%23,SPE=%24,SPS=%25,RP=%26,UFP=%27,old=%28 \
                                 WHERE surveyed_id = %1 AND dt = '%2'").arg(surveyed_id).arg(dt).arg(weight).arg(growth).arg(N1).arg(N2).arg(n1).arg(n2).arg(hr1).arg(hr2).\
                                 arg(apwc170).arg(opwc170).arg(ampk).arg(ompk).arg(alakm).arg(alake).arg(lakm).arg(lake).arg(pano).arg(chsspano).\
                                 arg(ome).arg(0.5*(opwc170 + ompk)).arg(0.5*(alakm + alake)).arg(0.5*(lakm + lake)).arg(0.5*(pano + chsspano)).arg(ome).arg(ufp).arg(old)))
            QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);

        return;
    }


    if (!query.exec(QString("INSERT INTO surveySHVSM (surveyed_id,dt,weight,growth,N1,N2,n_1,n_2,HR1,HR2,aPWC170,oPWC170,aMPK,oMPK,ALAKm,ALAKe,LAKm,LAKe,PANO,CHSSpano,OME,TE,SE,SPE,SPS,RP,UFP,old) \
                             VALUES (%1,'%2',%3,%4,%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,%19,%20,%21,%22,%23,%24,%25,%26,%27,%28)").arg(surveyed_id).arg(dt).arg(weight).arg(growth).\
                             arg(N1).arg(N2).arg(n1).arg(n2).arg(hr1).arg(hr2).arg(apwc170).arg(opwc170).arg(ampk).arg(ompk).arg(alakm).arg(alake).arg(lakm).arg(lake).arg(pano).arg(chsspano).\
                             arg(ome).arg(0.5*(opwc170 + ompk)).arg(0.5*(alakm + alake)).arg(0.5*(lakm + lake)).arg(0.5*(pano + chsspano)).arg(ome).arg(ufp).arg(old)))
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
}

void SHVSMCreateDialog::showIndicator(QLabel* label, float indicator,float val1,float val2, float val3, float val4)
{
    if (indicator < val1)
        label->setStyleSheet("QLabel { background-color : red; }");
    else if (indicator >= val1 && indicator <= val2)
        label->setStyleSheet("QLabel { background-color : gray; }");
    else if (indicator > val2 && indicator <= val3)
        label->setStyleSheet("QLabel { background-color : yellow; }");
    else if (indicator > val3 && indicator <= val4)
        label->setStyleSheet("QLabel { background-color : aqua; }");
    else
        label->setStyleSheet("QLabel { background-color : lime; }");
}

void SHVSMCreateDialog::showIndicatorTxt(QLabel* labelF, QLabel* labelT,float indicator)
{
    if (indicator < 0)
        indicator = 0;
    else if (indicator > 100)
        indicator = 100;

    labelF->setText(QString("%1").arg(indicator));
    if (indicator <= 33.1)
    {
        labelF->setStyleSheet("QLabel { background-color : red; }");
        labelT->setText(tr("Low"));
        labelT->setStyleSheet("QLabel { background-color : red; }");
    }
    else if (indicator > 33.1 && indicator <= 49.6)
    {
        labelF->setStyleSheet("QLabel { background-color : gray; }");
        labelT->setText(tr("Below the average"));
        labelT->setStyleSheet("QLabel { background-color : gray; }");
    }
    else if (indicator > 49.6 && indicator <= 66.1)
    {
        labelF->setStyleSheet("QLabel { background-color : yellow; }");
        labelT->setText(tr("Average"));
        labelT->setStyleSheet("QLabel { background-color : yellow; }");
    }
    else if (indicator > 66.1 && indicator <= 82.6)
    {
        labelF->setStyleSheet("QLabel { background-color : aqua; }");
        labelT->setText(tr("Above average"));
        labelT->setStyleSheet("QLabel { background-color : aqua; }");
    }
    else
    {
        labelF->setStyleSheet("QLabel { background-color : lime; }");
        labelT->setText(tr("High"));
        labelT->setStyleSheet("QLabel { background-color : lime; }");
    }
}


void SHVSMCreateDialog::slotCheckBoxClicked(void)
{
    ui->leN1->setEnabled(ui->cbManual->isChecked());
    ui->leN2->setEnabled(ui->cbManual->isChecked());
    ui->len1->setEnabled(ui->cbManual->isChecked());
    ui->len2->setEnabled(ui->cbManual->isChecked());
}

void SHVSMCreateDialog::slotTextChanged(void)
{
    bool isOk;

    if (ui->cbManual->isChecked())
        return;
    growth =  ui->leGrowth->text().toDouble(&isOk);
    if (!isOk)
    {
        ui->leN1->setText("");
        ui->leN2->setText("");
        ui->len1->setText("");
        ui->len2->setText("");
        return;
    }
    weight =  ui->leWeight->text().toDouble(&isOk);
    if (!isOk)
    {
        ui->leN1->setText("");
        ui->leN2->setText("");
        ui->len1->setText("");
        ui->len2->setText("");
        return;
    }
    calcNn12();
}

void SHVSMCreateDialog::calcNn12(void)
{
    if (weight <= 59)
        N1 = 50;
    else if (weight >= 60 && weight <= 64)
        N1 = 67;
    else if (weight >= 65 && weight <= 69)
        N1 = 83;
    else if (weight >= 70 && weight <= 74)
        N1 = 100;
    else if (weight >= 75 && weight <= 79)
        N1 = 117;
    else
        N1 = 133;

    if (sex == 1) // M
        n1 = int(((N1*6.12)/(1.33*0.4*weight)));
    else
        n1 = int(((N1*6.12)/(1.33*0.2*weight)));

    if (isSportsman)
    {
        N2 = int((N1 + 0.75*N1));
        n2 = int(n1 + n1*0.75);
    }
    else
    {
        N2 = int((N1 + 0.5*N1));
        n2 = int(n1 + n1*0.5);
    }
    ui->leN1->setText(QString("%1").arg(N1));
    ui->leN2->setText(QString("%1").arg(N2));
    ui->len1->setText(QString("%1").arg(n1));
    ui->len2->setText(QString("%1").arg(n2));
}

