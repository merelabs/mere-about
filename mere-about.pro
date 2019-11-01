QT      += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = mere-about
VERSION = 0.0.1b
TEMPLATE= app

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += APP_NAME=\\\"$$TARGET\\\"
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

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
# Generate TS file(s)
#
LANGUAGES = en bn
defineReplace(prependAll) {
    for(a, $$1): result += $$2$${a}$$3
    return($$result)
}
TRANSLATIONS = $$prependAll(LANGUAGES, i18n/mere-about_, .ts)
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

    i18n.path = /usr/local/share/mere/mere-about/i18n/
    i18n.files = i18n/*.qm

    desktop.path  = /usr/local/share/applications/
    desktop.files = mere-about.desktop

    INSTALLS += target i18n desktop
}


