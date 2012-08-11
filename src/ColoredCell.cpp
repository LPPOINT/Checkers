
#include "ColoredCell.h"
#include "SpriteCellComponent.h"
#include "Sprite.h"
#include "GameCell.h"
#include "Grid.h"
#include "Checker.h"
#include <iostream>
#include "Player.h"
#include "AIPlayer.h"
#include "StepBlank.h"


hgeSprite* ColoredCell::GetSprite(hgeColor* color)
{

	DWORD clr = color->GetHWColor();
	if(!_hge) _hge = hgeCreate(HGE_VERSION);
	  HTARGET target = _hge->Target_Create(CELL_SIZE, CELL_SIZE, false);
	  _hge->Gfx_BeginScene(target);
	  _hge->Gfx_Clear(clr);
	  _hge->Gfx_EndScene();
	  hgeSprite* spr = new hgeSprite(_hge->Target_GetTexture(target), 0, 0, CELL_SIZE, CELL_SIZE);
	  return spr;

}

hgeSprite* ColoredCell::GetSprite()
{
	return GetSprite(_color);
}

ColoredCell::ColoredCell(hgeColor* color, float x, float y) : Cell(x, y, GetSprite(color))
{
	_color = color;
}

ColoredCell::~ColoredCell()
{
  delete _color;
}

#define WIN_SCREEN_X CELL_END_X + 50 + STEP_BLANK_SIZE_X  // TODO 
#define WIN_SCREEN_Y CELL_END_Y

HGE* hge = NULL;
Player* p = NULL;
Player* p1 = NULL;
Player* p2 = NULL;

bool Render()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(ARGB(255, 231, 189, 140));
	Grid::Get()->Render();
    StepBlank::Get()->Render();
	p->Render();
	hge->Gfx_EndScene();
	return 0;
}

bool Update()
{
	if(p->Update())
	{
	  if(p==p1)
		  p = p2;
	  else if(p == p2)
		  p = p1;
	  	p->Init();
	}
	return 0;
}

void main()
{
	//  TODO    2. fix bug, who not return true after eat

	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_TITLE, "ALPHA 0.7(STABLE)");
	hge->System_SetState(HGE_FRAMEFUNC, Update);
	hge->System_SetState(HGE_RENDERFUNC, Render);
	hge->System_SetState(HGE_SCREENWIDTH, WIN_SCREEN_X);
	hge->System_SetState(HGE_SCREENHEIGHT, WIN_SCREEN_Y);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_FPS, 60);
	hge->System_SetState(HGE_LOGFILE, "log.log");
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_HIDEMOUSE, 0);

	if(hge->System_Initiate())
	{
		
			 p1 = new Player(Checker::_WHITE);
			 p2 = new Player(Checker::_BLACK);

			p = p2;
			p->Init();

		hge->System_Start();
	}


	hge->System_Shutdown();
	hge->Release();
}