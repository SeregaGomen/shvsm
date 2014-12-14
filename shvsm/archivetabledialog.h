#ifndef ARCHIVETABLEDIALOG_H
#define ARCHIVETABLEDIALOG_H

#include <QDialog>

namespace Ui {
class ArchiveTableDialog;
}

class QSqlDatabase;
class QSqlRelationalTableModel;
class QModelIndex;

class ArchiveTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArchiveTableDialog(QSqlDatabase*,QString,QWidget *parent = 0);
    ~ArchiveTableDialog();
    void changeLanguage(void);

public slots:
    void slotAddRow(void);
    void slotDelRow(void);
    void slotSaveChanges(void);
    void slotCancelChanges(void);

protected:
    virtual void showEvent(QShowEvent*);

private slots:
    void slotOnDataChanged(const QModelIndex&, const QModelIndex&);

private:
    Ui::ArchiveTableDialog *ui;
    QSqlDatabase* db;
    QSqlRelationalTableModel* model;
    QString tableName;
    bool isDataChanged;
    void setupForm(void);
    void checkButtons(void);
    void cascadeRemove(int);
};

#endif // ARCHIVETABLEDIALOG_H
