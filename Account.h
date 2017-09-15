#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include "Deck.h"
#include <QFile>
#include <QDataStream>

class Account : public QObject
{
    Q_OBJECT
public:
    Account(QObject *parent = nullptr);

public:
    Deck *deck[5];

public:
    void load();
    void save();
};

#endif // ACCOUNT_H
