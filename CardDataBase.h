#ifndef CARDDATABASE_H
#define CARDDATABASE_H

#include "Card.h"

class Card001: public Card  // Vran Warrior
{
public:
    Card001()
    {
        type = 3; //Bronze
        rarity = 2; //Rare
        loyalty = true; //Loyal
        lane = 0; //all
        power = 6;
        cardNumber = 001;
    }
};



#endif // CARDDATABASE_H
