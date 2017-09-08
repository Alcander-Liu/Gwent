#include "DeckControl.h"
#include "ui_DeckControl.h"


DeckControl::DeckControl(QWidget *parent) :
    QWidget(parent)
{
    ui = new Ui::Form;
    ui->setupUi(this);
}


DeckControl::~DeckControl()
{
    delete ui;
}
