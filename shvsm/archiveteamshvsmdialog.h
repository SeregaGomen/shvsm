#ifndef ARCHIVETEAMSHVSMDIALOG_H
#define ARCHIVETEAMSHVSMDIALOG_H

#include <QDialog>
#include <QItemDelegate>

namespace Ui {
class ArchiveTeamSHVSMDialog;
}



class QSqlDatabase;
class QSqlQueryModel;
class QItemSelection;
class ArchiveTeamSHVSMDialog;


class ColorDelegateSHVSM : public QItemDelegate
{
    Q_OBJECT
private:
    ArchiveTeamSHVSMDialog* ptr;
public:
    ColorDelegateSHVSM(ArchiveTeamSHVSMDialog* p,QWidget *parent = 0) : QItemDelegate(parent)
    {
        ptr = p;
    }
    void paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const;
};


class ArchiveTeamSHVSMDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveTeamSHVSMDialog(QSqlDatabase*,QWidget *parent = 0);
    ~ArchiveTeamSHVSMDialog();
    void changeLanguage(void);
    QColor getIndicatorColor(float,float,float,float,float);

private slots:
    void slotSelectionChangedTeam(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedSurveyed(const QItemSelection&, const QItemSelection&);
    void slotSelectionChangedDate(const QItemSelection&, const QItemSelection&);

private:
    Ui::ArchiveTeamSHVSMDialog *ui;
    QSqlDatabase* db;
    QSqlQueryModel* modelTeam;
    QSqlQueryModel* modelDate;
    QSqlQueryModel* modelSurveyed;
    QString dt;
    int team_id;
    bool isSportsmen;
    void setupForm(void);
};

#endif // ARCHIVETEAMSHVSMDIALOG_H
