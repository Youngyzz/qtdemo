#include "mylabel.h"
#include <QPainter>
#include <QTimerEvent>
#include <QTimer>

MyLabel::MyLabel(QWidget* parent)
    : QLabel(parent)
{
    angle = 0;
    rMin = 70;
    rMax = 90;
    timerId = -1;
}

void MyLabel::paintEvent(QPaintEvent *)
{
    QImage image(":/sucai2.png");
    QImage image2(":/sucai4.png");
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), image2);
    painter.drawImage(QPoint(0, 0), image);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawArc(35, 35, 140, 140, 0, angle);
    //painter.setPen(QBrush());
    painter.drawEllipse(QPointF(105.5, 105.5), rMin, rMin);
    painter.drawEllipse(QPointF(105.5, 105.5), rMax, rMax);
}

void MyLabel::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == timerId) {
        if (rMin < 105.5) {
            rMin += 35.5 / 30;
        } else {
            rMin = 70;
        }

        if (rMax < 105.5) {
            rMax += 35.5 / 30;
        } else {
            rMax = 70;
        }

        if (angle < 16 * 360) {
            angle += 16 * 360 / 30;
        }
        else {
            angle = 0;
        }

        angle += 16 * 360 / 30;
        update();
    }
}

void MyLabel::start() {
    timerId = startTimer(33);
}

void MyLabel::stop() {
    rMin = 70;
    rMax = 90;
    angle = 0;
    killTimer(timerId);
}
