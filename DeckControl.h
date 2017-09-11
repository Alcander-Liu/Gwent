#ifndef DECKCONTROL_H
#define DECKCONTROL_H

#include <QWidget>
#include <QMainWindow>
#include <QObject>
#include "Account.h"
#include "carddatabase.h"
#include "Card.h"
#include "Deck.h"
#include "BattleField.h"
#include "TurnPageButton.h"
#include <QLabel>
#include <QGraphicsView>

namespace Ui {
class Form;
}

class DeckControl : public QWidget
{
    Q_OBJECT
public:
    explicit DeckControl(Account *account, QWidget *parent = 0);
    ~DeckControl();

signals:

private:
    Ui::Form *ui;
    Account *account;
    bool oneCardIsSelected;
    Card *selectedCard;
    BattleField *battleField;
    Deck deckEditing;
    QGraphicsScene *scene;
    Card *bigCardWithDetails;
    QLabel *remark;
    QLabel *skill;
    QLabel *goldUsage;
    QLabel *silverUsage;
    QLabel *bronzeUsage;
    QLabel *totalUsage;
    Card *leader = nullptr;
    QGraphicsView *view;


public:
    Card *card[28];
    Card *cardInDeck[40];

public slots:
    void goBack();
    void loadDeck(int);
    void cardSelected(Card *);
    void laneSelected(int);

private slots:
    void turnLeftPage();
    void turnRightPage();

public:
    void run();
    void generateAllCards();
    void setCardsVisible(int index);
    void NewToLane(Card *card, int lane);

private:
    bool checkValidity(Card *card);
    void showCardDetails(Card *card);
    void deleteCardDetails();
    void retrieveFromDeck(Card *card);

private:
    int cardsVisibleIndex;

};

#endif // DECKCONTROL_H
