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


private:
    int cardAmount;
    QMultiMap<int, Card*> cardToCardPtr;

signals:
   void fieldPressed();

protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    void addCard(Card *card);
    void removeCard(Card *card);
    void adjustCardsPosition_DeckControl(int fieldType);
    void adjustCardsPosition_Game(int fieldType);
    Card* at(int index);
    int getCardAmount(){return cardAmount;}


};

#endif // FIELD_H
