#include <QtWidgets>
#include <QMessageBox>

class ResizeObserver : public QLabel
{
    public:
    ResizeObserver(QWidget* pwgt = 0) : QLabel(pwgt)
    {
        setAlignment(Qt::AlignCenter);
    }
    protected:
    bool isPress = false;
    virtual void resizeEvent(QResizeEvent* pe)
    {
        setText(QString("Resized")
        + "\n width()=" + QString::number(pe->size().width())
        + "\n height()=" + QString::number(pe->size().height()));
        if(!isPress)
        {
            if(pe->size().height() * pe->size().width() > 600*600)
                    {
                        QMessageBox::warning(this, "Внимание","Размер больше 600 x 600!");
                    }
        }
    }

    virtual void keyPressEvent(QKeyEvent* keyEvent) override {
        if(keyEvent->modifiers() == Qt::ControlModifier) {
          if(isPress)
          {
              isPress = false;
          }
          else
          {
              isPress = true;
          }
        }
    }
};

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ResizeObserver wgt;
    wgt.resize(250, 130);
    wgt.show();
    return app.exec();
}
