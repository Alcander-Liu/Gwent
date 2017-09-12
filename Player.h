#ifndef PLAYER_H
#define PLAYER_H

#include "Field.h"
#include "BattleField.h"
#include "Card.h"

class Player
{
public:
    Player();

public:
    int cardAmount;
    Field deckInGame;
    Field graveYard;
    Field hand;
    BattleField battleField;
    Card *card;
    Card *bigCardWithDetails;
};

#endif // PLAYER_H
