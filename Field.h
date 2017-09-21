#ifndef FIELD_H
#define FIELD_H

#include "Card.h"
#include <QGraphicsRectItem>
#include <QMultiMap>

class Field: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Field(QObject *parent = nullptr);

public:
    bool weathered;
    bool selectable;
    int scores;
    
private:
    int cardAmount; 
    QMultiMap<int, Card*> cardToCardPtr; //<cardNumber, card object>

signals:
   void fieldPressed();
   void scoresChanged(QString);

protected:
   void mousePressEvent(QGraphicsSceneMouseEvent *event);

public:
    void addCard(Card *card);
    virtual int countScores();
    void adjustCardsPosition_DeckControl(int fieldType);
    void adjustCardsPosition_Game(int fieldType, bool mySide);
    Card* at(int index);
    int getCardAmount(){ return cardAmount; }
    void removeCard(Card *card);
    void setCardsSelectable(bool b);

};

#endif // FIELD_H
