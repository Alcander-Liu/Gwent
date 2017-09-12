#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->menuWidget->setFixedSize(QSize(500,500));
    //this->setGeometry(0,0,500,500);
   // ui->menuWidget->setStyleSheet("{ width: 500px; height: 500px; }");
    this->setCentralWidget(ui->menuWidget);
/*
    scene = new QGraphicsScene(ui->menuWidget);
    view = new QGraphicsView(scene);
      //  setCentralWidget(view);
    QImage image(":/card/Gwent Cards/001_VranWarrior.png");
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    view->show();
*/


    connect(ui->deckButton, SIGNAL(clicked(bool)), this, SLOT(goToDeck()));
    connect(ui->multiModeButton, SIGNAL(clicked(bool)), this, SLOT(goToMultiMode()));

    account = new Account(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToDeck()
{
    ui->menuWidget->hide();

    deckControl = new DeckControl(account, this);
    deckControl->run();
    delete deckControl;

    ui->menuWidget->show();
}

void MainWindow::goToMultiMode()
{
    ui->menuWidget->hide();

 //   gameControl = new GameControl(account, this);
    delete gameControl;

    ui->menuWidget->show();
}

