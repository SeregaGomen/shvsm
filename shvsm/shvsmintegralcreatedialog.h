#ifndef SHVSMINTEGRALCREATEDIALOG_H
#define SHVSMINTEGRALCREATEDIALOG_H

#include <QDialog>

namespace Ui {
class SHVSMIntegralCreateDialog;
}

class QSqlDatabase;
class QSqlQueryModel;
class QLabel;
class PrintReportDialog;


class SHVSMIntegralCreateDialog : public QDialog
{
    Q_OBJECT

public slots:
    void slotCalcSHVSMIntegral(void);
    void slotSaveSHVSMIntegral(void);
    void slotPrintReport(void);
    void slotClear(void);

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
    float p_sok;
    float p_mok;
    float p_oadc;
    float p_oadd;
    float p_vc;
    float p_opss;
    float p_ir;
    float p_kek;
    float p_si;
    float p_dgel;
    float p_ig;
    float p_is;
    float p_dte;
    float p_dtbe;
    float p_dev_dgel;
    void setupForm(void);
    void showIndicatorTxt(QLabel*,QLabel*,float,float,float,float,float);
    void showIndicatorTxtI(QLabel*,QLabel*,float,float,float,float,float);
    void genReport(PrintReportDialog*);
    void SOK(float);
    void MOK(float);
    void OPSS(float);
    void VC(float);
    void IR(float);
    void KEK(float);
    void IG(float);
    void IS(float);
    float nSOK(float);
    float nMOK(float);
    float nVC(float);
    float nOPSS(float);
    float nKEK(float);
    float nGEL(float);
    float nIG(float);
    float nIS(float);
    float nDTE(float);
    float nDTBE(float);
    float nOADD(float);
    float nOADC(float);
    float nIR(float);
    float nSI(float);
    float nDEV_GEL(float);
};

#endif // SHVSMINTEGRALCREATEDIALOG_H
