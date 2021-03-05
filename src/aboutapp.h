#ifndef MEREABOUTAPP_H
#define MEREABOUTAPP_H

#include <QDebug>
#include <QTranslator>
#include <QApplication>

namespace Mere
{
    namespace About
    {
        #ifdef APP_CODE
        const QString AppCode   = APP_CODE;
        #else
        const QString AppCode   = "about";
        #endif

        #ifdef APP_NAME
        const QString AppName   = APP_NAME;
        #else
        const QString AppName   = "mere-about";
        #endif

        #ifdef APP_VERSION
        const QString AppVersion= APP_VERSION;
        #else
        const QString AppVersion= "0.0.0b";
        #endif
    }
}


class AboutWin;
class AboutApp : public QApplication
{
    Q_OBJECT
public:
    ~AboutApp();
    explicit AboutApp(int &argc, char **argv);

    void init();
    void start();

private:
    AboutWin *m_win;
    QTranslator m_translator;
};

#endif // MEREABOUTAPP_H
