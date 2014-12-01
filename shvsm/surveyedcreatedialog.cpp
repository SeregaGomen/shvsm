#include <QSqlDatabase>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlQuery>
#include "surveyedcreatedialog.h"
#include "ui_surveyedcreatedialog.h"

SurveyedCreateDialog::SurveyedCreateDialog(QSqlDatabase* pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SurveyedCreateDialog)
{
    ui->setupUi(this);
    db = pdb;
    setupForm();
}

SurveyedCreateDialog::~SurveyedCreateDialog()
{
    delete ui;
}

void SurveyedCreateDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}

void SurveyedCreateDialog::slotTextChanged(void)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled((ui->leName->text().length()) ? true : false);
}

void SurveyedCreateDialog::accept(void)
{
    QSqlQuery query;
    QString name = ui->leName->text(),
            DOB = ui->deDOB->text();
    int team_id = ui->cbTeam->itemData(ui->cbTeam->currentIndex()).toInt(),
        sex_id = ui->cbSex->itemData(ui->cbSex->currentIndex()).toInt(),
        qualification_id = ui->cbQualification->itemData(ui->cbQualification->currentIndex()).toInt();


    if (!query.exec(QString("INSERT INTO surveyed (team_id,name,sex_id,qualification_id,DOB) VALUES (%1,'%2',%3,%4,'%5')").arg(team_id).arg(name).arg(sex_id).arg(qualification_id).arg(DOB)))
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);

    QDialog::accept();
}

void SurveyedCreateDialog::setupForm(void)
{
    QSqlQuery query;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    // Инициализируем список команд
    if (!query.exec("SELECT * FROM team"))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        QDialog::close();
        return;
    }
    while (query.next())
        ui->cbTeam->addItem(query.value(1).toString(),query.value(0).toInt());
    ui->cbTeam->setCurrentIndex(-1);

    // Инициализируем список полов
    if (!query.exec("SELECT * FROM sex"))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        QDialog::close();
        return;
    }
    while (query.next())
        ui->cbSex->addItem(query.value(1).toString(),query.value(0).toInt());
//    ui->cbSex->setCurrentIndex(-1);

    // Инициализируем список квалификаций
    if (!query.exec("SELECT * FROM qualification"))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        QDialog::close();
        return;
    }
    while (query.next())
        ui->cbQualification->addItem(query.value(1).toString(),query.value(0).toInt());
//    ui->cbQualification->setCurrentIndex(-1);
}
