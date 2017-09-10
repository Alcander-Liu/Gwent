#include "Deck.h"

Deck::Deck(QObject *parent) : QObject(parent)
{
    cardAmount = 0;
    goldUsage = 0;
    silverUsage = 0;
}
