#ifndef LANGUAGESETUPDIALOG_H
#define LANGUAGESETUPDIALOG_H

#include <QDialog>

namespace Ui {
class LanguageSetupDialog;
}

class LanguageSetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LanguageSetupDialog(int,QWidget *parent = 0);
    ~LanguageSetupDialog();
    void changeLanguage(void);
    int getLangNo(void);

private:
    Ui::LanguageSetupDialog *ui;
};

#endif // LANGUAGESETUPDIALOG_H
