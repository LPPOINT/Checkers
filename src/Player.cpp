#include "Player.h"
#include "CheckerFlushCellComponent.h"
#include "SelectedCheckerCellComponent.h"
#include <iostream>

Grid* Player::_grid = NULL;

Player::Player(Checker::CheckerColor clr)
{
	_timer =  new Timer();
	_mycolor = clr;
	_fnt = new hgeFont("font1.fnt");
}

void  Player::Init()
{
 	Grid::Get()->SelectCheker(_mycolor);
	_timer->Reset();
}

void Player::Render()
{
	//switch (_mycolor)
	//{
	//case Checker::_WHITE:
	//	_fnt->printf(WHITE_PLAYER_TIMER_X, WHITE_PLAYER_TIMER_Y, 3, "%f : %f", _timer->GetSec(), _timer->GetMsec());
	//	break;
	//case Checker::_BLACK:
	//	_fnt->printf(BLACK_PLAYER_TIMER_X, BLACK_PLAYER_TIMER_Y, 3, "%f : %f", _timer->GetSec(), _timer->GetMsec());
	//	break;
	//default:
	//	break;
	//}
}

bool Player::Update()
{
	//static bool pressed = false;
	//if(!_hge)_hge = hgeCreate(HGE_VERSION);
	//_timer->Update(_hge->Timer_GetDelta());
	//if(!_hge->Input_GetKeyState(HGEK_LBUTTON)) pressed = false;
 //     if(!pressed)
	//  {
	//   if(_hge->Input_IsMouseOver())
	//   {
	//	   float x, y;
	//       GameCell* cell;
	//	 if(_hge->Input_GetKeyState(HGEK_LBUTTON)||_hge->Input_GetKeyState(HGEK_RBUTTON))
	//	 {
	//		 pressed = true;
	//		 _hge->Input_GetMousePos(&x, &y); 
	//	     return  Grid::Get()->UpdateCell(Grid::Get()->GetCell(x, y), _mycolor);


	//	 } else pressed = false;
	//   } 
	//  }
	//   return false;
		if(!_hge)_hge = hgeCreate(HGE_VERSION);
	_timer->Update(_hge->Timer_GetDelta());
	   if(_hge->Input_IsMouseOver())
	   {
		   float x, y;
	       GameCell* cell;
		 if(_hge->Input_GetKeyState(HGEK_LBUTTON)||_hge->Input_GetKeyState(HGEK_RBUTTON))
		 {
		   _hge->Input_GetMousePos(&x, &y);
		   return Grid::Get()->UpdateCell(Grid::Get()->GetCell(x, y), _mycolor);

		 }
	   }
	   return false;
}