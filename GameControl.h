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
#include "TurnPageButton.h"
#include <QDebug>
#include <QTimer>

namespace Ui {
class gameControl;
}

class GameControl : public QWidget
{
    Q_OBJECT
public:
    explicit GameControl(Account *account, QWidget *parent = nullptr);

signals:
    void playerEndTurn();
    void turnChanged(QString);
    void exit();

private slots:
    void startGame(int deckNumber);
    void cardSelected(Card *card);
    void laneSelected(int lane);
    void playerPassed();
    void opponentPassed();

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
    QLabel *discardAmountLabel[2];
    QLabel *whoseTurnLabel;
    bool myTurn; // true: player's turn   fasle: opponent's turn

private:

    void buildChooseDeckUI();
    void initializeDeck(int deckNumber);
    void startRound(int round);
    void showCardDetails(Card *card);
    void deleteCardDetails();
    void playCard(Player *player);
    void countSubTotal();
    bool gameEnd();
    void showResult();

};

#endif // GAMECONTROL_H
