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
    int lane;
    int power;
    int armor;
    int field;
    int position;
    int number;
    int sequence;
    int cardNumber;
    QString remark;
    QString skill;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    virtual Card * makeCopy(QObject *parent = nullptr)
    {
        return nullptr;
    }

signals:
    void cardPressed(Card *);

};

#endif // CARD_H
