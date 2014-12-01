#include "mancreatedialog.h"
#include "ui_mancreatedialog.h"

ManCreateDialog::ManCreateDialog(QSqlDatabase* pdb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManCreateDialog)
{
    ui->setupUi(this);
    db = pdb;
}

ManCreateDialog::~ManCreateDialog()
{
    delete ui;
}

void ManCreateDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}
