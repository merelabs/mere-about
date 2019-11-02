#include "mereaboutapp.h"
#include "mereaboutwin.h"

#include "mere/utils/merei18nutils.h"

#include <QFileInfo>
#include <QLocale>

MereAboutApp::~MereAboutApp()
{
    if (m_win)
    {
        delete m_win;
        m_win = nullptr;
    }
}

MereAboutApp::MereAboutApp(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setApplicationName(Mere::About::AppName);
    setApplicationVersion(Mere::About::AppVersion);

    setObjectName("MereAboutApp");

    // Apply Styles
    QFile File(":/about/about.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    setStyleSheet(StyleSheet);

    // Apply I18n
    bool ok = MereI18nUtils::apply(&m_translator);
    if (ok)
        qDebug() << "WARN: failed to apply i18n support!";

    m_win = new MereAboutWin();
}

void MereAboutApp::init()
{
    m_win->init();
}

void MereAboutApp::start()
{
    m_win->show();
}
