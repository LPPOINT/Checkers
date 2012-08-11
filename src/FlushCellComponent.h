#ifndef _FlushCellComponent_
#define _FlushCellComponent_

#include "SpriteCellComponent.h"
#include <iostream>

class FlushCellComponent : public SpriteCellComponent
{

public:

    bool Equals(CellComponent* c);
	FlushCellComponent(hgeSprite* spr, float x, float y, float sx, float sy) : SpriteCellComponent(spr, x, y, sx, sy){};

};

#endif