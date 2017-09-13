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
    explicit Deck(QObject *parent = nullptr);

signals:

public slots:

public:
    int cardAmount;
    QMultiMap<int,int> cardNumberMap;
    int goldUsage;
    int silverUsage;
    int bronzeUsage;
    int leader;
    bool valid;

public:
    void makeCopyOf(Deck *deck){
                     this->cardAmount = deck->cardAmount;
                   this->cardNumberMap = deck->cardNumberMap;
                   this->goldUsage = deck->goldUsage;
                   this->silverUsage = deck->goldUsage;
                  }
    void addCard(Card *card, int lane);
    void removeCard(Card *card);
};

#endif // DECK_H
