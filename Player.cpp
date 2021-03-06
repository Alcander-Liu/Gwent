#include "Player.h"
#include <QDebug>

Player::Player(QObject * parent):QObject(parent)
{
    passed = false;
    discardAmount = 3;
    bigScores = 0;
    deckInGame = new Field(this);
    graveYard = new Field(this);
    hand = new Field(this);
    battleField = new BattleField(this);
    leader = nullptr;
}



void Player::generateCardsInDeck(Deck *deck, QGraphicsScene *scene)
{
    Card *tempCard;
    for(int i = 0; i < deck->getCardAmount(); i++)
    {
        tempCard = newCard(deck->at(i), this);
        tempCard->field = -3; // this card is in deck
        deckInGame->addCard(tempCard);
        scene->addItem(tempCard);
        tempCard->hide();
    }

    // generate leader card
    leader = newCard(deck->leader, this);
    scene->addItem(leader);
    leader->selectable = false;
    leader->field = -1; // this is in hand
    connect(leader, SIGNAL(cardPressed(Card*)), this->parent(), SLOT(cardSelected(Card*)));
    if(mySide == true)
        leader->setPos(200, 870); // player
    else
        leader->setPos(200, 50); // opponent
    leader->show();
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

// draw 'times' cards from fieldSource to hand 
void Player::drawCards(int times, Field *fieldSource) 
{
    qsrand(QTime::currentTime().msec() + qrand());
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

    hand->adjustCardsPosition_Game(0, mySide);
}

void Player::discardCards(int round)
{
    Card *tempCard;
    cardsAvoided = new Field();

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
    emit discardAmountChanged("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(discardAmount)+"</font>");

    // make cards in hand discardable
    for(int i = 0; i < hand->getCardAmount(); i++)
    {
        tempCard = hand->at(i);
        connect(tempCard, SIGNAL(cardPressed(Card*)), this, SLOT(cardDiscarded(Card*)));
    }

    // hold here and wait for discard
    QEventLoop loop;
    connect(this, SIGNAL(endDiscarding()), &loop, SLOT(quit()));
    loop.exec();

    
    for(int i = 0; i < hand->getCardAmount(); i++)
    {
        tempCard = hand->at(i);
        disconnect(tempCard, SIGNAL(cardPressed(Card*)), this, SLOT(cardDiscarded(Card *)));
    }

    // move those discarded kinds back into the deck
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
    card->field = -3;
    disconnect(card, SIGNAL(cardPressed(Card*)), this, SLOT(cardDiscarded(Card*)));
    card->hide();


    // move the same kind into cardsAvoided to avoid drawing them.
    for(int i = 0; i < deckInGame->getCardAmount(); i++)
    {
        tempCard = deckInGame->at(i);
        if(tempCard->cardNumber == card->cardNumber)
        {
            deckInGame->removeCard(tempCard);
            cardsAvoided->addCard(tempCard);
            i--;
        }
    }

    // if there're no options in deck, then draw from cardsAvoided instead
    if(deckInGame->getCardAmount() != 0)
        drawCards(1, deckInGame);
    else
        drawCards(1, cardsAvoided);

    discardAmount --;
    emit discardAmountChanged("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(discardAmount)+"</font>");

    if(discardAmount == 0)
        emit endDiscarding();
}

void Player::setCardsSelectable(bool b)
{
    leader->selectable = true;
    hand->setCardsSelectable(b);
    battleField->lanes[1]->setCardsSelectable(b);
    battleField->lanes[2]->setCardsSelectable(b);
    battleField->lanes[3]->setCardsSelectable(b);
}

void Player::cleanBattleField()
{
    Card *tempCard;
    for(int i = 1; i<4; i++)
    {
        while(battleField->lanes[i]->getCardAmount() != 0)
        {
            tempCard = battleField->lanes[i]->at(0);
            battleField->lanes[i]->removeCard(tempCard);
            graveYard->addCard(tempCard);
            tempCard->field = -2; // in graveYard
            tempCard->hide();
        }
        battleField->lanes[i]->adjustCardsPosition_Game(i, mySide);
    }
    battleField->countScores();
}
