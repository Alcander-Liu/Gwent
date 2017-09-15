#ifndef DECK_H
#define DECK_H

#include <QObject>
#include <QMultiMap>
#include "Card.h"

class Deck : public QObject
{
    Q_OBJECT
public:
    Deck(QObject *parent = nullptr);

signals:

public slots:

public:
    QMultiMap<int,int> cardNumberMap;  // <cardNumber, existing field(melee/siege/ranged/special)> 
    int leader; // leader card's number
    bool valid; // 25~40 cards

public:
    int cardAmount;
    int goldUsage;
    int silverUsage;
    int bronzeUsage;

public:
    void makeCopyOf(Deck *deck);
    void addCard(Card *card, int lane);
    void removeCard(Card *card);
    int at(int index);

    int getCardAmount(){ return cardAmount; }
    int getGoldUsage(){ return goldUsage; }
    int getSilverUsage(){ return silverUsage; }
    int getBronzeUsage(){ return bronzeUsage; }

};

#endif // DECK_H
