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
    connect(this, SIGNAL(exit()), &loop, SLOT(quit()));
    loop.exec();
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
    for(int i = 1; i<4; i++)
    {
        startRound(i);
        if(gameEnd() == true)
            break;
    }
    showResult();
    emit exit();
}

void GameControl::initializeDeck(int deckNumber)
{
    player = new Player(this);
    player->mySide = true;
    opponent = new Player(this);
    opponent->mySide = false;
    player->generateCardsInDeck(account->deck[deckNumber], scene);
    opponent->generateCardsInDeck(account->deck[deckNumber], scene);

    QSignalMapper *m = new QSignalMapper(this);

    for(int i = 1; i<4; i++)
    {
        player->battleField->lanes[i]->setRect(450, 450+i*100, 1020, 96);
        scene->addItem(player->battleField->lanes[i]);
        connect(player->battleField->lanes[i], SIGNAL(fieldPressed()), m, SLOT(map()));
        m->setMapping(player->battleField->lanes[i], i);
    }

    for(int i = 4; i<7; i++)
    {
        player->battleField->lanes[i]->setRect(450, 850-i*100, 1020, 96);
        scene->addItem(player->battleField->lanes[i]);
        connect(player->battleField->lanes[i], SIGNAL(fieldPressed()), m, SLOT(map()));
        m->setMapping(player->battleField->lanes[i], i);
    }

    connect(m, SIGNAL(mapped(int)), this, SLOT(laneSelected(int)));

    QLabel *playersScores[8];
    for(int i = 0; i<8; i++)
    {
        playersScores[i] = new QLabel(this);
        playersScores[i]->show();
    }

    playersScores[0]->setGeometry(330, 670, 80, 80);
    connect(player->battleField, SIGNAL(scoresChanged(QString)), playersScores[0], SLOT(setText(QString)));
    for(int i = 1; i<4; i++)
    {
        playersScores[i]->setGeometry(440, 455+100*i, 80, 80);
        connect(player->battleField->lanes[i], SIGNAL(scoresChanged(QString)), playersScores[i], SLOT(setText(QString)));
    }
    playersScores[4]->setGeometry(300, 370, 80, 80);
    connect(opponent->battleField, SIGNAL(scoresChanged(QString)), playersScores[4], SLOT(setText(QString)));
    for(int i = 5; i<8; i++)
    {
        playersScores[i]->setGeometry(440, 955-100*i, 80, 80);
        connect(opponent->battleField->lanes[i-4], SIGNAL(scoresChanged(QString)), playersScores[i], SLOT(setText(QString)));
    }
    player->battleField->countScores();
    opponent->battleField->countScores();

    discardAmountLabel[0] = new QLabel(this);
    discardAmountLabel[1] = new QLabel(this);
    discardAmountLabel[0]->setGeometry(110, 800, 50, 50);
    discardAmountLabel[1]->setGeometry(110, 250, 50, 50);
    discardAmountLabel[0]->show();
    discardAmountLabel[1]->show();
    connect(player, SIGNAL(discardAmountChanged(QString)), discardAmountLabel[0], SLOT(setText(QString)));
    connect(opponent, SIGNAL(discardAmountChanged(QString)), discardAmountLabel[1], SLOT(setText(QString)));

    TurnPageButton *finishDiscardingButton1 = new TurnPageButton(this);
    TurnPageButton *finishDiscardingButton2 = new TurnPageButton(this);
    finishDiscardingButton1->setRect(30, 780, 330, 50);
    finishDiscardingButton2->setRect(30, 233, 330, 50);
    scene->addItem(finishDiscardingButton1);
    scene->addItem(finishDiscardingButton2);
    connect(finishDiscardingButton1, SIGNAL(buttonPressed()), player, SIGNAL(endDiscarding()));
    connect(finishDiscardingButton2, SIGNAL(buttonPressed()), opponent, SIGNAL(endDiscarding()));

    whoseTurnLabel = new QLabel(this);
    whoseTurnLabel->setGeometry(10, 495, 450, 80);
    whoseTurnLabel->setAlignment(Qt::AlignCenter);
    whoseTurnLabel->show();
    connect(this, SIGNAL(turnChanged(QString)), whoseTurnLabel, SLOT(setText(QString)));

    TurnPageButton *passedButton1 = new TurnPageButton(this);
    TurnPageButton *passedButton2 = new TurnPageButton(this);
    passedButton1->setRect(50, 550, 200, 50);
    passedButton2->setRect(50, 350, 200, 50);
    scene->addItem(passedButton1);
    scene->addItem(passedButton2);
    connect(passedButton1, SIGNAL(buttonPressed()), this, SLOT(playerPassed()));
    connect(passedButton2, SIGNAL(buttonPressed()), this, SLOT(opponentPassed()));

}

void GameControl::startRound(int round)
{
    myTurn = true;
    oneCardIsSelected = false;
    player->passed = false;
    opponent->passed = false;

    player->drawCards_round(round);
    opponent->drawCards_round(round);  // This line should be deleted in online mode.
    player->discardCards(round);
    opponent->discardCards(round);  // This line should be deleted in online mode.

    for(int i = 0; i < player->hand->getCardAmount(); i++)  // This should be deleted in online mode.
    {
        disconnect(player->hand->at(i), SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
        connect(player->hand->at(i), SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
    }

    for(int i = 0; i < opponent->hand->getCardAmount(); i++)  // This should be deleted in online mode.
    {
        disconnect(opponent->hand->at(i), SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
        connect(opponent->hand->at(i), SIGNAL(cardPressed(Card*)), this, SLOT(cardSelected(Card*)));
    }

    while(true)
    {
        if(myTurn == true)
        {
            playCard(player);
        }
        else
        {
            playCard(opponent);
        }
        if(player->passed == true && opponent->passed == true)
            break;
    }

    countSubTotal();
    player->cleanBattleField();
    opponent->cleanBattleField();
}



void GameControl::cardSelected(Card *card)
{
    if(card->selectable == false)
        return;

    if(oneCardIsSelected == false)
    {
        if(card->field == -1)
        {
            if(card->level == 4)
            {
                oneCardIsSelected = true;
                selectedCard = card;
                showCardDetails(card);

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
                showCardDetails(card);
                selectedCard = card;
            }
        }
    }
    else
    {
        deleteCardDetails();
        oneCardIsSelected = false;
    }
}

void GameControl::laneSelected(int lane)
{
     // this block should be delete in online mode
        Player *player;
        if(myTurn == false)
        {
            lane -= 3;
            player = opponent;
        }
        else
            player = this->player;

     // this block should be delete in online mode


    Card *tempCard;
    if(player->battleField->enabled == false)
    {
        return;
    }
    if(oneCardIsSelected == true)
    {
        if(selectedCard->level == 4)
        {
            /*deleteCardDetails();
            oneCardIsSelected = false;*/
        }
        else if(lane == selectedCard->lane)
        {
            player->hand->removeCard(selectedCard);
            player->battleField->lanes[lane]->addCard(selectedCard);
            selectedCard->field = lane;
            player->hand->adjustCardsPosition_Game(0, player->mySide);
            player->battleField->lanes[lane]->adjustCardsPosition_Game(lane, player->mySide);
            //selectedCard->used(lane);
            player->battleField->countScores();
            deleteCardDetails();
            oneCardIsSelected = false;
            emit playerEndTurn();
        }
        else if(selectedCard->lane == -1 )
        {
            player->hand->removeCard(selectedCard);
            player->battleField->lanes[lane]->addCard(selectedCard);
            selectedCard->field = lane;
            player->hand->adjustCardsPosition_Game(0, player->mySide);
            player->battleField->lanes[lane]->adjustCardsPosition_Game(lane, player->mySide);
            //selectedCard->used(lane);
            player->battleField->countScores();
            deleteCardDetails();
            oneCardIsSelected = false;
            emit playerEndTurn();
        }
        else
        {
            deleteCardDetails();
            oneCardIsSelected = false;
        }
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

void GameControl::playCard(Player *player)
{
    if(myTurn == true)
        emit turnChanged("<font color = white size = 7 face = HalisGR-Bold> Your Turn</font>");
    else
        emit turnChanged("<font color = white size = 7 face = HalisGR-Bold> Opponent's Turn</font>");

    if(player->passed != true)
    {
        player->battleField->enabled = true;
        player->setCardsSelectable(true);
        QEventLoop loop;
        connect(this ,SIGNAL(playerEndTurn()) , &loop, SLOT(quit()));
        loop.exec();

        player->battleField->enabled = false;
        player->setCardsSelectable(false);
    }
    myTurn = !myTurn;
}

void GameControl::playerPassed()
{
    if(myTurn == true)
    {
        player->passed = true;
        emit playerEndTurn();
    }
}

void GameControl::opponentPassed()
{
    if(myTurn == false)
    {
        opponent->passed = true;
        emit playerEndTurn();
    }
}

void GameControl::countSubTotal()
{
    QLabel *temp = new QLabel(this);
    temp->setGeometry(800, 450, 800, 200);
    temp->setAlignment(Qt::AlignCenter);
    temp->show();
    if(player->battleField->scores > opponent->battleField->scores)
    {
        player->bigScores ++;
        temp->setText("<font color = white size = 16 face = HalisGR-Bold> You Won This Round!</font>");
    }
    else if(player->battleField->scores < opponent->battleField->scores)
    {
        opponent->bigScores ++;
        temp->setText("<font color = white size = 16 face = HalisGR-Bold> You lost This Round!</font>");
    }
    else
    {
        player->bigScores ++;
        opponent->bigScores ++;
        temp->setText("<font color = white size = 16 face = HalisGR-Bold> Even!</font>");
    }

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start(2000);
    loop.exec();

    delete temp;
}

bool GameControl::gameEnd()
{
    if(player->bigScores == 2 || opponent->bigScores == 2)
        return true;
    else
        return false;
}

void GameControl::showResult()
{
    QLabel *temp = new QLabel(this);
    temp->setGeometry(800, 450, 800, 200);
    temp->setAlignment(Qt::AlignCenter);
    temp->show();
    if(player->bigScores > opponent->bigScores)
    {
        temp->setText("<font color = white size = 16 face = HalisGR-Bold> You Won This Game!</font>");
    }
    else if(player->bigScores < opponent->bigScores)
    {
        temp->setText("<font color = white size = 16 face = HalisGR-Bold> You lost This Game!</font>");
    }
    else
    {
        temp->setText("<font color = white size = 16 face = HalisGR-Bold> Even!</font>");
    }

    QEventLoop loop;
    QTimer timer;
    timer.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start(4000);
    loop.exec();

    delete temp;
}


