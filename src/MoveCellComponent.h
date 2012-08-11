#ifndef _MoveCellComponent_
#define _MoveCellComponent_

#include "FlushCellComponent.h"
#include "IO.h"

class MoveCellComponent : public FlushCellComponent, public IO
{
public:
	MoveCellComponent() : FlushCellComponent(new hgeSprite(_hge->Texture_Load("MOVE.png"), 0, 0, CELL_SIZE, CELL_SIZE), 0, 0, CELL_SIZE, CELL_SIZE){};
};

#endif