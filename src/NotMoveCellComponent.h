#ifndef _NotMoveCellComponent_
#define _NotMoveCellComponent_

#include "FlushCellComponent.h"
#include "IO.h"

class NotMoveCellComponent : public FlushCellComponent, public IO
{
public:
	NotMoveCellComponent() : FlushCellComponent(new hgeSprite(_hge->Texture_Load("NOT_MOVE.png"), 0, 0, CELL_SIZE, CELL_SIZE), 0, 0, CELL_SIZE, CELL_SIZE){};
};

#endif