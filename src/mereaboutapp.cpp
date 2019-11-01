#include "mereaboutapp.h"
#include "mereaboutwin.h"

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
    QCoreApplication::setApplicationName(Mere::About::AppName);
    QCoreApplication::setApplicationVersion(Mere::About::AppVersion);

    setObjectName("MereAboutApp");



    // Apply Styles
    QFile File(":/about/about.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    setStyleSheet(StyleSheet);

    // Apply I18n
    // moved the functionality to I18nUtils
    // I18nUtils::apply();
    // I18nUtils::apply(locale, default);
    {
        QString pattern = "/usr/local/share/mere/mere-about/i18n/mere-about_%1.qm";

        QLocale locale = QLocale::system();
        QString path = pattern.arg(locale.name());

        QFileInfo file(path);
        if (!file.exists())
        {
            qDebug() << QString("WARN: Failed to load i18n resource file for locale - %1").arg(path);

            // FALLBACK!
            {
                QStringList paths;
                paths << pattern.arg(locale.languageToString(locale.language()))
                      << pattern.arg("en_US")
                      << pattern.arg("en");

                QStringListIterator it(paths);
                while (it.hasNext())
                {
                    path = it.next();
                    file.setFile(path);
                    if (file.exists()) break;
                    qDebug() << QString("WARN: Failed to load i18n resource file for fallback - %1").arg(file.absoluteFilePath()) << file.exists();
                }
            }
        }

        if (file.exists())
        {
            if(m_translator.load(path))
            {
                QApplication::installTranslator(&m_translator);
            }
            else
            {
                qDebug() << "FATAL: Failed to load i18n resource file.";
            }
        }
    }

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
