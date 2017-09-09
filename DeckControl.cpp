#include "DeckControl.h"
#include "ui_DeckControl.h"
#include <QSignalMapper>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>

DeckControl::DeckControl(Account *account, QWidget *parent) :
    QWidget(parent)
{
    this->account = account;
}


DeckControl::~DeckControl()
{
    delete ui;
}

void DeckControl::run()
{
    ui = new Ui::Form;
    ui->setupUi(this);

    QSignalMapper *m = new QSignalMapper;

    QPushButton *pushButton;
    for(int i = 0; i<account->deckAmount; i++)
    {
        pushButton = new QPushButton();
        pushButton->setText("Deck " + (i+1));
        connect(pushButton, SIGNAL(clicked()), m, SLOT(map()));
        m->setMapping(pushButton, i+1);
    }

    connect(ui->newDeckButton, SIGNAL(clicked(bool)), m, SLOT(map()));
    m->setMapping(ui->newDeckButton, 0);


    //mainWindow->setCentralWidget(this);
    this->show();
    QEventLoop loop;
    connect(ui->goBackButton, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    connect(m, SIGNAL(mapped(int)), this, SLOT(loadDeck(int)));
    loop.exec();
    this->hide();
}

void DeckControl::goBack()
{


}

void DeckControl::loadDeck(int deckNumber)
{
    oneCardIsSelected = false;

    QGraphicsScene scene(0, 0, 1918, 1078, this);
    QGraphicsView view(&scene, this);

    view.setGeometry(0, 0, 1920, 1080);
    view.setStyleSheet(" border-image: url(:/card/Gwent Cards/NewDeck_small.png) ");
    view.show();
    if(deckNumber == 0)
    {

        generateAllCards();
        for(int i = 1; i<28; i++)
        {
            scene.addItem(card[i]);
            connect(card[i], SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
        }
        cardsVisibleIndex = 1;
        setCardsVisible(cardsVisibleIndex);

        connect(m, SIGNAL(mapped(int)), this, SLOT(laneSelected(int)));
       // card[1]->setPos(100,100);
 //     mainWindow->setCentralWidget(&view);

//        view.setSceneRect(0, 0, 1600, 900);
     //   view.showFullScreen();



        //mainWindow->setCentralWidget();



    }
    QEventLoop loop;
    loop.exec();
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
        card[i]->sequence = i;
}

void DeckControl::setCardsVisible(int index)
{
    for(int i = 1; i<28; i++)
    {
        card[i]->QGraphicsItem::hide();
    }

    for(int i = index; i<index+11; i++)
    {
        card[i]->QGraphicsItem::show();
    }

    for(int i = index; i<index+11; i++)
    {
        card[i]->setPos(100*i + 340, 740);
    }

}

void DeckControl::cardSelected(Card *card)
{
    if(oneCardIsSelected == false)
    {
        if(card->isInDeck == true)
            retrieveFromDeck(card);
        else
        {
            oneCardIsSelected = true;
            selectedCard = card;
        }
    }
    else
        oneCardIsSelected = false;
}

void DeckControl::landSelected(int lane)
{
    if(oneCardIsSelected == true)
    {
        if(lane == selectedCard->lane)
            moveToLane(selectedCard, lane);
        else if(card[selectedCardSequence] == 0)
            moveToLane(selectedCard, lane)
    }
}
