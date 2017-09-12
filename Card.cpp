#include "Card.h"

Card::Card(QPixmap pixmap,QObject *parent) : QObject(parent), QGraphicsPixmapItem(pixmap)
{

}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit cardPressed(this);
}

//Card * Card::newCard(int cardNumber, QObject *parent = nullptr)


