#include "mereaboutwindow.h"
#include "ui_mainframe.h"

#include <QDesktopWidget>
#include <QMouseEvent>

MereAboutWindow::~MereAboutWindow()
{
    delete ui;
}

MereAboutWindow::MereAboutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MereAboutWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);

    QDesktopWidget *desktop = QApplication::desktop();

    move(desktop->screen()->rect().center() - this->rect().center());
}

void MereAboutWindow::mousePressEvent(QMouseEvent *event)
{
    this->close();
}
