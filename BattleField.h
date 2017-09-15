#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Field.h"
#include <QObject>

class BattleField: public Field
{
    Q_OBJECT
public:
    BattleField(QObject *parent = nullptr);

public:
    Field *lanes[8];
    bool enabled;
    int countScores();

    //lanes[1]: Melee;  lanes[2]: Ranged;  lanes[3]: siege; lanes[0]: special;
    
};

#endif
