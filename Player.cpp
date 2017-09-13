#include "Player.h"
#include <QDebug>

Player::Player(QObject * parent):QObject(parent)
{
    cardAmount = 0;
    deckInGame = new Field(this);
    graveYard = new Field(this);
    hand = new Field(this);
    battleField = new BattleField(this);
}



void Player::generateCardsInDeck(Deck *deck, QGraphicsScene *scene)
{
    qsrand(QTime::currentTime().msec());
    int tempRand;
    int i,j;
    Card *tempCard;
    QMultiMap<int, int> tempMap = deck->cardNumberMap;

    for(i = 1; i<= deck->cardAmount; i++)
    {
        tempRand = (qrand()%27) + 1;
        j = 0;
        for(auto iter = tempMap.begin(); iter != tempMap.end(); iter++)
        {
            j++;
            if(j == tempRand)
            {
                tempCard = newCard(iter.key());
                deckInGame->cardToCardPtr.insert(i, tempCard);
                scene->addItem(tempCard);
                tempCard->hide();
                qDebug()<<j;
                tempMap.erase(iter);
                break;
            }
        }
    }
}

void Player::drawCards(int round)
{
    int drawAmount;
    Card *tempCard;

    switch(round)
    {
    case 1:
        drawAmount = 10;
        break;
    case 2:
        drawAmount = 3;
        break;
    case 3:
        drawAmount = 1;
        break;
    }


    for(int i = 0; i<drawAmount; i++)
    {
        auto iter = this->deckInGame->cardToCardPtr.begin();
        tempCard = iter.value();
        this->hand->cardToCardPtr.insert(tempCard->cardNumber, tempCard);
        hand->cardAmount ++;
        tempCard->show();
        this->deckInGame->cardToCardPtr.erase(iter);
        iter++;
    }
    this->hand->adjustCardsPosition_Game(0);
}

void Player::discardCards(int round)
{
    int discardAmount;
    Card *tempCard;

    switch(round)
    {
    case 1:
        discardAmount = 3;
        break;
    case 2:
        discardAmount = 2;
        break;
    case 3:
        discardAmount = 1;
        break;
    }

    /*
     *
     *
     * show tips;
     * */
    for(auto iter = hand->cardToCardPtr.begin(); iter != hand->cardToCardPtr.end(); iter++)
    {
        tempCard = iter.value();
        connect(tempCard, SIGNAL(cardPressed(Card*)), hand, SLOT(cardDiscarded(Card *)));
    }

}

