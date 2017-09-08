#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QWidget>

class Card : public QWidget
{
    Q_OBJECT
public:
    explicit Card(QWidget *parent = nullptr);

signals:

public slots:

public:
    int group;
    int rarity;
    bool loyalty;
    int lane;
    int power;
    int armor;
    int field;
    int position;
    int number;
    int sequence;
};

#endif // CARD_H