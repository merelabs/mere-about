#ifndef MEREABOUTAPP_H
#define MEREABOUTAPP_H

#include <QDebug>
#include <QTranslator>
#include <QApplication>

class MereAboutWin;
class MereAboutApp : public QApplication
{
    Q_OBJECT
public:
    ~MereAboutApp();
    explicit MereAboutApp(int &argc, char **argv);

    void init();
    void start();

private:
    MereAboutWin *m_win;
    QTranslator m_translator;
};

#endif // MEREABOUTAPP_H
