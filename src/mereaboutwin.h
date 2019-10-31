#ifndef MEREABOUTWIN_H
#define MEREABOUTWIN_H

#include <QLabel>
#include <QWidget>
#include <QDebug>

class MereAboutWin : public QWidget
{
    Q_OBJECT
public:
    explicit MereAboutWin(QWidget *parent = nullptr);
    void init();

private:
    void initUI();
    void initHeaderUI();
    void initContentUI();
    void initFooterUI();

    void initTranslateUI();

signals:

public slots:
private slots:
    void close();

private:
    QLabel *m_contact;
    QLabel *m_summary;
    QLabel *m_version;
};

#endif // MEREABOUTWIN_H
