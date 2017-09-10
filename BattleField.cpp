#include "BattleField.h"

BattleField::BattleField(QObject *parent): Field(parent)
{
    lanes[0] = new Field(this);
    lanes[1] = new Field(this);
    lanes[2] = new Field(this);
    lanes[3] = new Field(this);
}

BattleField:: ~BattleField()
{
    delete lanes[0];
    delete lanes[1];
    delete lanes[2];
    delete lanes[3];
}
