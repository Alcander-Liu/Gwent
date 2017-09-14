#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Field.h"
#include <QObject>

class BattleField: public Field
{
    Q_OBJECT
public:
    BattleField(QObject *parent = nullptr);
    ~BattleField();


public:
    Field *lanes[8];
    bool enabled;
    int countScores();

    //1: Melee;  2: Ranged;  3: siege; 0: special;
};

#endif
