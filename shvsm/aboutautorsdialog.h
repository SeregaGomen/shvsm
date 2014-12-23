#ifndef ABOUTAUTORSDIALOG_H
#define ABOUTAUTORSDIALOG_H

#include <QDialog>

namespace Ui {
class AboutAutorsDialog;
}

class AboutAutorsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutAutorsDialog(QWidget *parent = 0);
    ~AboutAutorsDialog();

private:
    Ui::AboutAutorsDialog *ui;
};

#endif // ABOUTAUTORSDIALOG_H
