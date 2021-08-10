QT      += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = mere-about
VERSION = 0.0.1b
TEMPLATE= app
VERSION= 0.0.1

DEFINES += APP_CODE=\\\"about\\\"
DEFINES += APP_NAME=\\\"$$TARGET\\\"
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
        src/main.cpp \
        src/aboutapp.cpp \
        src/aboutwin.cpp

HEADERS += \
        src/aboutapp.h \
        src/aboutwin.h

RESOURCES += \
    res/about.qrc

INCLUDEPATH += /usr/local/include

LIBS += -lmere-utils -lmere-widgets

TRANSLATIONS += \
    i18n/about_bn.ts \
    i18n/about_en.ts

##
## TS file(s)
##
qtPrepareTool(LUPDATE, lupdate)
command = $$LUPDATE mere-about.pro
system($$command)|error("Failed to run: $$command")


#
# Generate QM file(s) from TS file(s)
#
qtPrepareTool(LRELEASE, lrelease)
command = $$LRELEASE -removeidentical i18n/*.ts
system($$command)|error("Failed to run: $$command")

#
# Install
#
unix{
    target.path = /usr/local/bin/

#    i18n.path = /usr/local/share/mere/mere-about/i18n/
    i18n.path = /usr/local/share/mere/about/i18n
    i18n.files = i18n/*.qm

    desktop.path  = /usr/local/share/applications/
    desktop.files = mere-about.desktop

    INSTALLS += target i18n desktop
}
