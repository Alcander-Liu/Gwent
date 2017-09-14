#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>


class Card : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Card(QPixmap pixmap, QObject *parent = nullptr);

signals:

public slots:

public:
    int level;
    int rarity;
    bool loyalty;
    int lane; // capable place:  1:Melee 2:Ranged 3:Siege -1:all 0:special
    int power;
    int armor;
    int field;  //current place: 1:Melee 2:Ranged 3:Siege 0:special -1:hand -2:graveyard -3: deck
    int position;
    int number;
    int sequence;
    int cardNumber;
    QString remark;
    QString skill;
    bool selectable = false;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    virtual Card * makeCopy(QObject *parent = nullptr)
    {
        return nullptr;
    }
    void used(int lane){  }
//    Card * newCard(int cardNumber, QObject *parent = nullptr);

signals:
    void cardPressed(Card *);

};

#endif // CARD_H
