#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QWidget>
#include "Account.h"
#include "Card.h"
#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>
#include <QEventLoop>
#include "Player.h"

namespace Ui {
class gameControl;
}

class GameControl : public QWidget
{
    Q_OBJECT
public:
    explicit GameControl(Account *account, QWidget *parent = nullptr);

signals:

private slots:
    void startGame(int deckNumber);
    void cardSelected(Card *card);

private:
    Player *player;
    Player *opponent;
    Ui::gameControl *ui;
    Account *account;
    bool oneCardIsSelected;
    Card *selectedCard;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Card *bigCardWithDetails;
    QLabel *remark;
    QLabel *skill;
    Card *leader = nullptr;

private:

    void buildChooseDeckUI();
    void initializeDeck(int deckNumber);
    void startRound(int round);
    void showCardDetails(Card *card);
    void deleteCardDetails();
};

#endif // GAMECONTROL_H
