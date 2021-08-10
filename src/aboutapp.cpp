#include "aboutapp.h"
#include "aboutwin.h"

#include "mere/utils/apputils.h"
#include "mere/utils/i18nutils.h"

AboutApp::~AboutApp()
{
    if (m_win)
    {
        delete m_win;
        m_win = nullptr;
    }
}

AboutApp::AboutApp(int &argc, char **argv)
    : Mere::Widgets::DefaultApp(argc, argv)
{
    setObjectName("AboutApp");

    Mere::Utils::AppUtils::setAppCode(Mere::About::AppCode.toStdString());
    setApplicationName(Mere::About::AppName);
    setApplicationVersion(Mere::About::AppVersion);

    Mere::Utils::I18nUtils::apply();

    m_win = new AboutWin();
}

int AboutApp::init()
{
    m_win->init();

    return 0;
}

void AboutApp::start()
{
    m_win->show();
}
