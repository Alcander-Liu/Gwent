#ifndef DECK_H
#define DECK_H

#include <map>
#include <QObject>
#include <QMultiMap>
#include "Card.h"

class Deck : public QObject
{
    Q_OBJECT
public:
    Deck(QObject *parent = nullptr);
    Deck(const Deck &deck);
    ~Deck(){}

signals:

public slots:

public:
    QMultiMap<int,int> cardNumberMap;    
    int leader;
    bool valid;

public:
    int cardAmount;
    int goldUsage;
    int silverUsage;
    int bronzeUsage;

public:
    void makeCopyOf(Deck *deck){
                     this->cardAmount = deck->getCardAmount();
                   this->cardNumberMap = deck->cardNumberMap;
                   this->goldUsage = deck->getGoldUsage();
                   this->silverUsage = deck->getSilverUsage();
                   this->bronzeUsage = deck->getBronzeUsage();
                   this->leader = deck->leader;
                  }
    void addCard(Card *card, int lane);
    void removeCard(Card *card);
    int at(int index);

    int getCardAmount(){return cardAmount;}
    int getGoldUsage(){return goldUsage;}
    int getSilverUsage(){return silverUsage;}
    int getBronzeUsage(){return bronzeUsage;}
    friend QDataStream & operator << (QDataStream &out, const Deck &deck);
    friend QDataStream & operator >> (QDataStream &in, const Deck &deck);
};

#endif // DECK_H
