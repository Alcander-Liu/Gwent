#ifndef FIELD2_H
#define FIELD2_H

#include <QObject>
#include "Card.h"
#include <QGraphicsRectItem>
#include <QRect>

class Field2 : public QObject
{
    Q_OBJECT
public:
    explicit Field2(QObject *parent = nullptr);

public:
    bool weathered;
    bool selectable;
    Card *card[40];
    int cardAmount;

signals:

public slots:
};

#endif // FIELD2_H
