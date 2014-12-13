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

void PrintReportDialog::setHTML(QString p)
{
    ui->webView->setHtml(p);
}
