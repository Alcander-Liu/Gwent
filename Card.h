#ifndef CARD_H
#define CARD_H

#include <QObject>
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
    int cardNumber;
    QString remark;
    QString skill;
    QString name;
    bool selectable = false;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    
signals:
    void cardPressed(Card *);

};

#endif // CARD_H
