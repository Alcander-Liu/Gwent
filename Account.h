#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include "Deck.h"

class Account : public QObject
{
    Q_OBJECT
public:
    explicit Account(QObject *parent = nullptr);

signals:

public slots:

public:
    int deckAmount;
    Deck deck[5];
};

#endif // ACCOUNT_H
