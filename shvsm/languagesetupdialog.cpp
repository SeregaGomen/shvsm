#include "languagesetupdialog.h"
#include "ui_languagesetupdialog.h"

LanguageSetupDialog::LanguageSetupDialog(int lang,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LanguageSetupDialog)
{
    ui->setupUi(this);
    switch (lang)
    {
        case 1:
            ui->rbRU->setChecked(true);
            break;
        case 2:
            ui->rbUA->setChecked(true);
            break;
        default:
            ui->rbEN->setChecked(true);
    }
}

LanguageSetupDialog::~LanguageSetupDialog()
{
    delete ui;
}

void LanguageSetupDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}

int LanguageSetupDialog::getLangNo(void)
{
    if (ui->rbEN->isChecked())
        return 0;
    else if (ui->rbRU->isChecked())
        return 1;
    return 2;
}
