#ifndef MEREABOUTWINDOW_H
#define MEREABOUTWINDOW_H

#include <QDebug>
#include <QMainWindow>


namespace Ui {
class MereAboutWindow;
}

class MereAboutWindow : public QMainWindow
{
    Q_OBJECT
public:
    ~MereAboutWindow();
    explicit MereAboutWindow(QWidget *parent = 0);

protected:
     void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MereAboutWindow *ui;
};

#endif // MEREABOUTWINDOW_H
