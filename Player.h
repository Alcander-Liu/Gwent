#ifndef PLAYER_H
#define PLAYER_H

#include "Field.h"
#include "Lane.h"
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
    Lane lane;
    Card *card;
};

#endif // PLAYER_H
