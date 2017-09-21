#ifndef DECKCONTROL_H
#define DECKCONTROL_H

#include <QWidget>
#include <QObject>
#include "Account.h"
#include "carddatabase.h"
#include "Card.h"
#include "Deck.h"
#include "BattleField.h"
#include "TurnPageButton.h"
#include <QLabel>
#include <QGraphicsView>
#include <QMessageBox>
#include <QFile>
#include <QDataStream>

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
    void exit();

private:
    Ui::Form *ui;
    Account *account;
    BattleField *battleField;
    Card *selectedCard;
    Card *bigCardWithDetails;
    Card *leader = nullptr;
    Card *card[28];
    Deck deckEditing;    
    QLabel *remark;
    QLabel *skill;
    QLabel *name;
    QLabel *goldUsage;
    QLabel *silverUsage;
    QLabel *bronzeUsage;
    QLabel *totalUsage;
    QGraphicsScene *scene;
    QGraphicsView *view;
    TurnPageButton *saveAndExit;
    int cardsVisibleIndex;
    int deckEditingNumber;
    bool oneCardIsSelected;

private slots:
    void clearDeck();
    void cardSelected(Card *);
    void loadDeck(int);
    void laneSelected(int);
    void saveDeck();
    void turnLeftPage();
    void turnRightPage();

public:
    void run();
    
private:
    bool checkValidity(Card *card);
    void deleteCardDetails();
    void generateAllCards();
    void loadCardsInDeck();
    void newToLane(Card *card, int lane);
    void retrieveFromDeck(Card *card);
    void setCardsVisible(int index);
    void showCardDetails(Card *card);
    void updateUsageLabel();

};

#endif // DECKCONTROL_H
