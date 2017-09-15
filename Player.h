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

    int cardAmount;
    Field *deckInGame;
    Field *graveYard;
    Field *hand;
    BattleField *battleField;
    Card *card;
    Card *bigCardWithDetails;
    bool mySide; // true represents player, false represents opponent
    bool passed;
    int bigScores;
    Card *leader;

private:
    Field *cardsAvoided;
    int discardAmount;


public:
    void generateCardsInDeck(Deck *deck, QGraphicsScene *scene);
    void drawCards_round(int round);
    void discardCards(int round);
    void drawCards(int times, Field *fieldSource);
    void setCardsSelectable(bool b); // this is for offline usesage
    void cleanBattleField();


private slots:
    void cardDiscarded(Card *card);

signals:
    void endDiscarding();
    void discardAmountChanged(QString);
    void roundEnd(QString);

public slots:


public:

};
#endif // PLAYER_H
