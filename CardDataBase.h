#ifndef CARDDATABASE_H
#define CARDDATABASE_H

#include "Card.h"
#include <QPushButton>
#include <QGraphicsPixmapItem>

class Card001: public Card // Vran Warrior
{
public:
    Card001(QWidget *parent = nullptr):
        Card(QPixmap::fromImage(QImage((":/card/Gwent Cards/001_VranWarrior.png"))), parent)
    {
        level = 3; //Bronze
        rarity = 2; //Rare
        loyalty = true; //Loyal
        lane = 0; //all
        power = 6;
        cardNumber = 001;
        QPushButton *cardImage = new QPushButton(parent);
        QPixmap *pixmap = new QPixmap();
        pixmap->load(":/card/Gwent Cards/001_VranWarrior.png");
        cardImage->setIcon(QIcon(":/card/Gwent Cards/001_VranWarrior.png"));
        cardImage->setIconSize(pixmap->size());
        cardImage->show();
    }
};



#endif // CARDDATABASE_H
