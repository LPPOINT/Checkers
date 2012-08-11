#ifndef _CellComponent_
#define _CellComponent_

class Cell;

#include "Cell.h"
#include <iostream>

class CellComponent
{
	Cell* _myCell;

public:

	virtual void SetCell(Cell* mcell); 
	Cell* GetCell() {  return _myCell; }
	virtual bool Equals(CellComponent* c){ return 0; };
	bool operator!=(CellComponent* c);

	virtual void Render(){};

	CellComponent();

};

#endif