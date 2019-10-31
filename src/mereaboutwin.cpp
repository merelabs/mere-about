#include "mereaboutwin.h"

#include <QIcon>
#include <QScreen>
#include <QPushButton>
#include <QApplication>
#include <QDesktopWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

MereAboutWin::MereAboutWin(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setObjectName(QString::fromUtf8("MereAboutWin"));

    resize(700, 300);

    QScreen *screen = QApplication::primaryScreen();
    move(screen->virtualGeometry().center() - this->rect().center());

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);

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
    QHBoxLayout *hLayout = new QHBoxLayout;

    QWidget *header = new QWidget(this);
    header->setObjectName(QString::fromUtf8("MereAboutHeader"));
    header->setMinimumHeight(60);
    header->setMaximumHeight(75);
    header->setLayout(hLayout);

    QLabel *mereLogo = new QLabel(header);
    mereLogo->setObjectName(QString::fromUtf8("MereAboutLogo"));
    mereLogo->setMaximumHeight(41);
    mereLogo->setMaximumWidth(161);

    QPixmap pixmap(QString::fromUtf8(":/about/mere-logo.png"));
    mereLogo->setPixmap(pixmap);
    mereLogo->setScaledContents(true);

    hLayout->addWidget(mereLogo);

    m_version = new QLabel(tr("MereAboutVersion"), header);
    m_version->setObjectName(QString::fromUtf8("MereAboutVersion"));
    m_version->setAlignment(Qt::AlignBottom);
    hLayout->addWidget(m_version);

    QPushButton *btnClose = new QPushButton(header);
    btnClose->setObjectName(QString::fromUtf8("btnClose"));
    btnClose->setMaximumSize(QSize(24, 24));
    btnClose->setAutoFillBackground(false);

    QIcon icon;
    icon.addFile(QString::fromUtf8(":/about/close-icon.png"));
    btnClose->setIcon(icon);
    btnClose->setIconSize(QSize(24, 24));
    btnClose->setFlat(true);
    connect(btnClose, SIGNAL(clicked(bool)), this, SLOT(close()));

    hLayout->addWidget(btnClose);

    layout()->addWidget(header);
}

void MereAboutWin::initContentUI()
{
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setAlignment(Qt::AlignTop);

    QWidget *content = new QWidget(this);
    content->setLayout(hLayout);
    content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_summary = new QLabel(tr("MereAboutSummary"));
    m_summary->setObjectName(QString::fromUtf8("MereAboutSummary"));
    m_summary->setWordWrap(true);

    hLayout->addWidget(m_summary);

    QLabel *dummy = new QLabel(this);
    hLayout->addWidget(dummy);

    layout()->addWidget(content);
}

void MereAboutWin::initFooterUI()
{
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);

    QWidget *footer = new QWidget(this);
    footer->setLayout(vLayout);

    m_contact = new QLabel(tr("MereContactUs"), this);
    m_contact->setObjectName(QString::fromUtf8("MereContactUs"));
    vLayout->addWidget(m_contact);

    QLabel *addresses = new QLabel(this);
    addresses->setAlignment(Qt::AlignCenter);
    addresses->setMargin(0);
    addresses->setText("https://github.com/merelab | https://merelab.io | info@merelab.io");
    vLayout->addWidget(addresses);

    layout()->addWidget(footer);
}

void MereAboutWin::initTranslateUI()
{
}

void MereAboutWin::close()
{
    qApp->exit(0);
}

