#ifndef SHVSMCREATEDIALOG_H
#define SHVSMCREATEDIALOG_H

#include <QDialog>

namespace Ui {
class SHVSMCreateDialog;
}

class QSqlDatabase;
class QSqlQueryModel;
class QLabel;
class PrintReportDialog;

class SHVSMCreateDialog : public QDialog
{
    Q_OBJECT

public slots:
    void slotCalcSHVSM(void);
    void slotSaveSHVSM(void);
    void slotCheckBoxClicked(void);
    void slotTextChanged(void);
    void slotPrintReport(void);

public:
    explicit SHVSMCreateDialog(QSqlDatabase*,QWidget *parent = 0);
    ~SHVSMCreateDialog();
    void changeLanguage(void);


private:
    Ui::SHVSMCreateDialog *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
    bool isSportsman;
    int sex;
    float weight;
    float growth;
    float N1;
    float N2;
    float n1;
    float n2;
    float hr1;
    float hr2;
    float apwc170;
    float opwc170;
    float ampk;
    float ompk;
    float alakm;
    float alake;
    float lakm;
    float lake;
    float panof;
    float pano;
    float chsspano;
    float ome;
    float ufp;
    float old;
    void setupForm(void);
    void showIndicator(QLabel*,float,float,float,float,float);
    void showIndicatorTxt(QLabel*,QLabel*,float);
    void calcNn12(void);
    void genReport(PrintReportDialog*);
    QString getIndicatorTxt(QLabel*);
};

#endif // SHVSMCREATEDIALOG_H
