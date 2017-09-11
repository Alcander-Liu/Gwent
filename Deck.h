#ifndef DECK_H
#define DECK_H

#include <map>
#include <QObject>
#include <QMultiMap>

class Deck : public QObject
{
    Q_OBJECT
public:
    explicit Deck(QObject *parent = nullptr);

signals:

public slots:

public:
    int cardAmount;
    QMultiMap<int,int> cardNumber;
    int goldUsage;
    int silverUsage;
    int bronzeUsage;
    int leader;

public:
    void makeCopyOf(Deck *deck){
                     this->cardAmount = deck->cardAmount;
                   this->cardNumber = deck->cardNumber;
                   this->goldUsage = deck->goldUsage;
                   this->silverUsage = deck->goldUsage;
                  }

};

#endif // DECK_H
