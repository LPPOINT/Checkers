
#include <iostream>
#include "Sprite.h"

Sprite::Sprite(hgeSprite* spr, float x, float y, float sx, float sy)
{

	_spr = spr;
	_rect = new hgeRect();
	_rect->Set(x, y, x+sx, y+sy);

};

Sprite::~Sprite()
{
  delete _rect;
  delete _spr;
}

void Sprite::SetPos(float x, float y)
{
	float sx = _rect->x2-_rect->x1;
	float sy = _rect->y2-_rect->y1;
	_rect->Set(x, y, sx, sy);
}

void Sprite::Render()
{
	//_spr->RenderEx(GetPos().x, GetPos().y, 0, (_rect->y2-_rect->y1)/_spr->GetHeight(), (_rect->x2-_rect->x1)/ _spr->GetWidth() );
	_spr->RenderEx(GetPos().x, GetPos().y, 0, 1, 0);
}

Point Sprite::GetPos()
{
  Point p;
  p.x = _rect->x1;
  p.y = _rect->y1;
  return p;
}