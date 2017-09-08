#include "DeckControl.h"
#include "ui_DeckControl.h"
#include <QSignalMapper>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>

DeckControl::DeckControl(QMainWindow *mainWindow, Account *account, QWidget *parent) :
    QWidget(parent)
{
    this->account = account;
    this->mainWindow = mainWindow;
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


    mainWindow->setCentralWidget(this);
    this->show();
    QEventLoop loop;
    connect(ui->goBackButton, SIGNAL(clicked(bool)), &loop, SLOT(quit()));
    connect(m, SIGNAL(mapped(int)), this, SLOT(loadDeck(int)));
    loop.exec();

}

void DeckControl::goBack()
{


}

void DeckControl::loadDeck(int deckNumber)
{
    if(deckNumber == 0)
    {
        QGraphicsScene scene(mainWindow);
        QGraphicsView view(&scene);
       // view.show();

  //      QImage image(":/card/Gwent Cards/001_VranWarrior.png");
  //      QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        Card001 *card = new Card001(this);
        scene.addItem(card);
        view.setSceneRect(0,0,1800,1000);
        mainWindow->setCentralWidget(&view);
        view.show();

        //mainWindow->setCentralWidget();

        QEventLoop loop;
        loop.exec();
      //  mainWindow->setCentralWidget(view);

        //QWidget *widget = new QWidget();
      //  Card *card = new Card001(widget);

        //mainWindow->setCentralWidget(widget);
    }

}
