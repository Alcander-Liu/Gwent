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
    Card *tempCard;
    for(int i = 0; i<deck->getCardAmount(); i++)
    {
        tempCard = newCard(deck->at(i), this);
        tempCard->field = 3;
        deckInGame->addCard(tempCard);
        scene->addItem(tempCard);
        tempCard->hide();
    }



/*
    qsrand(QTime::currentTime().msec());
    int tempRand;
    int i,j;
    Card *tempCard;
    QMultiMap<int, int> tempMap = deck->cardNumberMap;

    for(i = 1; i<= deck->cardAmount(); i++)
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
    }*/
}

void Player::drawCards_round(int round)
{
    switch(round)
    {
    case 1:
        drawCards(10, deckInGame);
        break;
    case 2:
        drawCards(3, deckInGame);
        break;
    case 3:
        drawCards(1, deckInGame);
        break;
    }
}

void Player::drawCards(int times, Field *fieldSource)
{
    qsrand(QTime::currentTime().msec());
    int tempRand;
    Card *tempCard;

    for(int i = 0; i < times; i++)
    {
        tempRand = (qrand() % fieldSource->getCardAmount());
        tempCard = fieldSource->at(tempRand);
        tempCard->field = -1;
        hand->addCard(tempCard);
        tempCard->show();
        fieldSource->removeCard(tempCard);
    }


    hand->adjustCardsPosition_Game(0);
}

void Player::discardCards(int round)
{
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
    cardsAvoided = new Field();

    for(int i = 0; i < hand->getCardAmount(); i++)
    {
        tempCard = hand->at(i);
        connect(tempCard, SIGNAL(cardPressed(Card*)), this, SLOT(cardDiscarded(Card *)));
    }

    QEventLoop loop;
    connect(this, SIGNAL(endDiscarding()), &loop, SLOT(quit()));
    loop.exec();

    for(int i = 0; i < hand->getCardAmount(); i++)
    {
        tempCard = hand->at(i);
        disconnect(tempCard, SIGNAL(cardPressed(Card*)), this, SLOT(cardDiscarded(Card *)));
    }

    while(cardsAvoided->getCardAmount() != 0)
    {
        tempCard = cardsAvoided->at(0);
        cardsAvoided->removeCard(tempCard);
        deckInGame->addCard(tempCard);
    }
    delete cardsAvoided;
}

void Player::cardDiscarded(Card *card)
{
    Card *tempCard;


    hand->removeCard(card);
    cardsAvoided->addCard(card);
    card->field = 3;
    card->hide();

    for(int i = 0; i < deckInGame->getCardAmount(); i++)
    {
        tempCard = deckInGame->at(i);
        if(tempCard->cardNumber == card->number)
        {
            deckInGame->removeCard(tempCard);
            cardsAvoided->addCard(tempCard);
            i--;
        }
    }

    if(deckInGame->getCardAmount() != 0)
        drawCards(1, deckInGame);
    else
        drawCards(1, cardsAvoided);

    discardAmount --;

    if(discardAmount == 0)
        emit endDiscarding();
}

void Player::playCard(Player *player)
{



}
