#include <QPrinter>
#include <QPrintDialog>
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
    ui->textEdit->setText(p);
}

void PrintReportDialog::slotPrint(void)
{
    QPrinter printer;
    QPrintDialog* dialog = new QPrintDialog(&printer, this);

    dialog->setWindowTitle(tr("Print Report"));
    if (ui->textEdit->textCursor().hasSelection())
        dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if (dialog->exec() != QDialog::Accepted)
        return;

    ui->textEdit->print(&printer);
}
