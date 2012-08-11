#ifndef _Sprite_
#define _Sprite_




#include <HGE\hgesprite.h>
#include <HGE\hgerect.h>
#include "IO.h"

class Sprite
{

private:

	hgeSprite* _spr;
	hgeRect*   _rect;

public:

    Point GetPos();
	void  SetPos(float x, float y);
	virtual void Render();

	Sprite(hgeSprite* spr, float x, float y, float sx, float sy);
	~Sprite();
};

#endif