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

private slots:
    void on_btnClose_clicked();

private:
    Ui::MereAboutWindow *ui;
};

#endif // MEREABOUTWINDOW_H
