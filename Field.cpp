#include "Field.h"

Field::Field(QObject *parent):QObject(parent)
{
    cardAmount = 0;
    weathered = 0;
}

void Field::adjuctCardsPosition(int lane)
{
    int centralX = 280;
    for(int i = 0; i<cardAmount; i++)
    {
     //   card[i]->setScale(2.0);
        card[i]->setPos(centralX - cardAmount*50 + 100*i, 100 + lane*50);
    }
}

void Field::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit fieldPressed();
}
