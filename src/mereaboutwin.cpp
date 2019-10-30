#include "mereaboutwin.h"

#include <QIcon>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>

MereAboutWin::MereAboutWin(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setObjectName(QString::fromUtf8("MereAboutWin"));

    resize(700, 250);

    QDesktopWidget *desktop = QApplication::desktop();
    move(desktop->screen()->rect().center() - this->rect().center());

    init();
    initUI();
}

void MereAboutWin::init()
{

}

void MereAboutWin::initUI()
{
    initHeaderUI();
    initContentUI();
    initFooterUI();
    initTranslateUI();
}

void MereAboutWin::initHeaderUI()
{
    QLabel *mereLogo = new QLabel(this);
    mereLogo->setObjectName(QString::fromUtf8("mereLogo"));
    mereLogo->setGeometry(QRect(20, 20, 161, 41));
    mereLogo->setPixmap(QPixmap(QString::fromUtf8(":/about/mere-logo.png")));
    mereLogo->setScaledContents(true);

    m_version = new QLabel(this);
    m_version->setObjectName(QString::fromUtf8("MereAboutVersion"));
    m_version->setGeometry(QRect(191, 45, 41, 16));

    QPushButton *btnClose = new QPushButton(this);
    btnClose->setObjectName(QString::fromUtf8("btnClose"));
    btnClose->setGeometry(QRect(665, 5, 31, 31));
    btnClose->setBaseSize(QSize(24, 24));
    btnClose->setAutoFillBackground(false);

    QIcon icon;
    icon.addFile(QString::fromUtf8(":/about/close-icon.png"));
    btnClose->setIcon(icon);
    btnClose->setIconSize(QSize(24, 24));
    btnClose->setFlat(true);
    connect(btnClose, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void MereAboutWin::initContentUI()
{
    m_note = new QLabel(this);
    m_note->setObjectName(QString::fromUtf8("mereInfo"));
    m_note->setGeometry(QRect(20, 90, 311, 61));
    m_note->setAcceptDrops(true);
    m_note->setWordWrap(true);
}

void MereAboutWin::initFooterUI()
{
    m_aboutUs = new QLabel(this);
    m_aboutUs->setObjectName(QString::fromUtf8("MereAboutUs"));
    m_aboutUs->setGeometry(QRect(20, 180, 171, 31));

    QLabel *addresses = new QLabel(this);
    addresses->setObjectName(QString::fromUtf8("mereContacts"));
    addresses->setGeometry(QRect(20, 223, 661, 20));
    addresses->setAlignment(Qt::AlignCenter);
    addresses->setMargin(0);
    addresses->setText("https://github.com/merelab | https://merelab.io | info@merelab.io");
}

void MereAboutWin::initTranslateUI()
{
    m_aboutUs->setText(QApplication::translate("MereAboutWin", "About Us", nullptr));
    m_note->setText(QApplication::translate("MereAboutWin", "<html><head/><body><p>Simple system interface for UNIX like operating system developed from scratch.</p><p>MERE is licenced under the BSD 3-clause licence. </p></body></html>", nullptr));
    m_version->setText(QApplication::translate("MereAboutWin", "<html><head/><body><p><span style=\" font-weight:600;\">0.0.1</span></p></body></html>", nullptr));
}

void MereAboutWin::close()
{
    qApp->exit(0);
}

