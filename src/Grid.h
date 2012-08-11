#ifndef _Grid_
#define _Grid_




#include "GameCell.h"
#include "Checker.h"

class Grid
{

private:

	std::vector<GameCell*> _cells;
	std::vector<std::pair<GameCell*, Checker::MoveList>> _specCells;
	Checker*              _selectedChecker;


public:

	static Grid* Get();

	void SelectCheker(Checker::CheckerColor);
	bool UpdateCell(GameCell* cell, Checker::CheckerColor clr);
	std::vector<Checker*> GetAllChecker(Checker::CheckerColor);
	void Render();
	void Update();
	void Reset();


	GameCell* GetCell(GameCell::CellLocNum, GameCell::CellLocChar);
	GameCell* GetCell(float x, float y);
	Checker*  GetChecker(Cell* c);

	Grid();
	~Grid();

};

#endif