#include "GameControl.h"
#include "ui_gamecontrol.h"

GameControl::GameControl(Account *account, QWidget *parent) : QWidget(parent)
{
    this->account = account;

    ui = new Ui::gameControl;
    ui->setupUi(this);
    this->show();

    buildChooseDeckUI();
}

void GameControl::buildChooseDeckUI()
{
    QWidget chooseDeckUI(this);
    QSignalMapper *m = new QSignalMapper(&chooseDeckUI);
    QPushButton *pushButton;
    for(int i = 0; i<5; i++)
    {
        pushButton = new QPushButton(&chooseDeckUI);
        pushButton->setText("Deck " + QString::number(i+1));
        pushButton->setGeometry(900, 300+100*i, 200, 50);
        connect(pushButton, SIGNAL(clicked()), m, SLOT(map()));
        m->setMapping(pushButton, i);
    }
    connect(m, SIGNAL(mapped(int)), this, SLOT(startGame(int)));

    pushButton = new QPushButton(&chooseDeckUI);
    pushButton->setText("Back");
    pushButton->setGeometry(900, 800, 200, 50);

    chooseDeckUI.show();

    QEventLoop loop;
    connect(pushButton, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    loop.exec();
    this->hide();
}

void GameControl::startGame(int deckNumber)
{
    oneCardIsSelected = false;

    scene = new QGraphicsScene(0, 0, 1918, 1078, this);
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, 1920, 1080);
    view->setStyleSheet(" border-image: url(:/card/Gwent Cards/GameBackground_1080.png) ");
    view->show();

    initializeDeck(deckNumber); //shuffle the cards and decide who fist;
    startRound(1);
/*    for(int i = 1; i<4; i++)
    {
        startRound(i);
        if(gameEnd() == true)
            break;
    }
    showResult();*/

    QEventLoop loop;
    loop.exec();
}

void GameControl::initializeDeck(int deckNumber)
{
    player = new Player(this);
    opponent = new Player(this);
    player->generateCardsInDeck(&account->deck[deckNumber], scene);
    opponent->generateCardsInDeck(&account->deck[deckNumber], scene);
}

void GameControl::startRound(int round)
{
    player->drawCards(round);
    //opponent->drawCards(round);  // This line should be deleted in online mode.
  /*  player->discardCards(round);
    opponent->discardCards(round);  // This line should be deleted in online mode.
    while(true)
    {
        playCard(player);
        if(player->passed == true && opponent->passed == true)
            break;
        playCard(opponent);
        if(player->passed == true && opponent->passed == true)
            break;
    }
    countSubTotal();*/
}



