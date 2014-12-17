#include <QPalette>
#include <QItemSelectionModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlDatabase>
#include <math.h>
#include "shvsmcreatedialog.h"
#include "printreportdialog.h"
#include "ui_shvsmcreatedialog.h"

extern float normalize(float);

void getOME(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 150,169.99,210,230 },
                      { 137.50,154.99,190,207.5 }},
          m[][4]   = {{ 125,139.99,170,185 },
                      { 127.5,144.99,180,197.5 }},
          w_s[][4] = {{ 142.5,159.99,195,212.5 },
                      { 127.5,144.99,180,197.5 }},
          w[][4] =   {{ 115,129.99,160,175 },
                      { 107.50,124.99,160,177.50 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}

void getCHSSpano(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 147,154,170,178 },
                      { 138,144,160,169 }},
          m[][4]   = {{ 85,109,160,173 },
                      { 117,124,150,159 }},
          w_s[][4] = {{ 142,149,165,173 },
                      { 132,139,155,163 }},
          w[][4] =   {{ 85,109,150,170 },
                      { 110,119,140,151 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}

void getPANO(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 47.50,54.99,70.00,77.50 },
                      { 42.00,50.00,65.00,72.50 }},
          m[][4]   = {{ 40.00,44.99,55.00,60.00 },
                      { 40.00,45.00,55.00,60.00 }},
          w_s[][4] = {{ 37.50,44.99,60.00,67.50 },
                      { 37.50,45.0,60.00,67.50 }},
          w[][4] =   {{ 35.00,39.99,50.00,55.00 },
                      { 35.00,40.00,50.00,55.00 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}


void getLAKe(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 25.00,29.99,40.00,45.00 },
                      { 17.00,22.00,32.00,37.00 }},
          m[][4]   = {{ 15.00,19.99,30.00,35.00 },
                      { 13.00,18.00,28.00,33.00 }},
          w_s[][4] = {{ 20.00,24.99,35.00,40.00 },
                      { 15.00,20.00,30.00,35.00 }},
          w[][4] =   {{ 10.00,14.99,25.00,30.00 },
                      { 10.00,15.00,25.00,30.00 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}

void getLAKm(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 2.59,3.66,5.83,6.91 },
                      { 2.22,3.13,4.98,5.91 }},
          m[][4]   = {{ 1.91,2.82,4.67,5.59 },
                      { 1.41,2.3,4.11,5.01 }},
          w_s[][4] = {{ 2.41,3.32,5.17,6.09 },
                      { 2.20,2.87,4.24,4.93 }},
          w[][4] =   {{ 1.84,2.66,4.33,5.16 },
                      { 1.35,2.14,3.74,4.54 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}

void getALAKe(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 32,37.99,50,56 },
                      { 29.50,33,40,43.50 }},
          m[][4]   = {{ 20.00,24.99,35,40 },
                      { 15.00,20,30,35 }},
          w_s[][4] = {{ 29.5,32.99,40,43.5 },
                      { 27.5,30,35,37.5 }},
          w[][4] =   {{ 15.00,19.99,30,35 },
                      { 10.00,15.00,25,30 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}

void getALAKm(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 3.91,5.32,8.17,9.69 },
                      { 3.49,4.51,6.59,7.74 }},
          m[][4]   = {{ 2.41,3.57,5.92,7.09 },
                      { 2.02,3.06,5.17,6.22 }},
          w_s[][4] = {{ 3.59,4.66,6.83,7.91 },
                      { 3.49,4.51,6.59,7.74 }},
          w[][4] =   {{ 2.34,3.16,4.83,5.66 },
                      { 1.85,2.67,4.33,5.16 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}


void getoPWC170(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 15.25,18.49,25.00,28.25 },
                      { 14.00,16.00,20.00,22.00 }},
          m[][4]   = {{ 9.75,12.50,18.00,20.75 },
                      { 10.00,12.00,16.00,18.00 }},
          w_s[][4] = {{ 12.00,15.50,22.51,26.00 },
                      { 12.00,14.00,18.00,20.00 }},
          w[][4] =   {{ 7.00,9.49,14.50,17.00 },
                      { 8.00,10.00,14.00,16.00 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}

void getoMPK(int sex, int age, bool isSportsman, float& val1, float& val2, float& val3, float& val4)
{
    int index = (age < 18) ? 0 : 1;
    float m_s[][4] = {{ 50,55,65,70 },
                      { 40,45,55,60 }},
          m[][4]   = {{ 40,44.99,55,60 },
                      { 35,40,50,55 }},
          w_s[][4] = {{ 40,44.99,55,60 },
                      { 35,40.00,50,55}},
          w[][4] =   {{ 27.5,34.99,55,60 },
                      { 32.5,35,45,47.5 }},
          (*arr)[4];

    if (isSportsman)
    {
        if (sex == 1)
            arr = m_s;
        else
            arr = w_s;
    }
    else
    {
        if (sex == 1)
            arr = m;
        else
            arr = w;
    }
    val1 = arr[index][0];
    val2 = arr[index][1];
    val3 = arr[index][2];
    val4 = arr[index][3];
}


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
    QString query = "SELECT surveyed.id, surveyed.name,team.name, sex.name, qualification.name,surveyed.DOB,sex_id,qualification_id \
                     FROM surveyed \
                     LEFT OUTER JOIN team ON surveyed.team_id = team.id \
                     LEFT OUTER JOIN sex ON surveyed.sex_id = sex.id \
                     LEFT OUTER JOIN qualification ON surveyed.qualification_id = qualification.id";


    ui->pbSave->setEnabled(false);
    ui->pbPrint->setEnabled(false);
    ui->pbHint->setEnabled(false);

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
    model->setHeaderData(4, Qt::Horizontal, tr("Status"));
    model->setHeaderData(5, Qt::Horizontal, tr("DoB"));
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
    float val1,
          val2,
          val3,
          val4;
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
        QMessageBox::critical(this, tr("Error"),tr("Do not set the 'Height'!"), QMessageBox::Ok);
        ui->leGrowth->setFocus();
        return;
    }
    growth = ui->leGrowth->text().toFloat(&isOk);
    if (!isOk || growth <= 0)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Height'!"), QMessageBox::Ok);
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
    if (old >= 18)
    {
        if (isSportsman)
        {
            if (sex == 1)
            {
                p_opwc170  = normalize(100.0*(1.0 - (32.0 - opwc170)/22.0));
                p_ompk = normalize(100.0*(1.0 - (75.0 - ompk)/35.0));
                p_alakm = normalize(100.0*(1.0 - (11.0 - alakm)/8.5));
                p_alake = normalize(100.0*(1.0 - (60.0 - alake)/35.0));
                p_lakm = normalize(100.0*(1.0 - (8.0 - lakm)/6.5));
                p_lake = normalize(100.0*(1.0 - (45.0 - lake)/30.0));
                p_pano = normalize(100.0*(1.0 - (75.0 - pano)/45.0));
                p_chsspano = normalize(100.0*(1.0 - (180.0 - chsspano)/65.0));
                p_ome = normalize(100.0*(1.0 - (258.0 - ome)/138.0));
            }
            else
            {
                p_opwc170  = normalize(100.0*(1.0 - (27.0 - opwc170)/19.0));
                p_ompk = normalize(100.0*(1.0 - (70.0 - ompk)/30.0));
                p_alakm = normalize(100.0*(1.0 - (9.0 - alakm)/6.5));
                p_alake = normalize(100.0*(1.0 - (50.0 - alake)/25.0));
                p_lakm = normalize(100.0*(1.0 - (7.0 - lakm)/5.5));
                p_lake = normalize(100.0*(1.0 - (40.0 - lake)/25.0));
                p_pano = normalize(100.0*(1.0 - (70.0 - pano)/40.0));
                p_chsspano = normalize(100.0*(1.0 - (175.0 - chsspano)/60.0));
                p_ome = normalize(100.0*(1.0 - (220.0 - ome)/110.0));
            }
        }
        else
        {
            if (sex == 1)
            {
                p_opwc170  = normalize(100.0*(1.0 - (25.0 - opwc170)/20.0));
                p_ompk = normalize(100.0*(1.0 - (65.0 - ompk)/40.0));
                p_alakm = normalize(100.0*(1.0 - (8.5 - alakm)/7.0));
                p_alake = normalize(100.0*(1.0 - (50.0 - alake)/40.0));
                p_lakm = normalize(100.0*(1.0 - (6.5 - lakm)/5.5));
                p_lake = normalize(100.0*(1.0 - (40.0 - lake)/30.0));
                p_pano = normalize(100.0*(1.0 - (65.0 - pano)/45.0));
                p_chsspano = normalize(100.0*(1.0 - (160.0 - chsspano)/70.0));
                p_ome = normalize(100.0*(1.0 - (200.0 - ome)/100.0));
            }
            else
            {
                p_opwc170 = normalize(100.0*(1.0 - (20.0 - opwc170)/16.0));
                p_ompk = normalize(100.0*(1.0 - (60.0 - ompk)/40.0));
                p_alakm = normalize(100.0*(1.0 - (6.5 - alakm)/5.0));
                p_alake = normalize(100.0*(1.0 - (40.0 - alake)/30.0));
                p_lakm = normalize(100.0*(1.0 - (6.0 - lakm)/5.0));
                p_lake = normalize(100.0*(1.0 - (30.0 - lake)/20.0));
                p_pano = normalize(100.0*(1.0 - (55.0 - pano)/40.0));
                p_chsspano = normalize(100.0*(1.0 - (150.0 - chsspano)/70.0));
                p_ome = normalize(100.0*(1.0 - (190.0 - ome)/110.0));
            }
        }
    }
    else
    {
        if (isSportsman)
        {
            if (sex == 1)
            {
                p_opwc170  = normalize(100.0*(1.0 - (28.0 - opwc170)/20.0));
                p_ompk = normalize(100.0*(1.0 - (65.0 - ompk)/40.0));
                p_alakm = normalize(100.0*(1.0 - (8.5 - alakm)/6.0));
                p_alake = normalize(100.0*(1.0 - (50.0 - alake)/35.0));
                p_lakm = normalize(100.0*(1.0 - (7.0 - lakm)/6.5));
                p_lake = normalize(100.0*(1.0 - (42.0 - lake)/32.0));
                p_pano = normalize(100.0*(1.0 - (75.0 - pano)/45.0));
                p_chsspano = normalize(100.0*(1.0 - (175.0 - chsspano)/60.0));
                p_ome = normalize(100.0*(1.0 - (240.0 - ome)/135.0));
            }
            else
            {
                p_opwc170  = (100.0*(1.0 - (26.0 - opwc170)/20.0));
                p_ompk = (100.0*(1.0 - (60.0 - ompk)/35.0));
                p_alakm = (100.0*(1.0 - (8.0 - alakm)/6.0));
                p_alake = (100.0*(1.0 - (40.0 - alake)/30.0));
                p_lakm = (100.0*(1.0 - (6.5 - lakm)/5.5));
                p_lake = (100.0*(1.0 - (40.0 - lake)/30.0));
                p_pano = (100.0*(1.0 - (70.0 - pano)/40.0));
                p_chsspano = (100.0*(1.0 - (175.0 - chsspano)/60.0));
                p_ome = (100.0*(1.0 - (220.0 - ome)/120.0));
            }
        }
        else
        {
            if (sex == 1)
            {
                p_opwc170  = normalize(100.0*(1.0 - (22.0 - opwc170)/20.0));
                p_ompk = normalize(100.0*(1.0 - (65.0 - ompk)/45.0));
                p_alakm = normalize(100.0*(1.0 - (7.5 - alakm)/6.5));
                p_alake = normalize(100.0*(1.0 - (45.0 - alake)/35.0));
                p_lakm = normalize(100.0*(1.0 - (6.5 - lakm)/5.5));
                p_lake = normalize(100.0*(1.0 - (40.0 - lake)/30.0));
                p_pano = normalize(100.0*(1.0 - (60.0 - pano)/45.0));
                p_chsspano = normalize(100.0*(1.0 - (160.0 - chsspano)/70.0));
                p_ome = normalize(100.0*(1.0 - (200.0 - ome)/130.0));
            }
            else
            {
                p_opwc170 = normalize(100.0*(1.0 - (20.0 - opwc170)/18.0));
                p_ompk = normalize(100.0*(1.0 - (60.0 - ompk)/40.0));
                p_alakm = normalize(100.0*(1.0 - (6.5 - alakm)/5.5));
                p_alake = normalize(100.0*(1.0 - (40.0 - alake)/30.0));
                p_lakm = normalize(100.0*(1.0 - (6.0 - lakm)/5.0));
                p_lake = normalize(100.0*(1.0 - (35.0 - lake)/25.0));
                p_pano = normalize(100.0*(1.0 - (55.0 - pano)/40.0));
                p_chsspano = normalize(100.0*(1.0 - (150.0 - chsspano)/80.0));
                p_ome = normalize(100.0*(1.0 - (190.0 - ome)/120.0));
            }
        }
    }

    p_ufp = normalize((p_opwc170 + p_ompk + p_alakm + p_alake + p_lakm + p_lake + p_pano + p_chsspano + p_ome)/9.0);


    //--------------------------------------------------------

//    ui->leN1->setText(QString("%1").arg(N1,0,'f',0));
//    ui->leN2->setText(QString("%1").arg(N2,0,'f',0));
//    ui->len1->setText(QString("%1").arg(n1,0,'f',0));
//    ui->len2->setText(QString("%1").arg(n2,0,'f',0));
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

    getoPWC170(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labeloPWC170,opwc170,val1,val2,val3,val4);
    // ---------------------------------- oMPK ------------------------------------
    getoMPK(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labeloMPK,ompk,val1,val2,val3,val4);
    // ---------------------------------- ALAKm ------------------------------------
    getALAKm(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labelALAKm,alakm,val1,val2,val3,val4);
    // ---------------------------------- ALAKe ------------------------------------
    getALAKe(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labelALAKe,alake,val1,val2,val3,val4);
    // ---------------------------------- LAKm ------------------------------------
    getLAKm(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labelLAKm,lakm,val1,val2,val3,val4);
    // ---------------------------------- LAKe ------------------------------------
    getLAKe(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labelLAKe,lake,val1,val2,val3,val4);
    // ---------------------------------- PANO ------------------------------------
    getPANO(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labelPANO,pano,val1,val2,val3,val4);
    // ---------------------------------- CHSSpano ------------------------------------
    getCHSSpano(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labelCHSSpano,chsspano,val1,val2,val3,val4);
    // ---------------------------------- OME ------------------------------------
    getOME(sex,old,isSportsman,val1,val2,val3,val4);
    showIndicator(ui->labelOME,ome,val1,val2,val3,val4);

    showIndicatorTxt(ui->labelV1,ui->labelF1,0.5*(p_opwc170 + p_ompk));
    showIndicatorTxt(ui->labelV2,ui->labelF2,0.5*(p_alakm + p_alake));
    showIndicatorTxt(ui->labelV3,ui->labelF3,0.5*(p_lakm + p_lake));
    showIndicatorTxt(ui->labelV4,ui->labelF4,0.5*(p_pano + p_chsspano));
    showIndicatorTxt(ui->labelV5,ui->labelF5,p_ome);
    showIndicatorTxt(ui->labelV6,ui->labelF6,p_ufp);


    ui->pbSave->setEnabled(true);
    ui->pbPrint->setEnabled(true);
    ui->pbHint->setEnabled(true);
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
                                 WHERE surveyed_id = %1 AND dt = '%2'").arg(surveyed_id).arg(dt).arg(weight).arg(growth).arg(N1,0,'f',0).arg(N2,0,'f',0).arg(n1,0,'f',0).arg(n2,0,'f',0).arg(hr1,0,'f',0).arg(hr2,0,'f',0).\
                                 arg(apwc170,0,'f',2).arg(opwc170,0,'f',2).arg(ampk,0,'f',2).arg(ompk,0,'f',2).arg(alakm,0,'f',2).arg(alake,0,'f',2).arg(lakm,0,'f',2).\
                                 arg(lake,0,'f',2).arg(pano,0,'f',2).arg(chsspano,0,'f',2).arg(p_ome,0,'f',2).arg(0.5*(p_opwc170 + p_ompk),0,'f',2).arg(0.5*(p_alakm + p_alake),0,'f',2).\
                                 arg(0.5*(p_lakm + p_lake),0,'f',2).arg(0.5*(p_pano + p_chsspano),0,'f',2).arg(p_ome,0,'f',2).arg(p_ufp,0,'f',2).arg(old)))
            QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);

        return;
    }


    if (!query.exec(QString("INSERT INTO surveySHVSM (surveyed_id,dt,weight,growth,N1,N2,n_1,n_2,HR1,HR2,aPWC170,oPWC170,aMPK,oMPK,ALAKm,ALAKe,LAKm,LAKe,PANO,CHSSpano,OME,TE,SE,SPE,SPS,RP,UFP,old) \
                             VALUES (%1,'%2',%3,%4,%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,%19,%20,%21,%22,%23,%24,%25,%26,%27,%28)").arg(surveyed_id).arg(dt).arg(weight).arg(growth).\
                             arg(N1,0,'f',0).arg(N2,0,'f',0).arg(n1,0,'f',0).arg(n2,0,'f',0).arg(hr1,0,'f',0).arg(hr2,0,'f',0).arg(apwc170,0,'f',2).arg(opwc170,0,'f',2).arg(ampk,0,'f',2).arg(ompk,0,'f',2).arg(alakm,0,'f',2).arg(alake,0,'f',2).\
                             arg(lakm,0,'f',2).arg(lake,0,'f',2).arg(pano,0,'f',2).arg(chsspano,0,'f',2).arg(ome,0,'f',2).arg(0.5*(p_opwc170 + p_ompk),0,'f',2).arg(0.5*(p_alakm + p_alake),0,'f',2).\
                             arg(0.5*(p_lakm + p_lake),0,'f',2).arg(0.5*(p_pano + p_chsspano),0,'f',2).arg(p_ome,0,'f',2).arg(p_ufp,0,'f',2).arg(old)))
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

    labelF->setText(QString("%1").arg(indicator,0,'f',2));
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


QString SHVSMCreateDialog::getIndicatorTxt(QLabel* lb)
{
    QString text;
    QColor col = lb->palette().background().color();

    if (col == QColor("red"))
        text = tr("Low");
    else if (col == QColor("gray"))
        text = tr("Below the average");
    else if (col == QColor("yellow"))
        text = tr("Average");
    else if (col == QColor("aqua"))
        text = tr("Above average");
    else if (col == QColor("lime"))
        text = tr("High");
    return text;
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
        n1 = (N1*6.12)/(1.33*0.4*weight);
    else
        n1 = (N1*6.12)/(1.33*0.2*weight);
    if (isSportsman)
    {
        N2 = (N1 + 0.75*N1);
        n2 = n1 + n1*0.75;
    }
    else
    {
        N2 = N1 + 0.5*N1;
        n2 = n1 + n1*0.5;
    }
    ui->leN1->setText(QString("%1").arg(int(N1)));
    ui->leN2->setText(QString("%1").arg(int(N2)));
    ui->len1->setText(QString("%1").arg(int(n1)));
    ui->len2->setText(QString("%1").arg(int(n2)));
}

void SHVSMCreateDialog::slotPrintReport(void)
{
    PrintReportDialog* pdlg = new PrintReportDialog(this);

    genReport(pdlg);
    pdlg->exec();
}

void SHVSMCreateDialog::genReport(PrintReportDialog* p)
{
    QString text = "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">",
            name = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString(),
            sex_n = (sex == 1) ? tr("M") : tr("W"),
            qualification_n = (isSportsman) ? tr("Athlete") : tr("Non-athlete");

    text += tr("<h1><center>SHVSM - complex express estimation of functional preparedness</center></h1>");
    text += tr("<center>Malikov N.V, Malikova A.N., Svat'ev A.V.<br><b>Examination report</b></center>");
    text += "<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\">";

    text += tr("<tr><td colspan=\"6\">Date of  examination: <b>%1</b></tr>").arg(ui->deDate->text());
    text += tr("<tr><th width=\"200%\">Surname</th><th>Sex</th><th>Age</th><th>Status</th><th>Body<br>length (sm)</th><th>Body<br>mass (kg)</th></tr>");
    text += QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td><td>%6</td></tr>").arg(name).arg(sex_n).arg(old).arg(qualification_n).arg(ui->leGrowth->text()).arg(ui->leWeight->text());
    text += tr("<tr><th colspan=\"6\">Entrance  calculation data</th></tr>");
    text += tr("<tr><td colspan=\"5\">The first loading intensity on the veloergometer N1</td><td>%1</td></tr>").arg(ui->leN1->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">The second loading intensity on the veloergometer N2</td><td>%1</td></tr>").arg(ui->leN2->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">The first loading ascents on a step amount n1</td><td>%1</td></tr>").arg(ui->len1->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">The second loading ascents on a step amount n2</td><td>%1</td></tr>").arg(ui->len2->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Heart rate after the first loading HR1</td><td>%1</td></tr>").arg(ui->leHR1->text().toFloat(),0,'f',0);
    text += tr("<tr><td colspan=\"5\">Heart rate after the second loading  HR2</td><td>%1</td></tr>").arg(ui->leHR2->text().toFloat(),0,'f',0);
    text += tr("<tr><th colspan=\"6\">Calculation data</th></tr>");

    text += tr("<tr><th colspan=\"4\">Index</th><th>Numerical<br>value</th><th>Functional<br>estimation</th></tr>");
    text += tr("<tr><td colspan=\"4\">aPWC<sub>170</td><td>%1</td><td></td></tr>").arg(ui->labelaPWC170->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"4\">rPWC<sub>170</td><td>%1</td><td>%2</td></tr>").arg(ui->labeloPWC170->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labeloPWC170));
    text += tr("<tr><td colspan=\"4\">aVO<sub>2max</td><td>%1</td><td></td></tr>").arg(ui->labelaMPK->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"4\">rVO<sub>2max</td><td>%1</td><td>%2</td></tr>").arg(ui->labeloMPK->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labeloMPK));

    text += tr("<tr><td colspan=\"4\">ALAKp</td><td>%1</td><td>%2</td></tr>").arg(ui->labelALAKm->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labelALAKm));
    text += tr("<tr><td colspan=\"4\">ALAKc</td><td>%1</td><td>%2</td></tr>").arg(ui->labelALAKe->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labelALAKe));
    text += tr("<tr><td colspan=\"4\">LAKp</td><td>%1</td><td>%2</td></tr>").arg(ui->labelLAKm->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labelLAKm));
    text += tr("<tr><td colspan=\"4\">LAKc</td><td>%1</td><td>%2</td></tr>").arg(ui->labelLAKe->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labelLAKe));
    text += tr("<tr><td colspan=\"4\">AMT</td><td>%1</td><td>%2</td></tr>").arg(ui->labelPANO->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labelPANO));
    text += tr("<tr><td colspan=\"4\">HR<sub>AMT</td><td>%1</td><td>%2</td></tr>").arg(ui->labelCHSSpano->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labelCHSSpano));
    text += tr("<tr><td colspan=\"4\">GMC</td><td>%1</td><td>%2</td></tr>").arg(ui->labelOME->text().toFloat(),0,'f',2).arg(getIndicatorTxt(ui->labelOME));

    text += tr("<tr><td colspan=\"4\"><b>Functional preparedness level</b></td><td><b>%1</b></td><td><b>%2</b></td></tr>").arg(ui->labelV6->text().toFloat(),0,'f',2).arg(ui->labelF6->text());
    text += tr("<tr><td colspan=\"4\">General endurance</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV1->text().toFloat(),0,'f',2).arg(ui->labelF1->text());
    text += tr("<tr><td colspan=\"4\">Speed endurance</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV2->text().toFloat(),0,'f',2).arg(ui->labelF2->text());
    text += tr("<tr><td colspan=\"4\">Speed-strength endurance</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV3->text().toFloat(),0,'f',2).arg(ui->labelF3->text());
    text += tr("<tr><td colspan=\"4\">Energetic system economy</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV4->text().toFloat(),0,'f',2).arg(ui->labelF4->text());
    text += tr("<tr><td colspan=\"4\">Reserve capability</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV5->text().toFloat(),0,'f',2).arg(ui->labelF5->text());

    text += "</table>";



    p->setText(text);
}

void SHVSMCreateDialog::slotHint(void)
{
    PrintReportDialog* pdlg = new PrintReportDialog(this);

    pdlg->setHint();
    pdlg->exec();
}

void SHVSMCreateDialog::slotClear(void)
{
    ui->pbSave->setEnabled(false);
    ui->pbPrint->setEnabled(false);
    ui->pbHint->setEnabled(false);

    ui->leWeight->clear();
    ui->leGrowth->clear();
    ui->leN1->clear();
    ui->leN2->clear();
    ui->len1->clear();
    ui->len2->clear();
    ui->leHR1->clear();
    ui->leHR2->clear();
    ui->labelaPWC170->clear();
    ui->labeloPWC170->clear();
    ui->labelaMPK->clear();
    ui->labeloMPK->clear();
    ui->labelALAKm->clear();
    ui->labelALAKe->clear();
    ui->labelLAKe->clear();
    ui->labelLAKm->clear();
    ui->labelPANO->clear();
    ui->labelCHSSpano->clear();
    ui->labelOME->clear();
    ui->labelV1->clear();
    ui->labelF1->clear();
    ui->labelV2->clear();
    ui->labelF2->clear();
    ui->labelV3->clear();
    ui->labelF3->clear();
    ui->labelV4->clear();
    ui->labelF4->clear();
    ui->labelV5->clear();
    ui->labelF5->clear();
    ui->labelV6->clear();
    ui->labelF6->clear();

    ui->labeloPWC170->setStyleSheet("QLabel { background-color : ; }");
    ui->labeloMPK->setStyleSheet("QLabel { background-color : ; }");
    ui->labelALAKe->setStyleSheet("QLabel { background-color : ; }");
    ui->labelALAKm->setStyleSheet("QLabel { background-color : ; }");
    ui->labelLAKe->setStyleSheet("QLabel { background-color : ; }");
    ui->labelLAKm->setStyleSheet("QLabel { background-color : ; }");
    ui->labelPANO->setStyleSheet("QLabel { background-color : ; }");
    ui->labelCHSSpano->setStyleSheet("QLabel { background-color : ; }");
    ui->labelOME->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV1->setStyleSheet("QLabel { background-color : ; }");
    ui->labelF1->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV2->setStyleSheet("QLabel { background-color : ; }");
    ui->labelF2->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV3->setStyleSheet("QLabel { background-color : ; }");
    ui->labelF3->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV4->setStyleSheet("QLabel { background-color : ; }");
    ui->labelF4->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV5->setStyleSheet("QLabel { background-color : ; }");
    ui->labelF5->setStyleSheet("QLabel { background-color : ; }");
    ui->labelV6->setStyleSheet("QLabel { background-color : ; }");
    ui->labelF6->setStyleSheet("QLabel { background-color : ; }");

}
