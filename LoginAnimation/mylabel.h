#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>

class MyLabel : public QLabel
{
public:
    MyLabel(QWidget* parent = nullptr);

public:
    //开始执行连接动画
    void start();

    //停止连接动画
    void stop();

public:
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);

private:
    int timerId;
    int angle;
    qreal rMin, rMax;
    int interval;
    QPointF center;
};

#endif // MYLABEL_H
