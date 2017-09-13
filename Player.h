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

public:
    void generateCardsInDeck(Deck *deck, QGraphicsScene *scene);
    void drawCards(int round);
    void discardCards(int round);


signals:

public slots:

public:

};
#endif // PLAYER_H
