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


private:
    Field *cardsAvoided;
    int discardAmount;

public:
    void generateCardsInDeck(Deck *deck, QGraphicsScene *scene);
    void drawCards_round(int round);
    void discardCards(int round);
    void drawCards(int times, Field *fieldSource);
    void playCard(Player *player);

private slots:
    void cardDiscarded(Card *card);

signals:
    void endDiscarding();

public slots:

public:

};
#endif // PLAYER_H
