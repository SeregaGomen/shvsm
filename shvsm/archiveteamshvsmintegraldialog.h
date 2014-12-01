#ifndef ARCHIVETEAMSHVSMINTEGRALDIALOG_H
#define ARCHIVETEAMSHVSMINTEGRALDIALOG_H

#include <QDialog>
#include <QItemDelegate>

namespace Ui {
class ArchiveTeamSHVSMIntegralDialog;
}

class QSqlDatabase;
class QSqlQueryModel;
class QItemSelection;
class ArchiveTeamSHVSMIntegralDialog;


class ColorDelegateSHVSMIntegral : public QItemDelegate
{
    Q_OBJECT
private:
    ArchiveTeamSHVSMIntegralDialog* ptr;
public:
    ColorDelegateSHVSMIntegral(ArchiveTeamSHVSMIntegralDialog* p,QWidget *parent = 0) : QItemDelegate(parent)
    {
        ptr = p;
    }
    void paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const;
};

class ArchiveTeamSHVSMIntegralDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveTeamSHVSMIntegralDialog(QSqlDatabase*,QWidget *parent = 0);
    ~ArchiveTeamSHVSMIntegralDialog();
    void changeLanguage(void);
    QColor getIndicatorColor(float,float,float,float,float);

private slots:
    void slotSelectionChangedTeam(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedDate(const QItemSelection&, const QItemSelection&);

private:
    Ui::ArchiveTeamSHVSMIntegralDialog *ui;
    QSqlDatabase* db;
    QSqlQueryModel* modelTeam;
    QSqlQueryModel* modelDate;
    QSqlQueryModel* modelSurveyed;
    QString dt;
    int team_id;
    bool isSportsmen;
    void setupForm(void);
};

#endif // ARCHIVETEAMSHVSMINTEGRALDIALOG_H
