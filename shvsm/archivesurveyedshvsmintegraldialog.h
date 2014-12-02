#ifndef ARCHIVESURVEYEDSHVSMINTEGRALDIALOG_H
#define ARCHIVESURVEYEDSHVSMINTEGRALDIALOG_H

#include <QDialog>
#include <QItemDelegate>

namespace Ui {
class ArchiveSurveyedSHVSMIntegralDialog;
}

class QSqlDatabase;
class QSqlQueryModel;
class QItemSelection;
class ArchiveSurveyedSHVSMIntegralDialog;


class ColorDelegateSurveyedSHVSMIntegral : public QItemDelegate
{
    Q_OBJECT
private:
    ArchiveSurveyedSHVSMIntegralDialog* ptr;
public:
    ColorDelegateSurveyedSHVSMIntegral(ArchiveSurveyedSHVSMIntegralDialog* p,QWidget *parent = 0) : QItemDelegate(parent)
    {
        ptr = p;
    }
    void paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const;
};

class ArchiveSurveyedSHVSMIntegralDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveSurveyedSHVSMIntegralDialog(QSqlDatabase*,QWidget *parent = 0);
    ~ArchiveSurveyedSHVSMIntegralDialog();
    void changeLanguage(void);
    QColor getIndicatorColor(float,float,float,float,float);

private slots:
    void slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedSurvey1(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedSurvey2(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedSurvey3(const QItemSelection&, const QItemSelection&);
    void selectionChanged(void);
    void contextMenuRequest(QPoint);
    void moveLegend(void);
    void shovGraph1(void);
    void shovGraph2(void);
    void shovLegend(void);

private:
    Ui::ArchiveSurveyedSHVSMIntegralDialog *ui;
    QSqlDatabase* db;
    QSqlQueryModel* modelSurveyed;
    QSqlQueryModel* modelSurvey;
    bool isLegend;
    bool isGraph[2];
    int surveyedId;
    int currentRow;
    void setupForm(void);
    void scrollView(void);
    void rePlot(void);
};

#endif // ARCHIVESURVEYEDSHVSMINTEGRALDIALOG_H
