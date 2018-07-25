QT += core gui
QT += widgets
qt += multimedia
TARGET = TerrisBox
TEMPLATE = app

SOURCES += main.cpp\
        MainWindow.cpp \
    TestTools.cpp \
    Transform.cpp \
    Scores.cpp \
    Display.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui

OTHER_FILES +=

RESOURCES += \
    bg.qrc
