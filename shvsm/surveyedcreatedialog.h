#ifndef SURVEYEDCREATEDIALOG_H
#define SURVEYEDCREATEDIALOG_H

#include <QDialog>

namespace Ui {
class SurveyedCreateDialog;
}

class QSqlDatabase;

class SurveyedCreateDialog : public QDialog
{
    Q_OBJECT

public slots:
    void slotTextChanged(void);

public:
    explicit SurveyedCreateDialog(QSqlDatabase*,QWidget *parent = 0);
    ~SurveyedCreateDialog();
    void changeLanguage(void);
protected:
    void accept(void);
private:
    Ui::SurveyedCreateDialog *ui;
    QSqlDatabase* db;
    void setupForm(void);
};

#endif // SURVEYEDCREATEDIALOG_H
