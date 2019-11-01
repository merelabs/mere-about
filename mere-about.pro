QT      += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET  = mere-about
TEMPLATE= app

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

#TRANSLATIONS += \
#    i18n/mere-about_bn.ts \
#    i18n/mere-about_en.ts

#DISTFILES += \
#    i18n/mere-about_bn.ts \
#    i18n/mere-about_en.ts
#    README.md

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
    target.path = /usr/local/bin
    target.commands = @echo "Going to install target"

    i18n.path = /usr/local/share/mere/about/i18n
    i18n.files = i18n/*.qm
    i18n.commands = @echo "Going to copy i18n resources"

    desktop.path  = /usr/local/share/applications/
    desktop.files = mere-about.desktop
    desktop.commands = @echo "Going to copy desktop entity"

    INSTALLS += target i18n desktop
}


