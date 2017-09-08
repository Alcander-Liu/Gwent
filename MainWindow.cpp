#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->deckButton, SIGNAL(clicked(bool)), this, SLOT(goToDeck()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToDeck()
{
    deckControl.show();
}
