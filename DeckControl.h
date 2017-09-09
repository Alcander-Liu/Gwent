#ifndef DECKCONTROL_H
#define DECKCONTROL_H

#include <QWidget>
#include <QMainWindow>
#include <QObject>
#include "Account.h"
#include "carddatabase.h"
#include "Card.h"

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

public:
    Card *card[28];

public slots:
    void goBack();
    void loadDeck(int);
    void cardSelected(Card *);
    void landSelected(int);

public:
    void run();
    void generateAllCards();
    void setCardsVisible(int index);
    void moveToLane(Card *card, int lane);

private:
    int cardsVisibleIndex;

};

#endif // DECKCONTROL_H
