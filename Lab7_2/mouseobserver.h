#pragma once
#include <QtWidgets>

class MouseObserver : public QLabel {
    public:
    MouseObserver(QWidget* pwgt = 0);
    protected:
    virtual void mousePressEvent (QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent (QMouseEvent* pe);
    virtual void keyPressEvent (QKeyEvent* pe);
    virtual void keyReleaseEvent(QKeyEvent* pe);
    void dumpEvent (QMouseEvent* pe, const QString& strMessage);
    void dumpKeyEvent(const QString& strMessage);
    QString modifiersInfo (QMouseEvent* pe);
    QString buttonsInfo (QMouseEvent*	pe);
};
