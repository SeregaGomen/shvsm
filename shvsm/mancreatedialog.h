#ifndef MANCREATEDIALOG_H
#define MANCREATEDIALOG_H

#include <QDialog>

namespace Ui {
class ManCreateDialog;
}

class QSqlDatabase;


class ManCreateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManCreateDialog(QSqlDatabase*,QWidget *parent = 0);
    ~ManCreateDialog();
    void changeLanguage(void);
private:
    Ui::ManCreateDialog *ui;
    QSqlDatabase* db;
};

#endif // MANCREATEDIALOG_H
