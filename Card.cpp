#include "Card.h"

Card::Card(QPixmap pixmap,QWidget *parent) : QWidget(parent), QGraphicsPixmapItem(pixmap)
{

}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit cardPressed(this);
}


