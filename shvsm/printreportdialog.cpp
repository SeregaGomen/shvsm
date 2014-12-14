#include <QPrinter>
#include <QPrintDialog>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "printreportdialog.h"
#include "ui_printreportdialog.h"

extern int langNo;


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

void PrintReportDialog::setHint(void)
{
    QString fileName,
            data;
    QFile file;
    QTextStream in;

    setWindowTitle(tr("Hint"));
    switch (langNo)
    {
        case 0: // English
            fileName = "shvsm_hint_EN.html";
            break;
        case 1: // Russian
            fileName = "shvsm_hint_RU.html";
            break;
        case 2: // Ukrainian
            fileName = "shvsm_hint_UA.html";
            break;
    }
    file.setFileName(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        in.setDevice(&file);
        data = in.readAll();
        ui->textEdit->setText(data);
    }
}
