#include "Cell.h"
#include <iostream>
#include "FlushCellComponent.h"

Cell::Cell(float x, float y, hgeSprite* spr) : Sprite(spr, x, y, CELL_SIZE, CELL_SIZE)
{

}

void Cell::Render()
{
	Sprite::Render();
	for(int i = 0; i < _components.size(); i++)
		_components[i]->Render();

}



void Cell::AddComponent(CellComponent* c)
{
	for(int i = 0; i < _components.size(); i++)
		if(_components[i]->Equals(c))
			return;
	c->SetCell(this);
	_components.push_back(c);
}

void Cell::EraseComponent(CellComponent* c)
{
	for(int i = 0; i < _components.size(); i++)
		if(_components[i]->Equals(c))
			_components.erase(_components.begin()+i);
}

Cell::~Cell()
{
}
