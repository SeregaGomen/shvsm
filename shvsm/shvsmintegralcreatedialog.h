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
    void juniorSOK(float);
    void juniorMOK(float);
    void juniorOPSS(float);
    void juniorVC(float);
    void juniorIR(float);
    void juniorKEK(float);
    void juniorIG(float);
    void juniorIS(float);
    float jSOK(float);
    float jMOK(float);
    float jVC(float);
    float jOPSS(float);
    float jKEK(float);
    float jGEL(float);
    float jIG(float);
    float jIS(float);
    float jDTE(float);
    float jDTBE(float);
};

#endif // SHVSMINTEGRALCREATEDIALOG_H
