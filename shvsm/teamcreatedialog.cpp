#include <QPushButton>
#include <QSqlQuery>
#include <QMessageBox>
#include "teamcreatedialog.h"
#include "ui_teamcreatedialog.h"

TeamCreateDialog::TeamCreateDialog(QSqlDatabase* pdb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamCreateDialog)
{
    ui->setupUi(this);
    db = pdb;
    ui->lineEdit->setFocus();
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

TeamCreateDialog::~TeamCreateDialog()
{
    delete ui;
}

void TeamCreateDialog::slotTextChanged(void)
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled((ui->lineEdit->text().length()) ? true : false);
}

void TeamCreateDialog::accept(void)
{
    QSqlQuery query;



    // Проверка наличия такой команды
    if (!query.exec(QString("SELECT * FROM team WHERE name = '%1'").arg(ui->lineEdit->text())))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
        QDialog::reject();
    }
    if (query.next())
    {
        QMessageBox::critical(this,tr("Error"), tr("This team is already there!"), QMessageBox::Ok);
        return;
    }
    if (!query.exec(QString("INSERT INTO team (name) VALUES ('%1')").arg(ui->lineEdit->text())))
        QMessageBox::critical(this, tr("Error"),tr("Error accessing to database!"), QMessageBox::Ok);
    QDialog::accept();
}

void TeamCreateDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}

