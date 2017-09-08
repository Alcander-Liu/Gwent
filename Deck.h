#ifndef DECK_H
#define DECK_H

#include <map>
#include <QObject>

class Deck : public QObject
{
    Q_OBJECT
public:
    explicit Deck(QObject *parent = nullptr);

signals:

public slots:

public:
    int cardAmount;
    std::map<int,int> cardNumber;

};

#endif // DECK_H
