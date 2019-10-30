QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mere-about
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        src/main.cpp \
        src/mereaboutapp.cpp \
        src/mereaboutwin.cpp

HEADERS += \
        src/mereaboutapp.h \
        src/mereaboutwin.h

RESOURCES += \
    res/about.qrc

#
# Install
#
unix{
    target.path = /usr/local/bin
    INSTALLS += target
}


