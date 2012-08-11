#ifndef _Checker_
#define _Checker_


#include "SpriteCellComponent.h"
#include "IO.h"
#include "Move.h"
#include "GameCell.h"


class Checker : public SpriteCellComponent, public IO
{

public:



	enum CheckerColor
	{
	
		_WHITE,
		_BLACK

	};

	enum MoveList
	{
	  _UP_1 = 0,
	  _UP_2 = 1,
	  _DOWN_1 = 2,
	  _DOWN_2 = 3,
	  _EAT_UP_1 = 4,
	  _EAT_UP_2 = 5,
	  _EAT_DOWN_1 = 6,
	  _EAT_DOWN_2 = 7,
	};

	hgeSprite* GetSprite(CheckerColor color);

private:

	CheckerColor _color;
	HEFFECT _setSnd;

public:
	std::pair<GameCell::CellLocNum, GameCell::CellLocChar> GetCellLoc(Cell* curCell, MoveList mList);
	std::vector<std::pair<GameCell*, Checker::MoveList>> GetSteps();

    Move CreateMove(MoveList ml);
	bool CanEat();
	void EatChecker(Checker* cheker);
	Checker* GetEatedChecker(MoveList move);
	void Eat();
	bool IsLegalMove(MoveList move);

	void SetCell(Cell* c);

	bool Equals(CellComponent* c);

	CheckerColor GetColor() { return _color; }

	Checker(Cell* cell, CheckerColor color);




};

#endif