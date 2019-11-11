#include "mereaboutapp.h"
#include "mereaboutwin.h"

#include "mere/utils/mereapputils.h"
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
    setObjectName("MereAboutApp");

    MereAppUtils::setAppCode(Mere::About::AppCode);
    setApplicationName(Mere::About::AppName);
    setApplicationVersion(Mere::About::AppVersion);

    // Apply Styles
    QFile File(":/about/about.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    setStyleSheet(StyleSheet);

    MereI18nUtils::apply();

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
