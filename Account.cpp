#include "Account.h"

Account::Account(QObject *parent) : QObject(parent)
{
    for(int i = 0; i<5; i++)
        this->deck[i] = new Deck(this);
}

Account::Account(const Account &account)
{
    this->setParent(account.parent());
    for(int i = 0; i<5; i++)
        this->deck[i] = new Deck(account.deck[i]);
}

QDataStream & operator << (QDataStream &out, const Account &account)
{
    for(int i=0; i<5; i++)
        out << account.deck[i];
    return out;
}

QDataStream & operator >> (QDataStream &in, Account &account)
{
    for(int i=0; i<5; i++)
        in << account.deck[i];
    return in;
}

void Account::load()
{
    QFile file("account.txt");
    file.open(QIODevice::ReadOnly);

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_9);
    int a;
    in >> a;


    for(int i=0; i<5; i++)
    {
        in >> deck[i]->cardAmount;
        in >> deck[i]->goldUsage;
        in >> deck[i]->silverUsage;
        in >> deck[i]->bronzeUsage;
        in >> deck[i]->leader;
        in >> deck[i]->valid;
        in >> deck[i]->cardNumberMap;
    }
}

void Account::save()
{
    QFile file("account.txt");
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_9);
    int a = 3;
    out << a;

    for(int i=0; i<5; i++)
    {
        out << deck[i]->cardAmount;
        out << deck[i]->goldUsage;
        out << deck[i]->silverUsage;
        out << deck[i]->bronzeUsage;
        out << deck[i]->leader;
        out << deck[i]->valid;
        out << deck[i]->cardNumberMap;
    }
}
