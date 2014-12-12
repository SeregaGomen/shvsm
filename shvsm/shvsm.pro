#-------------------------------------------------
#
# Project created by QtCreator 2014-11-07T09:19:24
#
#-------------------------------------------------

QT       += core sql gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shvsm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    teamcreatedialog.cpp \
    surveyedcreatedialog.cpp \
    shvsmcreatedialog.cpp \
    shvsmintegralcreatedialog.cpp \
    languagesetupdialog.cpp \
    aboutdialog.cpp \
    archiveteamshvsmintegraldialog.cpp \
    archiveteamshvsmdialog.cpp \
    archivesurveyedshvsmdialog.cpp \
    archivesurveyedshvsmintegraldialog.cpp \
    archivetabledialog.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    teamcreatedialog.h \
    surveyedcreatedialog.h \
    shvsmcreatedialog.h \
    shvsmintegralcreatedialog.h \
    languagesetupdialog.h \
    aboutdialog.h \
    archiveteamshvsmintegraldialog.h \
    archiveteamshvsmdialog.h \
    archivesurveyedshvsmdialog.h \
    archivesurveyedshvsmintegraldialog.h \
    archivetabledialog.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    teamcreatedialog.ui \
    surveyedcreatedialog.ui \
    shvsmcreatedialog.ui \
    shvsmintegralcreatedialog.ui \
    languagesetupdialog.ui \
    aboutdialog.ui \
    archiveteamshvsmintegraldialog.ui \
    archiveteamshvsmdialog.ui \
    archivesurveyedshvsmdialog.ui \
    archivesurveyedshvsmintegraldialog.ui \
    archivetabledialog.ui

TRANSLATIONS += shvsm_RU.ts

RESOURCES += \
    shvsm.qrc

win32 {

    RC_FILE += shvsm.rc
}

OTHER_FILES += \
    shvsm_UA.ts \
    shvsm_RU.ts
