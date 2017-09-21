#include "MyTimerLoop.h"

MyTimerLoop::MyTimerLoop(QWidget *parent) : QWidget(parent)
{
    timeRemaining = new QLabel(this);
    timeRemaining->setGeometry(0, 0, 200, 70);
    timeRemaining->setAlignment(Qt::AlignCenter);
    timeRemaining->show();
    timer.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
}


// set a loop which will quit after msec
// it can also be quit by calling quit()
// it updates and shows the remaining time every half sec
void MyTimerLoop::start(unsigned int msec)
{
    int halfsec = msec/500;
    shouldBreak = false;
    for(int i = halfsec; i>0; i--)
    {
        timer.start(500);
        timeRemaining->setText("<font color = white size = 8 face = HalisGR-Bold>" +QString::number(i/2)+"</font>");
        loop.exec();
        if(shouldBreak == true)
        {
            return;
        }
    }
    timer.start(500);
    timeRemaining->setText("<font color = white size = 4 face = HalisGR-Bold> Times Up </font>");
    loop.exec();
}

void MyTimerLoop::quit()
{
    shouldBreak = true;
}
