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
#include <QMessageBox>
#include "MyTimerLoop.h"

namespace Ui {
class gameControl;
}

class GameControl : public QWidget
{
    Q_OBJECT
public:
    GameControl(Account *account, QWidget *parent = nullptr);

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
    Account *account;
    Card *bigCardWithDetails;
    QLabel *discardAmountLabel[2];
    Card *leader = nullptr;
    bool myTurn;  // true: player's turn   fasle: opponent's turn
    bool oneCardIsSelected;
    Player *opponent;
    Player *player;
    Ui::gameControl *ui;
    QLabel *remark;
    QLabel *skill;
    QLabel *name;
    Card *selectedCard;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QLabel *whoseTurnLabel;

private:
    void buildChooseDeckUI();
    void countSubTotal();
    void deleteCardDetails();
    bool gameEnd();
    void initializeDeck(int deckNumber);
    void playCard(Player *player);
    void startRound(int round);
    void showCardDetails(Card *card);
    void showResult();

};

#endif // GAMECONTROL_H
