#ifndef _SpriteCellComponent_
#define _SpriteCellComponent_


#include "CellComponent.h"
#include "Sprite.h"
#include <iostream>

class SpriteCellComponent : public CellComponent, public Sprite
{

	float _myx;
	float _myy;

public:

	void SetSprite(hgeSprite* spr);

	virtual void SetCell(Cell* c);

	void Render() { Sprite::Render(); }

	virtual bool Equals(CellComponent* c);

    SpriteCellComponent( hgeSprite* spr, float x, float y, float sx, float sy);


};

#endif