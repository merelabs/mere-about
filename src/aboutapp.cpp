#include "aboutapp.h"
#include "aboutwin.h"

#include "mere/utils/apputils.h"
#include "mere/utils/i18nutils.h"

#include <QThread>
#include <QFileInfo>
#include <QLocale>

AboutApp::~AboutApp()
{
    if (m_win)
    {
        delete m_win;
        m_win = nullptr;
    }
}

AboutApp::AboutApp(int &argc, char **argv)
    : QApplication(argc, argv)
{
    setObjectName("MereAboutApp");

    Mere::Utils::AppUtils::setAppCode(Mere::About::AppCode);
    setApplicationName(Mere::About::AppName);
    setApplicationVersion(Mere::About::AppVersion);

    // Apply Styles
    QFile File(":/about/about.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    setStyleSheet(StyleSheet);

    Mere::Utils::I18nUtils::apply();

    m_win = new AboutWin();
}

void AboutApp::init()
{
    m_win->init();
}

void AboutApp::start()
{
    m_win->show();
}
