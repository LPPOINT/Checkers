#ifndef _CheckerFlushCellComponent_
#define _CheckerFlushCellComponent_

#include "FlushCellComponent.h"
#include "IO.h"

class CheckerFlushCellComponent : public FlushCellComponent, public IO
{
public:
	CheckerFlushCellComponent() : FlushCellComponent(new hgeSprite(_hge->Texture_Load("MY_CHECKER.png"), 0, 0, CELL_SIZE, CELL_SIZE), 0, 0, CELL_SIZE, CELL_SIZE){};
};

#endif