#include "Field.h"

Field::Field(QObject *parent):QObject(parent)
{
    cardAmount = 0;
    weathered = 0;
}

void Field::addCard(int cardNumber, Card *card)
{
    cardToCardPtr.insert(cardNumber, card);
    cardAmount ++;
}

void Field::removeCard(Card *card)
{
    auto iter = cardToCardPtr.find(card->cardNumber, card);
    if(iter != cardToCardPtr.end())
    {
        cardToCardPtr.erase(iter);
        cardAmount --;
    }
}

void Field::adjustCardsPosition_DeckControl(int fieldType)
{
    int centralX = 950;

    int i = 0;
    Card *temp;

    if(fieldType != 0)
    {
        if(cardAmount <11)
        {
            for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
            {
                temp = iter.value();
                temp->setPos(centralX - cardAmount*50 + 100*i, 40 + fieldType*115);
                i++;
            }
        }
        else
        {
            for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
            {
                temp = iter.value();
                temp->setPos(450 + 900.0*i/cardAmount, 40 + fieldType*115);
                i++;
            }
        }
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

void Field::adjustCardsPosition_Game(int fieldType)
{
    int centralX = 500;

    int i = 0;
    Card *temp;

    if(fieldType == 0)
        for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
        {
            temp = iter.value();
            temp->setPos(centralX - cardAmount*50 + 100*i, 800);
            i++;
        }
}

void Field::cardDiscarded(Card *card)
{
    this->removeCard(card);
    this->adjustCardsPosition_Game(0);


}

void Field::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit fieldPressed();
}
