#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <math.h>
#include "shvsmintegralcreatedialog.h"
#include "printreportdialog.h"
#include "ui_shvsmintegralcreatedialog.h"


void normalize(double& p)
{
    if (p < 0)
        p = 0;
    else if (p > 100)
        p = 100;
}

SHVSMIntegralCreateDialog::SHVSMIntegralCreateDialog(QSqlDatabase* pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SHVSMIntegralCreateDialog)
{
    ui->setupUi(this);
    db = pdb;
    setupForm();
}

SHVSMIntegralCreateDialog::~SHVSMIntegralCreateDialog()
{
    delete ui;
    delete model;
}

void SHVSMIntegralCreateDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}

void SHVSMIntegralCreateDialog::setupForm(void)
{
    QString query = "SELECT surveyed.id, surveyed.name,team.name,sex.name,qualification.name,surveyed.DOB,sex_id,qualification_id \
            FROM surveyed \
            LEFT OUTER JOIN team ON surveyed.team_id = team.id \
            LEFT OUTER JOIN sex ON surveyed.sex_id = sex.id \
            LEFT OUTER JOIN qualification ON surveyed.qualification_id = qualification.id";

    ui->pbSave->setEnabled(false);
    ui->pbPrint->setEnabled(false);

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
}

void SHVSMIntegralCreateDialog::slotCalcSHVSMIntegral(void)
{
    bool isOk;
    QString dob = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString();
    double p_sok,
           p_mok,
           p_oadc,
           p_oadd,
           p_vc,
           p_opss,
           p_ir,
           p_kek,
           p_si,
           p_dgel,
           p_ig,
           p_is,
           p_dte,
           p_dtbe,
           p_dev_dgel;

    sex = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),6)).toInt();
    isSportsman = (ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),7)).toInt() == 1) ? true : false;
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

    hr = ui->leHR->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Heart rate'!"), QMessageBox::Ok);
        ui->leHR->setFocus();
        return;
    }

    sbp = ui->leSBP->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Systolic blood pressure'!"), QMessageBox::Ok);
        ui->leSBP->setFocus();
        return;
    }

    dbp = ui->leDBP->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Diastolic blood pressure'!"), QMessageBox::Ok);
        ui->leDBP->setFocus();
        return;
    }

    lvActual = ui->leLActual->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Actual vital capacity of lungs'!"), QMessageBox::Ok);
        ui->leLActual->setFocus();
        return;
    }

    dte = ui->leDTE->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Delay time exhalations'!"), QMessageBox::Ok);
        ui->leDTE->setFocus();
        return;
    }

    dtbe = ui->leDTBE->text().toFloat(&isOk);
    if (!isOk)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the 'Delay time breathing exhalation'!"), QMessageBox::Ok);
        ui->leDTBE->setFocus();
        return;
    }

    // Определяем возраст человека
    old = QDate::currentDate().year() - dob.right(4).toInt();
    if (old <= 0 || old > 120)
    {
        QMessageBox::critical(this, tr("Error"),tr("Incorrectly set the birthday or date survey!"), QMessageBox::Ok);
        return;
    }

    // ------------------------------ 1. СОК ----------------------------------------
    sok = 0.53*sbp + 0.617*growth + 0.231*weight - 1.07*dbp - 0.698*old - 22.64;
    if (isSportsman)
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV1,ui->labelT1,sok,50.00,59.99,80.00,90.00);
        else
            showIndicatorTxt(ui->labelV1,ui->labelT1,sok,45.00,54.99,75.00,85.00);
    }
    else
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV1,ui->labelT1,sok,40.00,44.99,70.00,80.00);
        else
            showIndicatorTxt(ui->labelV1,ui->labelT1,sok,39.50,48.49,66.50,75.50);
    }

    // ------------------------------ 2. МОК ----------------------------------------
    mok = hr*sok/1000.0;
    if (isSportsman)
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV2,ui->labelT2,mok,4.50,5.49,7.50,8.50);
        else
            showIndicatorTxt(ui->labelV2,ui->labelT2,mok,3.50,4.49,6.50,7.50);
    }
    else
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV2,ui->labelT2,mok,3.00,3.99,6.00,7.00);
        else
            showIndicatorTxt(ui->labelV2,ui->labelT2,mok,2.50,3.49,5.50,6.50);
    }
    // ------------------------------ 3. СИ ----------------------------------------
    si = mok/(pow(weight,0.425)*pow(growth,0.725)*0.007184);
    ui->labelV3->setText(QString("%1").arg(si,0,'f',2));
    if (isSportsman)
    {
        if (sex == 1)
        {
            if (si < 2.7)
                ui->labelT3->setText(tr("Hypokinetic type of regulation"));
            else if (si >= 2.7 && si <= 3.2)
                ui->labelT3->setText(tr("Norm"));
            else
                ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
        }
        else
        {
            if (si < 3.0)
                ui->labelT3->setText(tr("Hypokinetic type of regulation"));
            else if (si >= 3.0 && si <= 3.5)
                ui->labelT3->setText(tr("Norm"));
            else
                ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
        }
    }
    else
    {
        if (sex == 1)
        {
            if (si < 3.0)
                ui->labelT3->setText(tr("Hypokinetic type of regulation"));
            else if (si >= 3.0 && si <= 3.5)
                ui->labelT3->setText(tr("Norm"));
            else
                ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
        }
        else
        {
            if (si < 3.2)
                ui->labelT3->setText(tr("Hypokinetic type of regulation"));
            else if (si >= 3.2 && si <= 3.6)
                ui->labelT3->setText(tr("Norm"));
            else
                ui->labelT3->setText(tr("Hyperkinetic type of regulation"));
        }
    }
    // ------------------------------ 4. ОПСС ----------------------------------------
    opss = ((dbp + 0.33*(sbp - dbp))*1333*60)/(mok*1000);
    if (isSportsman)
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV4,ui->labelT4,opss,800.00,1199.00,2000.00,2400.00);
        else
            showIndicatorTxt(ui->labelV4,ui->labelT4,opss,900.00,1299.00,2100.00,2500.00);
    }
    else
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV4,ui->labelT4,opss,1000.00,1399.00,2200.00,2600.00);
        else
            showIndicatorTxt(ui->labelV4,ui->labelT4,opss,1200.00,1599.00,2400.00,2800.00);
    }

    // ------------------------------ 5. VC ----------------------------------------
    vc = 40.0*pow(1000.0*weight/growth,0.5);
    if (isSportsman)
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV5,ui->labelT5,vc,825.00,879.00,990.00,1045.00);
        else
            showIndicatorTxt(ui->labelV5,ui->labelT5,vc,720.00,759.00,840.00,880.00);
    }
    else
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV5,ui->labelT5,vc,680.00,719.00,800.00,840.00);
        else
            showIndicatorTxt(ui->labelV5,ui->labelT5,vc,500.00,539.00,620.00,660.00);
    }

    // ------------------------------ 6. ИР ----------------------------------------
    ir = hr*sbp/100;
    if (isSportsman)
    {
        if (sex == 1)
            showIndicatorTxtI(ui->labelV6,ui->labelT6,ir,98.00,93.00,66.00,56.00);
        else
            showIndicatorTxtI(ui->labelV6,ui->labelT6,ir,103.00,98.00,71.00,61.00);
    }
    else
    {
        if (sex == 1)
            showIndicatorTxtI(ui->labelV6,ui->labelT6,ir,108.00,103.00,76.00,66.00);
        else
            showIndicatorTxtI(ui->labelV6,ui->labelT6,ir,110.00,105.00,78.00,68.00);
    }
    // ------------------------------ 7. КЭК ----------------------------------------
    kek = hr*(sbp - dbp);
    if (isSportsman)
    {
        if (sex == 1)
            showIndicatorTxtI(ui->labelV7,ui->labelT7,kek,3200.00,2801.00,2000.00,1600.00);
        else
            showIndicatorTxtI(ui->labelV7,ui->labelT7,kek,3400.00,3001.00,2200.00,1800.00);
    }
    else
    {
        if (sex == 1)
            showIndicatorTxtI(ui->labelV7,ui->labelT7,kek,3600.00,3201.00,2400.00,2900.00);
        else
            showIndicatorTxtI(ui->labelV7,ui->labelT7,kek,3800.00,3401.00,2600.00,2200.00);
    }

    // ------------------------------ 8. ОАДС ----------------------------------------
    if (sex == 1)
        oadc = sbp - (91 + 0.5*old + 0.1*weight);
    else
        oadc = sbp - (88 + 0.7*old + 0.15*weight);

    ui->labelV8->setText(QString("%1").arg(oadc,0,'f',2));
    if (oadc < 0)
        ui->labelT8->setText(tr("Below the norm"));
    else if (oadc >=0 && oadc <= 30)
        ui->labelT8->setText(tr("Norm"));
    else
        ui->labelT8->setText(tr("Above norm"));

    // ------------------------------ 9. ОАДД ----------------------------------------
    if (sex == 1)
        oadd = dbp - (58 + 0.1*old + 0.15*weight);
    else
        oadd = dbp - (62 + 0.17*old + 0.1*weight);

    ui->labelV9->setText(QString("%1").arg(oadc,0,'f',2));
    if (oadc < 0)
        ui->labelT9->setText(tr("Below the norm"));
    else if (oadc >=0 && oadc <= 30)
        ui->labelT9->setText(tr("Norm"));
    else
        ui->labelT9->setText(tr("Above norm"));

    // -------------------------------- ДЖЕЛ ----------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
            dgel = (27.63 - 0.122*old)*growth;
        else
            dgel = (21.78 - 0.101*old)*growth;
    }
    else
    {
        if (sex == 1)
            dgel = (27.63 - 0.122*old)*growth - 500;
        else
            dgel = (21.78 - 0.101*old)*growth - 300;
    }
    ui->leLNorm->setText(QString("%1").arg(dgel,0,'f',2));

    // -------------------------------- ОтклЖЕЛ ----------------------------------------
    dev_dgel = ((lvActual - dgel)/lvActual)*100;
    ui->leLDeviation->setText(QString("%1").arg(dev_dgel,0,'f',2));
    if (isSportsman)
    {
        if (sex == 1)
        {
            if (dev_dgel < -7.5)
                ui->labelFE->setText(tr("Significantly below normal"));
            else if (dev_dgel >= -7.5 && dev_dgel <= 0)
                ui->labelFE->setText(tr("Below the norm"));
            else if (dev_dgel > 0 && dev_dgel <= 14.99)
                ui->labelFE->setText(tr("Norm"));
            else if (dev_dgel >= 15 && dev_dgel <= 25)
                ui->labelFE->setText(tr("Above the norm"));
            else
                ui->labelFE->setText(tr("Significantly above normal"));
        }
        else
        {
            if (dev_dgel < -10)
                ui->labelFE->setText(tr("Significantly below normal"));
            else if (dev_dgel >= -10 && dev_dgel <= 0)
                ui->labelFE->setText(tr("Below the norm"));
            else if (dev_dgel > 0 && dev_dgel <= 9.99)
                ui->labelFE->setText(tr("Norm"));
            else if (dev_dgel >= 10 && dev_dgel <= 20)
                ui->labelFE->setText(tr("Above the norm"));
            else
                ui->labelFE->setText(tr("Significantly above normal"));
        }
    }
    else
    {
        if (sex == 1)
        {
            if (dev_dgel < -15)
                ui->labelFE->setText(tr("Significantly below normal"));
            else if (dev_dgel >= -15 && dev_dgel <= 0)
                ui->labelFE->setText(tr("Below the norm"));
            else if (dev_dgel > 0 && dev_dgel <= 7.49)
                ui->labelFE->setText(tr("Norm"));
            else if (dev_dgel >= 7.5 && dev_dgel <= 10.75)
                ui->labelFE->setText(tr("Above the norm"));
            else
                ui->labelFE->setText(tr("Significantly above normal"));
        }
        else
        {
            if (dev_dgel < -17.5)
                ui->labelFE->setText(tr("Significantly below normal"));
            else if (dev_dgel >= -17.5 && dev_dgel <= 0)
                ui->labelFE->setText(tr("Below the norm"));
            else if (dev_dgel > 0 && dev_dgel <= 4.99)
                ui->labelFE->setText(tr("Norm"));
            else if (dev_dgel >= 5 && dev_dgel <= 10)
                ui->labelFE->setText(tr("Above the norm"));
            else
                ui->labelFE->setText(tr("Significantly above normal"));
        }
    }

    // ------------------------------ 10. ИГ ----------------------------------------
    ig = dtbe/hr;
    if (isSportsman)
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV10,ui->labelT10,ig,0.52,0.609,0.787,0.884);
        else
            showIndicatorTxt(ui->labelV10,ui->labelT10,ig,0.42,0.509,0.687,0.774);
    }
    else
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV10,ui->labelT10,ig,0.32,0.409,0.587,0.674);
        else
            showIndicatorTxt(ui->labelV10,ui->labelT10,ig,0.26,0.369,0.547,0.634);
    }

    // ------------------------------ 11. ИC ----------------------------------------
    is = 2.0*dgel*dtbe/hr;
    if (isSportsman)
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV11,ui->labelT11,is,2800,3500,4901,5600);
        else
            showIndicatorTxt(ui->labelV11,ui->labelT11,is,2300,3000,4401,5100);
    }
    else
    {
        if (sex == 1)
            showIndicatorTxt(ui->labelV11,ui->labelT11,is,1800,2500,3901,4600);
        else
            showIndicatorTxt(ui->labelV11,ui->labelT11,is,800,1500,2901,3600);
    }

    // ------------------------------ 12. УФСС ----------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
        {
            p_sok = 100.0*(1.0 - (100.0 - sok)/60.0);
            p_mok = 100.0*(1.0 - (10.0 - mok)/7.0);
            p_oadc = 100.0*((30.0 - oadc)/30.0 - 1.0);
            p_oadd = 100.0*((30.0 - oadd)/30.0 - 1.0);
            p_vc = 100.0*(1.0 - (1200.0 - vc)/700.0);
            p_opss = 100.0*((2800.0 - opss)/2400.0 - 1.0);
            p_ir = 100.0*((120.0 - ir)/80.0 - 1.0);
            p_kek = 100.0*((3600.0 - ir)/2400.0 - 1.0);
            p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
        }
        else
        {
            p_sok = 100.0*(1.0 - (90.0 - sok)/55.0);
            p_mok = 100.0*(1.0 - (8.0 - mok)/5.0);
            p_oadc = 100.0*((30.0 - oadc)/30.0 - 1.0);
            p_oadd = 100.0*((30.0 - oadd)/30.0 - 1.0);
            p_vc = 100.0*(1.0 - (1000.0 - vc)/700.0);
            p_opss = 100.0*((2900.0 - opss)/2500.0 - 1.0);
            p_ir = 100.0*((125.0 - ir)/80.0 - 1.0);
            p_kek = 100.0*((3800.0 - ir)/2400.0 - 1.0);
            p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
        }
    }
    else
    {
        if (sex == 1)
        {
            p_sok = 100.0*(1.0 - (90.0 - sok)/60.0);
            p_mok = 100.0*(1.0 - (9.0 - mok)/7.0);
            p_oadc = 100.0*((30.0 - oadc)/30.0 - 1.0);
            p_oadd = 100.0*((30.0 - oadd)/30.0 - 1.0);
            p_vc = 100.0*(1.0 - (900.0 - vc)/600.0);
            p_opss = 100.0*((3000.0 - opss)/2400.0 - 1.0);
            p_ir = 100.0*((130.0 - ir)/85.0 - 1.0);
            p_kek = 100.0*((4400.0 - ir)/2600.0 - 1.0);
            p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
        }
        else
        {
            p_sok = 100.0*(1.0 - (85.0 - sok)/55.0);
            p_mok = 100.0*(1.0 - (7.0 - mok)/5.0);
            p_oadc = 100.0*((30.0 - oadc)/30.0 - 1.0);
            p_oadd = 100.0*((30.0 - oadd)/30.0 - 1.0);
            p_vc = 100.0*(1.0 - (800.0 - vc)/650.0);
            p_opss = 100.0*((3200.0 - opss)/2400.0 - 1.0);
            p_ir = 100.0*((135.0 - ir)/80.0 - 1.0);
            p_kek = 100.0*((4600.0 - ir)/2600.0 - 1.0);
            p_si = 100.0*(1.0 - ((fabs(si) - 0.5)/0.5));
        }
    }

    normalize(p_sok);
    normalize(p_mok);
    normalize(p_oadc);
    normalize(p_oadd);
    normalize(p_vc);
    normalize(p_opss);
    normalize(p_ir);
    normalize(p_kek);
    normalize(p_si);

    ufss = (p_sok + p_mok + p_oadc + p_oadd + p_vc + p_opss + p_ir + p_kek + p_si)/9.0;
    showIndicatorTxt(ui->labelV12,ui->labelT12,ufss,33.0,49.6,66.1,82.6);
    // ------------------------------ 13. УФСВД ----------------------------------------
    if (isSportsman)
    {
        if (sex == 1)
        {
            p_dgel = 100.0*(1.0 - (5500.0 - dgel)/3500.0);
            p_ig = 100.0*(1.0 - (0.95 - ig)/0.55);
            p_is = 100.0*(1.0 - (6000.0 - is)/3600.0);
            p_dte = 100.0*(1.0 - (100.0 - dte)/70.0);
            p_dtbe = 100.0*(1.0 - (80.0 - dtbe)/50.0);
            p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
        }
        else
        {
            p_dgel = 100.0*(1.0 - (5000.0 - dgel)/3000.0);
            p_ig = 100.0*(1.0 - (0.85 - ig)/0.5);
            p_is = 100.0*(1.0 - (5500.0 - is)/3100.0);
            p_dte = 100.0*(1.0 - (90.0 - dte)/60.0);
            p_dtbe = 100.0*(1.0 - (70.0 - dtbe)/40.0);
            p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
        }
    }
    else
    {
        if (sex == 1)
        {
            p_dgel = 100.0*(1.0 - (5000.0 - dgel)/3000.0);
            p_ig = 100.0*(1.0 - (0.725 - ig)/0.41);
            p_is = 100.0*(1.0 - (5400.0 - is)/4600.0);
            p_dte = 100.0*(1.0 - (85.0 - dte)/65.0);
            p_dtbe = 100.0*(1.0 - (65.0 - dtbe)/50.0);
            p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
        }
        else
        {
            p_dgel = 100.0*(1.0 - (4000.0 - dgel)/2500.0);
            p_ig = 100.0*(1.0 - (0.684 - ig)/0.44);
            p_is = 100.0*(1.0 - (4400.0 - is)/3800.0);
            p_dte = 100.0*(1.0 - (75.0 - dte)/60.0);
            p_dtbe = 100.0*(1.0 - (55.0 - dtbe)/40.0);
            p_dev_dgel = fabs(100.0*((20.0 - fabs(dev_dgel)) - 1.0/20.0));
        }
    }
    normalize(p_dgel);
    normalize(p_ig);
    normalize(p_is);
    normalize(p_dte);
    normalize(p_dtbe);
    normalize(p_dev_dgel);

    ufsvd = (p_dgel + p_ig + p_is + p_dte + p_dtbe + p_dev_dgel)/6.0;
    showIndicatorTxt(ui->labelV13,ui->labelT13,ufsvd,33.0,49.6,66.1,82.6);

    ui->pbSave->setEnabled(true);
    ui->pbPrint->setEnabled(true);
}

void SHVSMIntegralCreateDialog::slotSaveSHVSMIntegral(void)
{
    QSqlQuery query;
    QString dt = ui->deDate->text();
    int surveyed_id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();

    // Проверяем, есть ли уже такая запись
    if (!query.exec(QString("SELECT * FROM surveySHVSMIntegral WHERE surveyed_id = %1 AND dt = '%2'").arg(surveyed_id).arg(dt)))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        qDebug() << query.lastError();
        return;
    }
    if (query.next())
    {
        // Такая запись уже есть, перезаписываем ее
        if (!query.exec(QString("UPDATE surveySHVSMIntegral SET weight=%3,growth=%4,HR=%5,SAD=%6,DAD=%7,VL=%8,VLN=%9,VLD=%10,T1=%11,T2=%12,V1=%13,V2=%14,V3=%15,V4=%16,V5=%17,\
                                 V6=%18,V7=%19,V8=%20,V9=%21,V10=%22,V11=%23,V12=%24,V13=%25,old=%26 \
                                 WHERE surveyed_id = %1 AND dt = '%2'").arg(surveyed_id).arg(dt).arg(weight).arg(growth).\
                                arg(hr).arg(sbp).arg(dbp).arg(lvActual).arg(dgel).arg(dev_dgel).arg(dte).arg(dtbe).arg(sok).arg(mok).arg(si).arg(opss).arg(vc).arg(ir).arg(kek).arg(oadc).\
                                arg(oadd).arg(ig).arg(is).arg(ufss).arg(ufsvd).arg(old)))
            QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);

        return;
    }


    if (!query.exec(QString("INSERT INTO surveySHVSMIntegral (surveyed_id,dt,weight,growth,HR,SAD,DAD,VL,VLN,VLD,T1,T2,V1,V2,V3,V4,V5,V6,V7,V8,V9,V10,V11,V12,V13,old) \
                             VALUES (%1,'%2',%3,%4,%5,%6,%7,%8,%9,%10,%11,%12,%13,%14,%15,%16,%17,%18,%19,%20,%21,%22,%23,%24,%25,%26)").arg(surveyed_id).arg(dt).arg(weight).arg(growth).\
                             arg(hr).arg(sbp).arg(dbp).arg(lvActual).arg(dgel).arg(dev_dgel).arg(dte).arg(dtbe).arg(sok).arg(mok).arg(si).arg(opss).arg(vc).arg(ir).arg(kek).arg(oadc).\
                             arg(oadd).arg(ig).arg(is).arg(ufss).arg(ufsvd).arg(old)))
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
}

void SHVSMIntegralCreateDialog::showIndicatorTxt(QLabel* labelF, QLabel* labelT,float indicator,float val1, float val2,float val3, float val4)
{

    if (labelF)
        labelF->setText(QString("%1").arg(indicator,0,'f',2));
    if (indicator < val1)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : red; }");
        labelT->setText(tr("Low"));
        labelT->setStyleSheet("QLabel { background-color : red; }");
    }
    else if (indicator >= val1 && indicator <= val2)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : gray; }");
        labelT->setText(tr("Below the average"));
        labelT->setStyleSheet("QLabel { background-color : gray; }");
    }
    else if (indicator > val2 && indicator <= val3)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : yellow; }");
        labelT->setText(tr("Average"));
        labelT->setStyleSheet("QLabel { background-color : yellow; }");
    }
    else if (indicator > val3 && indicator <= val4)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : aqua; }");
        labelT->setText(tr("Above average"));
        labelT->setStyleSheet("QLabel { background-color : aqua; }");
    }
    else
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : lime; }");
        labelT->setText(tr("High"));
        labelT->setStyleSheet("QLabel { background-color : lime; }");
    }
}

void SHVSMIntegralCreateDialog::showIndicatorTxtI(QLabel* labelF, QLabel* labelT,float indicator,float val1, float val2,float val3, float val4)
{

    if (labelF)
        labelF->setText(QString("%1").arg(indicator,0,'f',2));
    if (indicator > val1)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : red; }");
        labelT->setText(tr("Low"));
        labelT->setStyleSheet("QLabel { background-color : red; }");
    }
    else if (indicator <= val1 && indicator >= val2)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : gray; }");
        labelT->setText(tr("Below the average"));
        labelT->setStyleSheet("QLabel { background-color : gray; }");
    }
    else if (indicator < val2 && indicator >= val3)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : yellow; }");
        labelT->setText(tr("Average"));
        labelT->setStyleSheet("QLabel { background-color : yellow; }");
    }
    else if (indicator < val3 && indicator >= val4)
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : aqua; }");
        labelT->setText(tr("Above average"));
        labelT->setStyleSheet("QLabel { background-color : aqua; }");
    }
    else
    {
        if (labelF)
            labelF->setStyleSheet("QLabel { background-color : lime; }");
        labelT->setText(tr("High"));
        labelT->setStyleSheet("QLabel { background-color : lime; }");
    }
}

void SHVSMIntegralCreateDialog::slotPrintReport(void)
{
    PrintReportDialog* pdlg = new PrintReportDialog(this);

    genReport(pdlg);
    pdlg->exec();
}

void SHVSMIntegralCreateDialog::genReport(PrintReportDialog* p)
{
    QString text = "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">",
            name = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString(),
            sex_n = (sex == 1) ? tr("M") : tr("W"),
            qualification_n = (isSportsman) ? tr("Athlete") : tr("Non-athlete");

    text += tr("<h1><center>SHVSM-complex express estimation of functional state</center></h1>");
    text += tr("<center>Malikov N.V, Malikova A.N., Svat'ev A.V.<br><b>Examination report</b></center>");
    text += "<table border=\"1\" cellpadding=\"4\" cellspacing=\"0\">";

    text += tr("<tr><td colspan=\"6\">Date of  examination: <b>%1</b></tr>").arg(ui->deDate->text());
    text += tr("<tr><th width=\"200%\">Surname</th><th>Sex</th><th>Age</th><th>Qualification</th><th>Body<br>length</th><th>Body<br>mass</th></tr>");
    text += QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td><td>%6</td></tr>").arg(name).arg(sex_n).arg(old).arg(qualification_n).arg(ui->leGrowth->text()).arg(ui->leWeight->text());
    text += tr("<tr><th colspan=\"6\">Entrance  calculation data</th></tr>");

    text += tr("<tr><td colspan=\"5\">Heart rate (HR)</td><td>%1</td></tr>").arg(ui->leHR->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Systolic arterial pressure (APs)</td><td>%1</td></tr>").arg(ui->leSBP->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Diastolic arterial pressure (APd)</td><td>%1</td></tr>").arg(ui->leDBP->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Vital lung capacity (VLC)</td><td>%1</td></tr>").arg(ui->leLActual->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Inhalation breathing delay time (Tin)</td><td>%1</td></tr>").arg(ui->leDTE->text().toFloat(),0,'f',2);
    text += tr("<tr><td colspan=\"5\">Exhalation breathing delay time (Tex)</td><td>%1</td></tr>").arg(ui->leDTBE->text().toFloat(),0,'f',2);
    text += tr("<tr><th colspan=\"6\">Calculation data</th></tr>");

    text += tr("<tr><th colspan=\"4\">Index</th><th>Numerical<br>value</th><th>Functional<br>estimation</th></tr>");

    text += tr("<tr><td colspan=\"4\">Systole blood volume</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV1->text().toFloat(),0,'f',2).arg(ui->labelT1->text());
    text += tr("<tr><td colspan=\"4\">Minute blood volume</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV2->text().toFloat(),0,'f',2).arg(ui->labelT2->text());
    text += tr("<tr><td colspan=\"4\">Cardiac index</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV3->text().toFloat(),0,'f',2).arg(ui->labelT3->text());
    text += tr("<tr><td colspan=\"4\">General peripheral resistance</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV4->text().toFloat(),0,'f',2).arg(ui->labelT4->text());
    text += tr("<tr><td colspan=\"4\">Heart volume</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV5->text().toFloat(),0,'f',2).arg(ui->labelT5->text());
    text += tr("<tr><td colspan=\"4\">Robinson Index</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV6->text().toFloat(),0,'f',2).arg(ui->labelT6->text());
    text += tr("<tr><td colspan=\"4\">Circulation of blood economizing coefficient</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV7->text().toFloat(),0,'f',2).arg(ui->labelT7->text());
    text += tr("<tr><td colspan=\"4\"Systolic arterial pressure deviation</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV8->text().toFloat(),0,'f',2).arg(ui->labelT8->text());
    text += tr("<tr><td colspan=\"4\">Diastolic arterial pressure deviation</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV9->text().toFloat(),0,'f',2).arg(ui->labelT9->text());
    text += tr("<tr><td colspan=\"4\">Hypoxia index</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV10->text().toFloat(),0,'f',2).arg(ui->labelT10->text());
    text += tr("<tr><td colspan=\"4\">Skibinsky index</td><td>%1</td><td>%2</td></tr>").arg(ui->labelV11->text().toFloat(),0,'f',2).arg(ui->labelT11->text());
    text += tr("<tr><td colspan=\"4\"><b>Cardio-vascular system functional state level</b></td><td>%1</td><td>%2</td></tr>").arg(ui->labelV12->text().toFloat(),0,'f',2).arg(ui->labelT12->text());
    text += tr("<tr><td colspan=\"4\"><b>External breathing system functional state level</b></td><td>%1</td><td>%2</td></tr>").arg(ui->labelV13->text().toFloat(),0,'f',2).arg(ui->labelT13->text());

    text += "</table>";



    p->setText(text);
}
