#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class QTranslator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void slotCreateTieam(void);
    void slotCreateSurveyed(void);
    void slotCreateSHVSM(void);
    void slotCreateSHVSMIntegral(void);
    void slotArchiveTeamSHVSMIntegral(void);
    void slotArchiveTeamSHVSM(void);
    void slotArchiveSurveyedSHVSMIntegral(void);
    void slotArchiveSurveyedSHVSM(void);
    void slotChangeLanguage(void);
    void slotAboutProgram(void);
    void slotAboutAutors(void);
    void slotArchiveTeam(void);
    void slotArchiveSurveyed(void);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changeLanguage(void);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QTranslator* translator;
    void readSettings(void);
    void writeSettings(void);
    void openDB(void);
    void closeDB(void);
    void setupLanguage(void);
    bool checkDB(QString);
    bool createDB(QString);
};

#endif // MAINWINDOW_H
