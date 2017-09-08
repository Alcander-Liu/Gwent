#ifndef LANE_H
#define LANE_H

#include "Field.h"

class Lane : public Field
{
public:
    Lane();

public:
    Field melee;
    Field ranged;
    Field Siege;
};

#endif // LANE_H
