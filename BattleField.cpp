#include "BattleField.h"

BattleField::BattleField(QObject *parent): Field(parent)
{
    for(int i = 0; i<8; i++)
    {
        lanes[i] = new Field(this);
    }
    scores = 0;
    enabled = false;
}

int BattleField::countScores()
{
    scores = lanes[1]->countScores() + lanes[2]->countScores() + lanes[3]->countScores();
    emit scoresChanged("<font color = white size = 10 face = HalisGR-Bold>" +QString::number(scores)+"</font>");
    return scores;
}
