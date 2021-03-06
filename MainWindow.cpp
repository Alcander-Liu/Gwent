#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->menuWidget);

    connect(ui->deckButton, SIGNAL(clicked(bool)), this, SLOT(goToDeck()));
    connect(ui->multiModeButton, SIGNAL(clicked(bool)), this, SLOT(goToGame()));
    connect(ui->exitButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    account = new Account(this);
    account->load();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToDeck()
{
    ui->menuWidget->hide();

    deckControl = new DeckControl(account, this);
    delete deckControl;

    ui->menuWidget->show();
}

void MainWindow::goToGame()
{
    ui->menuWidget->hide();
    
    gameControl = new GameControl(account, this);
    delete gameControl;

    ui->menuWidget->show();
}


