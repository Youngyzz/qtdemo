#include "mylabel.h"
#include <QPainter>
#include <QTimerEvent>
#include <QTimer>
static const int MaxAngle = 16 * 360;
static const int Period =  30; //1s执行多少次
static const qreal MinRedius = 72;
static const qreal MaxRedius = 90;
MyLabel::MyLabel(QWidget* parent)
    : QLabel(parent)
{
    angle = 0;
    rMin = MinRedius;
    rMax = MaxRedius;
    timerId = -1;
    interval = 1000/Period;
}

void MyLabel::paintEvent(QPaintEvent *)
{
    QImage image(":/sucai2.png");
    QImage image2(":/sucai4.png");
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), image2);
    painter.drawImage(QPoint(0, 0), image);

    painter.setPen(QPen(QBrush(0x7585e1), 2));

    QPointF centerF = QPointF(width()/2.0, height()/2.0);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawArc(34, 34, 141, 141, 0, angle);

    painter.drawEllipse(centerF, rMin, rMin);
    painter.drawEllipse(centerF, rMax, rMax);
}

void MyLabel::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == timerId) {
        if (rMin < 105) {
            rMin += 35.0 / Period;
        } else {
            rMin = 70;
        }

        if (rMax < 105) {
            rMax += 35.0 / Period;
        } else {
            rMax = 70;
        }

        if (angle < 16 * 360) {
            angle += MaxAngle / Period;
        }
        else {
            angle = 0;
        }

        angle += MaxAngle / Period;
        update();
    }
}

void MyLabel::start() {
    timerId = startTimer(interval);
}

void MyLabel::stop() {
    rMin = 70;
    rMax = 90;
    angle = 0;
    killTimer(timerId);
    update();
}
