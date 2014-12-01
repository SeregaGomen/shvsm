#ifndef ARCHIVESURVEYEDSHVSMDIALOG_H
#define ARCHIVESURVEYEDSHVSMDIALOG_H

#include <QDialog>
#include <QItemDelegate>


namespace Ui {
class ArchiveSurveyedSHVSMDialog;
}


class QSqlDatabase;
class QSqlQueryModel;
class QItemSelection;
class ArchiveSurveyedSHVSMDialog;
class QCPLegend;
class QCPAbstractLegendItem;


class ColorDelegateSurveyedSHVSM : public QItemDelegate
{
    Q_OBJECT
private:
    ArchiveSurveyedSHVSMDialog* ptr;
public:
    ColorDelegateSurveyedSHVSM(ArchiveSurveyedSHVSMDialog* p,QWidget *parent = 0) : QItemDelegate(parent)
    {
        ptr = p;
    }
    void paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const;
};


class ArchiveSurveyedSHVSMDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveSurveyedSHVSMDialog(QSqlDatabase*,QWidget *parent = 0);
    ~ArchiveSurveyedSHVSMDialog();
    void changeLanguage(void);
    QColor getIndicatorColor(float,float,float,float,float);

private slots:
    void slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedSurvey1(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedSurvey2(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedSurvey3(const QItemSelection&, const QItemSelection&);
    void selectionChanged(void);

private:
    Ui::ArchiveSurveyedSHVSMDialog *ui;
    QSqlDatabase* db;
    QSqlQueryModel* modelSurveyed;
    QSqlQueryModel* modelSurvey;
    int surveyedId;
    int currentRow;
    void setupForm(void);
    void scrollView(void);
    void rePlot(void);
};

#endif // ARCHIVESURVEYEDSHVSMDIALOG_H
