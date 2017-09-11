#include "Field.h"

Field::Field(QObject *parent):QObject(parent)
{
    cardAmount = 0;
    weathered = 0;
}

void Field::adjuctCardsPosition(int lane)
{
    int centralX = 950;
    /*if(lane != 0)
        for(int i = 0; i<cardAmount; i++)
        {
            card[i]->setPos(centralX - cardAmount*50 + 100*i, 40 + lane*115);
        }
    else
    {
        if(cardAmount < 11)
            for(int i = 0; i<cardAmount; i++)
            {
                card[i]->setPos(centralX - cardAmount*50 + 100*i, 515);
            }
        else
            for(int i = 0; i<cardAmount; i++)
            {
                card[i]->setPos(450 + i*900.0/cardAmount, 515);

            }

    }*/

    int i = 0;
    Card *temp;
    if(lane != 0)
        for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
        {
            temp = iter.value();
            temp->setPos(centralX - cardAmount*50 + 100*i, 40 + lane*115);
            i++;
        }
    else
    {
        if(cardAmount <11)
            for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
            {
                temp = iter.value();
                temp->setPos(centralX - cardAmount*50 + 100*i, 515);
                i++;
            }
        else
            for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
            {
                temp = iter.value();
                temp->setPos(450 + i*900.0/cardAmount, 515);
                i++;
            }

    }

}

void Field::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit fieldPressed();
}
