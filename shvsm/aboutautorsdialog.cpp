#include "aboutautorsdialog.h"
#include "ui_aboutautorsdialog.h"

AboutAutorsDialog::AboutAutorsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutAutorsDialog)
{
    ui->setupUi(this);
}

AboutAutorsDialog::~AboutAutorsDialog()
{
    delete ui;
}
