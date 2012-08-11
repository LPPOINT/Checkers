
#include "SpriteCellComponent.h"
#include <iostream>

SpriteCellComponent::SpriteCellComponent(hgeSprite* spr, float x, float y, float sx, float sy) : 
	Sprite(spr, 0, 0, sx, sy)
{
  _myx= x;
  _myy = y;
}


void SpriteCellComponent::SetCell(Cell* c)
{
	CellComponent::SetCell(c);
	SetPos(c->GetPos().x+_myx, c->GetPos().y+_myy);
}

bool SpriteCellComponent::Equals(CellComponent* c)
{
	SpriteCellComponent* sc = dynamic_cast<SpriteCellComponent*>(c);
	if(sc)
	  return GetPos().x==sc->GetPos().x&&GetPos().x==sc->GetPos().y;
	return false;
}