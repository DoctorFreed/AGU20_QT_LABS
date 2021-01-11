#include "mouseobserver.h"

MouseObserver::MouseObserver(QWidget* pwgt) : QLabel(pwgt)
{
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions \n(Press a mouse button)");
}

void MouseObserver::mousePressEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Pressed");
}

void MouseObserver::mouseReleaseEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Released");
}

void MouseObserver::mouseMoveEvent(QMouseEvent* pe)
{
    dumpEvent(pe, "Mouse Is Moving");
}

void MouseObserver::keyPressEvent(QKeyEvent* pe)
{
    dumpKeyEvent("Key Pressed");
    if(pe->key() == Qt::Key_Left)
    {
        dumpKeyEvent("Key Left");
        this->move(this->x()-10, this->y());
    }
    if(pe->key() == Qt::Key_Right)
    {
        dumpKeyEvent("Key Right");
        this->move(this->x()+10, this->y());
    }
    if(pe->key() == Qt::Key_Up)
    {
        dumpKeyEvent("Key Up");
        this->move(this->x(), this->y()-10);
    }
    if(pe->key() == Qt::Key_Down)
    {
        dumpKeyEvent("Key Down");
        this->move(this->x(), this->y()+10);
    }

}

void MouseObserver::keyReleaseEvent(QKeyEvent* pe)
{
    dumpKeyEvent("Key Release");
}

void MouseObserver::dumpKeyEvent(const QString& strMsg)
{
    setText(strMsg);

}

void MouseObserver::dumpEvent(QMouseEvent* pe, const QString& strMsg)
{
    setText(strMsg
    + "\n buttons()=" + buttonsInfo(pe)
    + "\n x()=" + QString::number(pe->x())
    + "\n y()=" + QString::number(pe->y())
    + "\n globalX()=" + QString::number(pe->globalX())
    + "\n globalY()=" + QString::number(pe->globalY())
    + "\n modifiers()=" + modifiersInfo(pe)
    );

}

QString MouseObserver::modifiersInfo (QMouseEvent* pe)
{
    QString strModifiers;
    if(pe->modifiers() & Qt::ShiftModifier)
    {
    strModifiers += "Shift ";
    }
    if(pe->modifiers() & Qt::ControlModifier)
    {
    strModifiers += "Control ";
    }
    if(pe->modifiers() & Qt::AltModifier)
    {
    strModifiers += "Alt";
    }
    return strModifiers;
}

QString MouseObserver::buttonsInfo(QMouseEvent* pe)
{
    QString strButtons;
    if(pe->buttons() & Qt::LeftButton)
    {
    strButtons += "Left ";
    }
    if(pe->buttons() & Qt::RightButton)
    {
    strButtons += "Right ";
    }
    if(pe->buttons() & Qt::MidButton)
    {
    strButtons += "Middle";
    }
    return strButtons;
}