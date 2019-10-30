#include "mereaboutapp.h"
#include "mereaboutwin.h"

#include <QFile>

MereAboutApp::~MereAboutApp()
{
    if (m_win)
    {
        delete m_win;
        m_win = nullptr;
    }
}

MereAboutApp::MereAboutApp(int &argc, char **argv)
    : QApplication(argc, argv),
      m_win(new MereAboutWin)
{
    QFile File(":/about/about.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());

    setStyleSheet(StyleSheet);
}

void MereAboutApp::init()
{
    m_win->init();
}

void MereAboutApp::start()
{
    m_win->show();
}

