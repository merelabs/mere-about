#ifndef MEREABOUTAPP_H
#define MEREABOUTAPP_H

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
};

#endif // MEREABOUTAPP_H
