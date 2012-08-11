#ifndef _SelectedCheckerCellComponent_
#define _SelectedCheckerCellComponent_

#include "FlushCellComponent.h"
#include "IO.h"

class SelectedCheckerCellComponent : public FlushCellComponent, public IO
{
public:
	SelectedCheckerCellComponent() : FlushCellComponent(new hgeSprite(_hge->Texture_Load("SELECTED_CHECKER.png"), 0, 0, CELL_SIZE, CELL_SIZE), 0, 0, CELL_SIZE, CELL_SIZE){};
	bool Equals(CellComponent* c) { return (bool)dynamic_cast<SelectedCheckerCellComponent*>(c); }
};

#endif