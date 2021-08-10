QT      += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = mere-about
TEMPLATE= app

DEFINES += APP_CODE=\\\"about\\\"
DEFINES += APP_NAME=\\\"$$TARGET\\\"
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += QT_DEPRECATED_WARNINGS

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

LIBS += -lmere-utils

TRANSLATIONS += \
    i18n/about_bn.ts \
    i18n/about_en.ts

#DISTFILES += \
#    i18n/mere-about_bn.ts \
#    i18n/mere-about_en.ts
#    README.md

#
# Generate TS file
#
#LANGUAGES = en bn
#defineReplace(prependAll) {
#    for(a, $$1): result += $$2$${a}$$3
#    return($$result)
#}
#TRANSLATIONS = $$prependAll(LANGUAGES, i18n/about_, .ts)
qtPrepareTool(LUPDATE, lupdate)
command = $$LUPDATE mere-about.pro
system($$command)|error("Failed to run: $$command")

##
## Generate QM file from TS file, and
## Copy to the resource bundle
##
#TRANSLATIONS_FILES =
#qtPrepareTool(LRELEASE, lrelease)
#for(tsfile, TRANSLATIONS) {
#    qmfile = $$tsfile
#    qmfile ~= s,mere-,
#    qmfile ~= s,.ts,.qm

#    command = $$LRELEASE -removeidentical $$tsfile -qm $$qmfile
#    system($$command)|error("Failed to run: $$command")
#    TRANSLATIONS_FILES += $$qmfile
#}

#
# Install
#
unix{
    i18n.path = /usr/local/share/mere/about/i18n
    i18n.files = $$TRANSLATIONS_FILES
    INSTALLS += i18n

    target.path = /usr/local/bin
    INSTALLS += target
}


