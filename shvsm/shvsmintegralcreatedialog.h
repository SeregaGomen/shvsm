#ifndef SHVSMINTEGRALCREATEDIALOG_H
#define SHVSMINTEGRALCREATEDIALOG_H

#include <QDialog>

namespace Ui {
class SHVSMIntegralCreateDialog;
}

class QSqlDatabase;
class QSqlQueryModel;
class QLabel;

class SHVSMIntegralCreateDialog : public QDialog
{
    Q_OBJECT

public slots:
    void slotCalcSHVSMIntegral(void);
    void slotSaveSHVSMIntegral(void);

public:
    explicit SHVSMIntegralCreateDialog(QSqlDatabase*,QWidget *parent = 0);
    ~SHVSMIntegralCreateDialog();
    void changeLanguage(void);

private:
    Ui::SHVSMIntegralCreateDialog *ui;
    QSqlDatabase* db;
    QSqlQueryModel* model;
    int sex;
    bool isSportsman;
    float weight;
    float growth;
    float hr;
    float sbp;
    float dbp;
    float lvActual;
    float sok;
    float mok;
    float si;
    float opss;
    float vc;
    float kek;
    float ir;
    float oadc;
    float oadd;
    float dgel;
    float dev_dgel;
    float ig;
    float dte;
    float dtbe;
    float is;
    float ufss;
    float ufsvd;
    float old;
    void setupForm(void);
    void showIndicatorTxt(QLabel*,QLabel*,float,float,float,float,float);
    void showIndicatorTxtI(QLabel*,QLabel*,float,float,float,float,float);
};

#endif // SHVSMINTEGRALCREATEDIALOG_H
