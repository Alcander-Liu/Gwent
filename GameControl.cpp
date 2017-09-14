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
    player->generateCardsInDeck(account->deck[deckNumber], scene);
    //opponent->generateCardsInDeck(&account->deck[deckNumber], scene);

   /* QSignalMapper *m = new QSignalMapper(this);

   for(int i = 1; i<4; i++)
    {
        player->battleField->lanes[i]->setRect(450, 200+i*110, 1020, 96);
        scene->addItem(player->battleField->lanes[i]);
        connect(player->battleField->lanes[i], SIGNAL(fieldPressed()), m, SLOT(map()));
        m->setMapping(player->battleField->lanes[i], i);
    }*/


    //connect(m, SIGNAL(mapped(int)), this, SLOT(laneSelected(int)));

}

void GameControl::startRound(int round)
{
    player->drawCards_round(round);
    //opponent->drawCards(round);  // This line should be deleted in online mode.
    player->discardCards(round);

    for(int i = 0; i < player->hand->getCardAmount(); i++)
    {
        connect(player->hand->at(i), SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
    }
    //opponent->discardCards(round);  // This line should be deleted in online mode.
  /*  while(true)
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



void GameControl::cardSelected(Card *card)
{
    if(oneCardIsSelected == false)
    {
        if(card->field == -1)
        {
            if(card->level == 4)
            {
                oneCardIsSelected = true;
                selectedCard = card;
                //showCardDetails(card);

               /* if(leader != nullptr)
                    delete leader;
                leader = card->makeCopy(this);
                scene->addItem(leader);
                leader->setPos(180, 685);
                leader->setScale(0.47);
                leader->show();
                deckEditing.leader = leader->cardNumber;*/
            }
            else
            {
                oneCardIsSelected = true;
                //showCardDetails(card);
                selectedCard = card;
            }
        }
    }
    else
    {
        //deleteCardDetails();
        oneCardIsSelected = false;
    }

}

void GameControl::showCardDetails(Card *card)
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

void GameControl::deleteCardDetails()
{
    delete bigCardWithDetails;
    delete remark;
    delete skill;
}
