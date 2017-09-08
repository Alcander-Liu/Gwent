#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>
class Card : public QWidget, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Card(QPixmap pixmap, QWidget *parent = nullptr);

signals:

public slots:

public:
    int level;
    int rarity;
    bool loyalty;
    int lane;
    int power;
    int armor;
    int field;
    int position;
    int number;
    int sequence;
    int cardNumber;
};

#endif // CARD_H
