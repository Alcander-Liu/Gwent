#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QWidget>
#include "Account.h"
#include "Card.h"
#include <QGraphicsView>
#include <QLabel>


class GameControl : public QWidget
{
    Q_OBJECT
public:
    explicit GameControl(QWidget *parent = nullptr);

signals:

public slots:

private:
    Account *account;
    bool oneCardIsSelected;
    Card *selectedCard;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Card *bigCardWithDetails;
    QLabel *remark;
    QLabel *skill;
    Card *leader = nullptr;

};

#endif // GAMECONTROL_H
