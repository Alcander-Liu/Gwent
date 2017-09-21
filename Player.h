#ifndef PLAYER_H
#define PLAYER_H

#include "Field.h"
#include "BattleField.h"
#include "Card.h"
#include <QObject>
#include <QTime>
#include "Deck.h"
#include "carddatabase.h"
#include <QGraphicsScene>
#include <QEventLoop>
#include <QLabel>

class Player: public QObject
{
    Q_OBJECT
public:
    Player(QObject *parent = 0);

public:
    Field *graveYard;
    Field *cardsAvoided; // used when drawing cards
    Field *deckInGame;    
    Field *hand;
    BattleField *battleField; // melee, ranged, siege
    Card *bigCardWithDetails;
    bool mySide; // true represents player, false represents opponent
    bool passed;
    int bigScores; // round results
    
private:
    Card *leader;
    int discardAmount;

public:
    void cleanBattleField(); // used after each round
    void drawCards_round(int round);  // drawing different numbers of cards according to current round
    void drawCards(int times, Field *fieldSource);
    void discardCards(int round);
    void generateCardsInDeck(Deck *deck, QGraphicsScene *scene);
    void setCardsSelectable(bool b);

private slots:
    void cardDiscarded(Card *card); // to discard one card

signals:
    void endDiscarding(); // emit after finishing discarding
    void discardAmountChanged(QString); // emit after one card is discarded
    void roundEnd(QString); // emit after each round

};
#endif // PLAYER_H
