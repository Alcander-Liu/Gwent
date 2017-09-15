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

Deck::Deck(const Deck &deck)
{
    cardAmount = deck.cardAmount;
    goldUsage = deck.goldUsage;
    silverUsage = deck.silverUsage;
    bronzeUsage = deck.bronzeUsage;
    leader = deck.leader;
    valid = deck.valid;
    cardNumberMap = deck.cardNumberMap;
    this->setParent(deck.parent());
}

void Deck::makeCopyOf(Deck *deck)
{
    this->cardAmount = deck->getCardAmount();
    this->cardNumberMap = deck->cardNumberMap;
    this->goldUsage = deck->getGoldUsage();
    this->silverUsage = deck->getSilverUsage();
    this->bronzeUsage = deck->getBronzeUsage();
    this->leader = deck->leader;
    this->valid = deck->valid;
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

int Deck::at(int index)
{
    int i = -1;
    if(index >= 0 && index < cardAmount)
    {
        for(auto iter = cardNumberMap.begin(); iter != cardNumberMap.end(); iter++)
        {
            i++;
            if(i == index)
                return iter.key();
        }
    }
    else
        return -1;
}

