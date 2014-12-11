#include <QSqlError>
#include <QDebug>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QTextCodec>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSettings>
#include <QCloseEvent>
#include "mainwindow.h"
#include "teamcreatedialog.h"
#include "surveyedcreatedialog.h"
#include "shvsmcreatedialog.h"
#include "shvsmintegralcreatedialog.h"
#include "languagesetupdialog.h"
#include "aboutdialog.h"
#include "archiveteamshvsmintegraldialog.h"
#include "archiveteamshvsmdialog.h"
#include "archivesurveyedshvsmdialog.h"
#include "archivesurveyedshvsmintegraldialog.h"
#include "archivetabledialog.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    langNo = 0; // Английский по умолчанию
    readSettings();
    setupLanguage();
    openDB();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete translator;
}

void MainWindow::changeLanguage(void)
{
    ui->retranslateUi(this);
}

void MainWindow::readSettings(void)
{
    QSettings settings("ZNU","SHVSM");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    QString path = settings.value("path").toString();
    int states = settings.value("state").toInt();

    langNo = settings.value("lang").toInt();
    if ((Qt::WindowStates)states == Qt::WindowMaximized)
        this->setWindowState(Qt::WindowMaximized);
    else
    {
        move(pos);
        resize(size);
    }
    setWindowFilePath(path);
}

void MainWindow::writeSettings(void)
{
    QSettings settings("ZNU","SHVSM");

    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("path",windowFilePath());
    settings.setValue("state",(int)windowState());
    settings.setValue("lang",langNo);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    closeDB();
    writeSettings();
    event->accept();
}

bool MainWindow::checkDB(QString fileName)
{
    return QFile::exists(fileName);
}

bool MainWindow::createDB(QString fileName)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(fileName);
    setCursor(Qt::WaitCursor);
    if (!db.open())
    {
        setCursor(Qt::ArrowCursor);
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        return false;
    }
    setCursor(Qt::ArrowCursor);

    QSqlQuery query;

    // Создание таблиц
    // Sex
    if (!query.exec(QString("CREATE TABLE sex (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, name	TEXT)")))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    if (!query.exec(QString("INSERT INTO sex (name) VALUES ('%1')").arg(tr("Man"))))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    if (!query.exec(QString("INSERT INTO sex (name) VALUES ('%1')").arg(tr("Woman"))))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    // Qualification
    if (!query.exec(QString("CREATE TABLE qualification (id	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,name	TEXT)")))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    if (!query.exec(QString("INSERT INTO qualification (name) VALUES ('%1')").arg(tr("Athlete"))))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    if (!query.exec(QString("INSERT INTO qualification (name) VALUES ('%1')").arg(tr("Non-athlete"))))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    // Team
    if (!query.exec(QString("CREATE TABLE team (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, name TEXT )")))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    // Surveyed
    if (!query.exec(QString("CREATE TABLE surveyed (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,name TEXT, sex_id INTEGER NOT NULL, team_id INTEGER, qualification_id INTEGER NOT NULL,DOB TEXT NOT NULL)")))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    // SurveySHVSM
    if (!query.exec(QString("CREATE TABLE surveySHVSM (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, surveyed_id INTEGER NOT NULL, dt TEXT, weight INTEGER, growth INTEGER, N1 REAL, N2 REAL, n_1 REAL, n_2 REAL, HR1 INTEGER, HR2 INTEGER, aPWC170 REAL, oPWC170 REAL, aMPK REAL, oMPK REAL, ALAKm REAL, ALAKe REAL, LAKm REAL, LAKe REAL, PANO REAL, CHSSpano REAL, OME REAL, TE REAL, SE REAL, SPE REAL, SPS REAL, RP REAL, UFP REAL, old INTEGER )")))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }
    // SurveySHVSMIntegral
    if (!query.exec(QString("CREATE TABLE surveySHVSMIntegral (id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, surveyed_id INTEGER NOT NULL, dt TEXT, weight INTEGER, growth INTEGER, HR NUMERIC, SAD REAL, DAD REAL, VL NUMERIC, VLN NUMERIC, VLD NUMERIC, T1 NUMERIC, T2 REAL, V1 REAL, V2 REAL, V3 REAL, V4 REAL, V5 REAL, V6 REAL, V7 REAL, V8 REAL, V9 REAL, V10 REAL, V11 REAL, V12 REAL, V13 REAL, old INTEGER)")))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        qDebug() << db.lastError();
        db.close();
        return false;
    }

    db.close();
    return true;
}

void MainWindow::openDB(void)
{
    // Проверка наличия БД
    if (!checkDB("shvsm.db"))
        if (!createDB("shvsm.db"))
            return;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("shvsm.db");

    setCursor(Qt::WaitCursor);
    if (!db.open())
    {
        setCursor(Qt::ArrowCursor);
        QMessageBox::critical(this, tr("Error"),tr("Error opening database!"), QMessageBox::Ok);
        return;
    }
    setCursor(Qt::ArrowCursor);
}

void MainWindow::closeDB(void)
{
    db.close();
}

void MainWindow::slotCreateTieam(void)
{
    TeamCreateDialog* dlg = new TeamCreateDialog(&db,this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotCreateSurveyed(void)
{
    SurveyedCreateDialog* dlg = new SurveyedCreateDialog(&db,this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotCreateSHVSM(void)
{
    SHVSMCreateDialog* dlg = new SHVSMCreateDialog(&db,this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotCreateSHVSMIntegral(void)
{
    SHVSMIntegralCreateDialog* dlg = new SHVSMIntegralCreateDialog(&db,this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotChangeLanguage(void)
{
    LanguageSetupDialog* dlg = new LanguageSetupDialog(langNo,this);

    dlg->changeLanguage();
    if (dlg->exec() != QDialog::Accepted)
        return;

    switch ((langNo = dlg->getLangNo()))
    {
        case 0: // English
            qApp->removeTranslator(translator);
            break;
        case 1: // Russian
            translator->load("shvsm_RU");
            qApp->installTranslator(translator);
            break;
        case 2: // Ukrainian
            translator->load("shvsm_UA");
            qApp->installTranslator(translator);
            break;
    }
    changeLanguage();
}

void MainWindow::setupLanguage(void)
{
    QString translatorFileName = QLatin1String("qt_") + QLocale::system().name(),
            translatorFile;
    QTranslator* dlgTranslator = new QTranslator(qApp);

    // Локализация (стандартных диалогов, e.t.c, ...)
    if (dlgTranslator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        qApp->installTranslator(dlgTranslator);

    translator = new QTranslator(qApp);
    // Перевод на указанный язык
    switch (langNo)
    {
        case 0: // English
            translatorFile = "";
            break;
        case 1: // Russian
            translatorFile = "shvsm_RU";
            break;
        case 2: // Ukrainian
            translatorFile = "shvsm_UA";
            break;
    }

    if (translator->load(translatorFile))
    {
        qApp->installTranslator(translator);
        changeLanguage();
    }
}

void MainWindow::slotAboutProgram(void)
{
    AboutDialog* dlg = new AboutDialog(this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotArchiveTeamSHVSMIntegral(void)
{
    ArchiveTeamSHVSMIntegralDialog* dlg = new ArchiveTeamSHVSMIntegralDialog(&db,this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotArchiveTeamSHVSM(void)
{
    ArchiveTeamSHVSMDialog* dlg = new ArchiveTeamSHVSMDialog(&db,this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotArchiveSurveyedSHVSMIntegral(void)
{
    ArchiveSurveyedSHVSMIntegralDialog* dlg = new ArchiveSurveyedSHVSMIntegralDialog(&db,this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotArchiveSurveyedSHVSM(void)
{
    ArchiveSurveyedSHVSMDialog* dlg = new ArchiveSurveyedSHVSMDialog(&db,this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotArchiveTeam(void)
{
    ArchiveTableDialog* dlg = new ArchiveTableDialog(&db,"team",this);

    dlg->changeLanguage();
    dlg->exec();
}

void MainWindow::slotArchiveSurveyed(void)
{
    ArchiveTableDialog* dlg = new ArchiveTableDialog(&db,"surveyed",this);

    dlg->changeLanguage();
    dlg->exec();
}
