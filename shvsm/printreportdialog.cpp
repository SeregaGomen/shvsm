#include "printreportdialog.h"
#include "ui_printreportdialog.h"

PrintReportDialog::PrintReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintReportDialog)
{
    ui->setupUi(this);
}

PrintReportDialog::~PrintReportDialog()
{
    delete ui;
}

void PrintReportDialog::setText(QString p)
{
//    ui->webView->setHtml(p);
    ui->textEdit->setText(p);
}
