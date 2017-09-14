#include "Field.h"

Field::Field(QObject *parent):QObject(parent)
{
    cardAmount = 0;
    weathered = 0;
    scores = 0;
}

void Field::addCard(Card *card)
{
    cardToCardPtr.insert(card->cardNumber, card);
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

Card* Field::at(int index)
{
    int i = -1;
    if(index >= 0 && index < cardAmount)
    {
        for(auto iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
        {
            i++;
            if(i == index)
                return iter.value();
        }
    }
    else
        return nullptr;
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

void Field::adjustCardsPosition_Game(int fieldType, bool mySide)
{
    int centralX = 930;

    int i = 0;
    Card *temp;
    if(mySide == true) // for player
    {
        if(fieldType == 0)
            for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
            {
                temp = iter.value();
                temp->setPos(centralX - cardAmount*50 + 100*i, 880);
                i++;
            }
        else
        {
            for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
            {
                temp = iter.value();
                temp->setPos(centralX - cardAmount*50 + 100*i, 430 + 100*fieldType);
                i++;
            }
        }
    }
    else // for opponent
    {
        if(fieldType == 0)
            for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
            {
                temp = iter.value();
                temp->setPos(centralX - cardAmount*50 + 100*i, 50);
                i++;
            }
        else
        {
            for(QMultiMap<int, Card*>::iterator iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
            {
                temp = iter.value();
                temp->setPos(centralX - cardAmount*50 + 100*i, 520 - 100*fieldType);
                i++;
            }
        }
    }
}

int Field::countScores()
{
    int tempScores = 0;
    Card *tempCard;
    for(auto iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
    {
        tempCard = iter.value();
        tempScores += tempCard->power;
    }
    scores = tempScores;
    emit scoresChanged("<font color = white size = 10 face = HalisGR-Bold>" +QString::number(scores)+"</font>");
    return tempScores;
}

void Field::setCardsSelectable(bool b)
{
    Card *tempCard;
    for(auto iter = cardToCardPtr.begin(); iter != cardToCardPtr.end(); iter++)
    {
        tempCard = iter.value();
        tempCard->selectable = b;
    }
}


void Field::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit fieldPressed();
}
