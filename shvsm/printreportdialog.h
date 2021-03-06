#ifndef PRINTREPORTDIALOG_H
#define PRINTREPORTDIALOG_H

#include <QDialog>

namespace Ui {
class PrintReportDialog;
}

class PrintReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrintReportDialog(QWidget *parent = 0);
    ~PrintReportDialog();
    void setText(QString);
    void setHint(void);

private slots:
    void slotPrint(void);
    void slotSaveAs(void);

private:
    Ui::PrintReportDialog *ui;
};

#endif // PRINTREPORTDIALOG_H
