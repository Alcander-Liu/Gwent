#include "DeckControl.h"
#include "ui_DeckControl.h"
#include <QSignalMapper>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsPixmapItem>
using namespace std;

// setup UI, buttons, labels, and the scene
// wait for user to choose a deck to edit
DeckControl::DeckControl(Account *account, QWidget *parent) : 
    QWidget(parent)
{
    ui = new Ui::Form;
    ui->setupUi(this);

    QSignalMapper *m = new QSignalMapper(this);
    QPushButton *pushButton;
    for(int i = 0; i<5; i++)
    {
        pushButton = new QPushButton(this);
        pushButton->setText("Deck " + QString::number(i+1));
        pushButton->setGeometry(900, 300+100*i, 200, 50);
        pushButton->show();
        connect(pushButton, SIGNAL(clicked()), m, SLOT(map()));
        m->setMapping(pushButton, i);
    }
    connect(m, SIGNAL(mapped(int)), this, SLOT(loadDeck(int)));

    this->show();

    oneCardIsSelected = false;
    this->account = account;

    scene = new QGraphicsScene(0, 0, 1918, 1078, this);
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, 1920, 1080);
    view->setStyleSheet(" border-image: url(:/card/Gwent Cards/NewDeck_small.png) ");
    view->hide();

    TurnPageButton *left = new TurnPageButton(this);
    TurnPageButton *right = new TurnPageButton(this);
    left->setRect(350, 790, 50, 50);
    right->setRect(1520, 790, 50, 50);
    scene->addItem(left);
    scene->addItem(right);
    connect(left, SIGNAL(buttonPressed()), this, SLOT(turnLeftPage()));
    connect(right, SIGNAL(buttonPressed()), this, SLOT(turnRightPage()));

    saveAndExit = new TurnPageButton(this);
    saveAndExit->setRect(1005, 927, 180, 40);
    scene->addItem(saveAndExit);
    connect(saveAndExit, SIGNAL(buttonPressed()), this, SLOT(saveDeck()));

    TurnPageButton *clearDeckButton = new TurnPageButton(this);
    clearDeckButton->setRect(825, 927, 180, 40);
    scene->addItem(clearDeckButton);
    connect(clearDeckButton, SIGNAL(buttonPressed()), this, SLOT(clearDeck()));

    goldUsage = new QLabel(this);
    silverUsage = new QLabel(this);
    bronzeUsage = new QLabel(this);
    totalUsage = new QLabel(this);
    goldUsage->setGeometry(290, 420, 50, 50);
    silverUsage->setGeometry(290, 340, 50, 50);
    bronzeUsage->setGeometry(300, 280, 50, 50);
    totalUsage->setGeometry(270, 180, 50, 50);

    generateAllCards();
    

    QEventLoop loop;
    connect(ui->goBackButton, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();  // wait for user to choose a deck to edit
    this->hide();  // exit deckControl
}

DeckControl::~DeckControl()
{
    delete ui;
}

void DeckControl::loadDeck(int deckNumber)
{
    deckEditingNumber = deckNumber;
    deckEditing.makeCopyOf(account->deck[deckNumber]);
    oneCardIsSelected = false;

    view->show();

    // setup melee, ranged, siege, and special
    battleField = new BattleField(this);
    QSignalMapper *m = new QSignalMapper(this);
    for(int i = 0; i<4; i++)
    {
        battleField->lanes[i]->setRect(450, 75 + i*110, 1020, 96);
        scene->addItem(battleField->lanes[i]);
        connect(battleField->lanes[i], SIGNAL(fieldPressed()), m, SLOT(map()));
        m->setMapping(battleField->lanes[i], i);
    }
    battleField->lanes[0]->setRect(440, 525, 1040, 115);
    connect(m, SIGNAL(mapped(int)), this, SLOT(laneSelected(int)));

    // setup usage label
    goldUsage->setText("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(deckEditing.getGoldUsage())+"</font>");
    silverUsage->setText("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(deckEditing.getSilverUsage())+"</font>");
    bronzeUsage->setText("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(deckEditing.getBronzeUsage())+"</font>");
    totalUsage->setText("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(deckEditing.getCardAmount())+"</font>");
    goldUsage->show();
    silverUsage->show();
    bronzeUsage->show();
    totalUsage->show();

    // show first ten cards to be chosen
    cardsVisibleIndex = 1;
    setCardsVisible(cardsVisibleIndex);

    // load deck info
    loadCardsInDeck();

    // wait for user to select cards and build their deck.
    QEventLoop loop;
    connect(this, SIGNAL(exit()), &loop, SLOT(quit()));
    loop.exec();

    // back to the UI to choose deck1 to deck5
    delete battleField;
    delete m;
    view->hide();
    goldUsage->hide();
    silverUsage->hide();
    bronzeUsage->hide();
    totalUsage->hide();
}

void DeckControl::generateAllCards()
{
    card[1] = new Card001(this);
    card[2] = new Card002(this);
    card[3] = new Card003(this);
    card[4] = new Card004(this);
    card[5] = new Card005(this);
    card[6] = new Card006(this);
    card[7] = new Card007(this);
    card[8] = new Card008(this);
    card[9] = new Card009(this);
    card[10] = new Card010(this);
    card[11] = new Card011(this);
    card[12] = new Card012(this);
    card[13] = new Card013(this);
    card[14] = new Card014(this);
    card[15] = new Card015(this);
    card[16] = new Card016(this);
    card[17] = new Card017(this);
    card[18] = new Card018(this);
    card[19] = new Card019(this);
    card[20] = new Card020(this);
    card[21] = new Card021(this);
    card[22] = new Card022(this);
    card[23] = new Card023(this);
    card[24] = new Card024(this);
    card[25] = new Card025(this);
    card[26] = new Card026(this);
    card[27] = new Card027(this);

    for(int i = 1; i<28; i++)
    {
        scene->addItem(card[i]);
        connect(card[i], SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
    }
}

void DeckControl::setCardsVisible(int index)
{
    for(int i = 1; i<28; i++)
    {
        card[i]->QGraphicsItem::hide();
    }

    for(int i = index; i<index+10; i++)
    {
        card[i]->QGraphicsItem::show();
    }

    for(int i = 0; i<10; i++)
    {
        card[index+i]->setPos(100*i + 440, 750);
    }
}

void DeckControl::cardSelected(Card *card)
{
    if(oneCardIsSelected == false)
    {
        if(card->parent() == battleField)
        {
            retrieveFromDeck(card);
        }
        else if(card->level == 4) // leader
        {
            oneCardIsSelected = true;
            showCardDetails(card);
            selectedCard = card;            

            if(leader != nullptr)
                delete leader;
            leader = card->makeCopy(this);
            scene->addItem(leader);
            leader->setPos(180, 685);
            leader->setScale(0.47);
            leader->show();
            deckEditing.leader = leader->cardNumber;
        }
        else
        {
            oneCardIsSelected = true;
            showCardDetails(card);
            selectedCard = card;
        }
    }
    else // oneCardIsSelected == true
    {
        deleteCardDetails();
        oneCardIsSelected = false;
    }
}

void DeckControl::laneSelected(int lane)
{
    if(oneCardIsSelected == true)
    {
        if(selectedCard->level == 4) // leader
        {
            deleteCardDetails();
            oneCardIsSelected = false;
        }
        else if(lane == selectedCard->lane) // lane valid
        {
            newToLane(selectedCard, lane);
            deleteCardDetails();
            oneCardIsSelected = false;
        }
        else if(selectedCard->lane == -1 && lane != 0) // lane valid
        {
            newToLane(selectedCard, lane);
            deleteCardDetails();
            oneCardIsSelected = false;
        }
        else  // lane invalid
        {
            deleteCardDetails();
            oneCardIsSelected = false;
        }
    }
}

void DeckControl::newToLane(Card *card, int lane)
{
    if(this->checkValidity(card) == false)  // invalid due to card usages
        return;

    deckEditing.addCard(card, lane);
    updateUsageLabel();

    Card *temp = card->makeCopy(battleField);
    temp->field = lane;  // record current field(place)
    connect(temp, SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
    battleField->lanes[lane]->addCard(temp);
    scene->addItem(temp);
    temp->show();

    battleField->lanes[lane]->adjustCardsPosition_DeckControl(lane);
}

bool DeckControl::checkValidity(Card *card)
{
    if(deckEditing.getCardAmount() == 40)
        return false;

    switch(card->level)
    {
    case 3: // gold
    {
        if(deckEditing.getGoldUsage() == 4)
            return false;
        for(int i = 0; i < deckEditing.getCardAmount(); i++)
        {
            if(deckEditing.at(i) == card->cardNumber)
                return false;
        }
        break;
    }
    case 2: // silver
    {
        if(deckEditing.getSilverUsage() == 6)
            return false;
        for(int i = 0; i < deckEditing.getCardAmount(); i++)
        {
            if(deckEditing.at(i) == card->cardNumber)
                return false;
        }
        break;
    }
    case 1: // bronze
    {
        int count = 0;
        for(int i = 0; i < deckEditing.getCardAmount(); i++)
        {
            if(deckEditing.at(i) == card->cardNumber)
            {
                count++;
                if(count == 3)
                    return false;
            }
        }
        break;
    }
    }
   return true;
}

void DeckControl::turnLeftPage()
{
    if(cardsVisibleIndex != 1)
    {
        cardsVisibleIndex --;
        setCardsVisible(cardsVisibleIndex);
    }
}

void DeckControl::turnRightPage()
{
    if(cardsVisibleIndex != 18)
    {
        cardsVisibleIndex ++;
        setCardsVisible(cardsVisibleIndex);
    }
}

void DeckControl::showCardDetails(Card *card)
{
    bigCardWithDetails = card->makeCopy(this);
    bigCardWithDetails->setScale(1.3);
    bigCardWithDetails->setPos(1500, 100);
    remark = new QLabel(this);
    remark->setText(bigCardWithDetails->remark);
    remark->show();
    remark->setGeometry(1600, 600, 280, 100);
    remark->setAlignment(Qt::AlignTop);
    skill = new QLabel(this);
    skill->setText(bigCardWithDetails->skill);
    skill->show();
    skill->setGeometry(1600, 640, 280, 400);
    skill->setWordWrap(true);
    skill->setAlignment(Qt::AlignTop);
    scene->addItem(bigCardWithDetails);
}

void DeckControl::deleteCardDetails()
{
    delete bigCardWithDetails;
    delete remark;
    delete skill;
}

void DeckControl::retrieveFromDeck(Card *card)
{
    deckEditing.removeCard(card);
    updateUsageLabel();
    battleField->lanes[card->field]->removeCard(card);
    battleField->lanes[card->field]->adjustCardsPosition_DeckControl(card->field);
    delete card;
}

void DeckControl::saveDeck()
{
    if(leader == 0) // didn't choose a leader
    {
        QMessageBox *warning = new QMessageBox;
        warning->setText("A leader must be chosen.");
        warning->exec();
        delete warning;
        saveAndExit->setEnabled(false); // reset the button
        saveAndExit->setEnabled(true);
        return ;
    }
    else if(deckEditing.getCardAmount() < 25)
    {
        QMessageBox *warning = new QMessageBox;
        warning->setText("You need at least 25 cards");
        warning->exec();
        delete warning;
        saveAndExit->setEnabled(false);
        saveAndExit->setEnabled(true);
        deckEditing.valid = false;
        return ;
    }
    deckEditing.valid = true;
    account->deck[deckEditingNumber]->makeCopyOf(&deckEditing);
    account->save();
    emit exit();
}

void DeckControl::loadCardsInDeck()
{
    for(auto iter = deckEditing.cardNumberMap.begin(); iter != deckEditing.cardNumberMap.end(); iter++)
    {
        selectedCard = newCard(iter.key(), battleField);
        selectedCard->field = iter.value();
        connect(selectedCard, SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
        battleField->lanes[iter.value()]->addCard(selectedCard);
        scene->addItem(selectedCard);
    }
    for(int i = 0; i<4; i++)
        battleField->lanes[i]->adjustCardsPosition_DeckControl(i);

    if(deckEditing.leader != 0)
    {
        leader = newCard(deckEditing.leader, battleField);
        scene->addItem(leader);
        leader->setPos(180, 685);
        leader->setScale(0.47);
        leader->show();
    }
}

void DeckControl::clearDeck()
{
    for(int i = 0; i<4; i++)
        while(battleField->lanes[i]->getCardAmount() != 0 )
        {
            retrieveFromDeck(battleField->lanes[i]->at(0));
        }
    delete leader;
    leader = nullptr;
}

void DeckControl::updateUsageLabel()
{
    totalUsage->setText("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(deckEditing.getCardAmount())+"</font>");
    bronzeUsage->setText("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(deckEditing.getBronzeUsage())+"</font>");
    silverUsage->setText("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(deckEditing.getSilverUsage())+"</font>");
    goldUsage->setText("<font color = white size = 4 face = HalisGR-Bold>" +QString::number(deckEditing.getGoldUsage())+"</font>");
}
