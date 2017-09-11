#ifndef FIELD_H
#define FIELD_H

#include "Card.h"
#include <QGraphicsRectItem>
#include <QWidget>
#include <QRect>
#include <QMultiMap>

class Field: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Field(QObject *parent = nullptr);

public:
    bool weathered;
    bool selectable;
    QMultiMap<int, Card*> cardToCardPtr;
    Card *card[40];
    int cardAmount;

signals:
   void fieldPressed();

protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    void adjuctCardsPosition(int lane);


};

#endif // FIELD_H
