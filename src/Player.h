#ifndef _Player_
#define _Player_


#include "MoveCellComponent.h"
#include "Timer.h"
#include "Grid.h"
#include "Checker.h"
#include <HGE\hgefont.h>

#define WHITE_PLAYER_TIMER_X 1069
#define WHITE_PLAYER_TIMER_Y 797

#define BLACK_PLAYER_TIMER_X 1069
#define BLACK_PLAYER_TIMER_Y 214

class Player : public IO
{

protected:

	Timer* _timer;
	static Grid* _grid;
	Checker::CheckerColor _mycolor;
	hgeFont* _fnt;

public:

	virtual bool Update();
	void Render();

	Checker::CheckerColor GetColor() { return _mycolor; } 
	bool Equals(Player* p) { return _mycolor == p->GetColor(); }

	virtual void Init();

	Player(Checker::CheckerColor);

};

#endif