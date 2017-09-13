#include "Deck.h"

Deck::Deck(QObject *parent) : QObject(parent)
{
    cardAmount = 0;
    goldUsage = 0;
    silverUsage = 0;
    bronzeUsage = 0;
    leader = 0;
    valid = false;
}

void Deck::addCard(Card *card, int lane)
{
    switch(card->level)
    {
    case 1:
        bronzeUsage++;
        break;
    case 2:
        silverUsage++;
        break;
    case 3:
        goldUsage++;
        break;
    }
    cardNumberMap.insert(card->cardNumber, lane);
    cardAmount ++;
}

void Deck::removeCard(Card *card)
{
    auto tempIter = cardNumberMap.find(card->cardNumber, card->field);

    if(tempIter == cardNumberMap.end())
        return;

    switch(card->level)
    {
    case 1:
        bronzeUsage--;
        break;
    case 2:
        silverUsage--;
        break;
    case 3:
        goldUsage--;
        break;
    }
    cardNumberMap.erase(tempIter);
    cardAmount --;
}
