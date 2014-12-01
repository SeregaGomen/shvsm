#ifndef TEAMCREATEDIALOG_H
#define TEAMCREATEDIALOG_H

#include <QDialog>

namespace Ui {
class TeamCreateDialog;
}


class QSqlDatabase;

class TeamCreateDialog : public QDialog
{
    Q_OBJECT

public slots:
    void slotTextChanged(void);

public:
    explicit TeamCreateDialog(QSqlDatabase*, QWidget *parent = 0);
    ~TeamCreateDialog();
    void changeLanguage(void);

protected:
    void accept(void);

private:
    Ui::TeamCreateDialog *ui;
    QSqlDatabase* db;
};

#endif // TEAMCREATEDIALOG_H
