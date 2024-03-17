#include "aboutwin.h"

#include <QIcon>
#include <QScreen>
#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>

AboutWin::AboutWin(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setObjectName("AboutWin");

    resize(700, 300);

    QScreen *screen = QApplication::primaryScreen();
    move(screen->virtualGeometry().center() - this->rect().center());

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    setLayout(layout);

    init();
    initUI();
}

void AboutWin::init()
{

}

void AboutWin::initUI()
{
    initHeaderUI();
    initContentUI();
    initFooterUI();
    initTranslateUI();
}

void AboutWin::initHeaderUI()
{
    QHBoxLayout *hLayout = new QHBoxLayout;

    QWidget *header = new QWidget(this);
    header->setObjectName("AboutHeader");
    header->setMinimumHeight(60);
    header->setMaximumHeight(75);
    header->setLayout(hLayout);

    QLabel *mereLogo = new QLabel(header);
    mereLogo->setObjectName("AboutLogo");
    mereLogo->setMaximumHeight(41);
    mereLogo->setMaximumWidth(161);

    QPixmap pixmap(QString::fromUtf8(":/about/mere-logo.png"));
    mereLogo->setPixmap(pixmap);
    mereLogo->setScaledContents(true);

    hLayout->addWidget(mereLogo);

    m_version = new QLabel(tr("AboutVersion"), header);
    m_version->setObjectName("AboutVersion");
    m_version->setAlignment(Qt::AlignBottom);
    hLayout->addWidget(m_version);

    QPushButton *btnClose = new QPushButton(header);
    btnClose->setObjectName("btnClose");
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

void AboutWin::initContentUI()
{
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setAlignment(Qt::AlignTop);

    QWidget *content = new QWidget(this);
    content->setLayout(hLayout);
    content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_summary = new QLabel(tr("AboutSummary"));
    m_summary->setObjectName("AboutSummary");
    m_summary->setWordWrap(true);

    hLayout->addWidget(m_summary);

    QLabel *dummy = new QLabel(this);
    hLayout->addWidget(dummy);

    layout()->addWidget(content);
}

void AboutWin::initFooterUI()
{
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);

    QWidget *footer = new QWidget(this);
    footer->setLayout(vLayout);

    m_contact = new QLabel(tr("ContactUs"), this);
    m_contact->setObjectName("ContactUs");
    vLayout->addWidget(m_contact);

    QLabel *addresses = new QLabel(this);
    addresses->setAlignment(Qt::AlignCenter);
    addresses->setMargin(0);
    addresses->setText("https://github.com/merelabs | https://merelabs.io | info@merelabs.io");
    vLayout->addWidget(addresses);

    layout()->addWidget(footer);
}

void AboutWin::initTranslateUI()
{
}

void AboutWin::close()
{
    qApp->exit(0);
}

