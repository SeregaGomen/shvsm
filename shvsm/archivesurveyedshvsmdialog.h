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
    QColor getIndicatorColor(int,float);

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
    void shovGraph3(void);
    void shovGraph4(void);
    void shovGraph5(void);
    void shovGraph6(void);
    void shovLegend(void);

private:
    Ui::ArchiveSurveyedSHVSMDialog *ui;
    QSqlDatabase* db;
    QSqlQueryModel* modelSurveyed;
    QSqlQueryModel* modelSurvey;
    bool isLegend;
    bool isGraph[6];
    int surveyedId;
    int currentRow;
    void setupForm(void);
    void scrollView(void);
    void rePlot(void);
    int old;
    int sex;
    bool isSportsman;
};

#endif // ARCHIVESURVEYEDSHVSMDIALOG_H
