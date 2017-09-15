#ifndef MYTIMERLOOP_H
#define MYTIMERLOOP_H

#include <QWidget>
#include <QEventLoop>
#include <QTimer>
#include <QLabel>

class MyTimerLoop : public QWidget
{
    Q_OBJECT
public:
    explicit MyTimerLoop(QWidget *parent = nullptr);
    void start(unsigned int msec);

private:
    QLabel *timeRemaining;
    QEventLoop loop;
    QTimer timer;
    bool shouldBreak;

signals:

public slots:
    void quit();
};

#endif // MYTIMERLOOP_H
