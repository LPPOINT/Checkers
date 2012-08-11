#ifndef _GameCell_
#define _GameCell_




#include "Cell.h"
#include <vector>

class GameCell : public Cell
{

public:


#define  CELL_START_X  0
#define  CELL_START_Y  0
#define  MAX_CELL_NUM  8
#define  MAX_CELL_CHAR 8
#define  CELL_END_X    CELL_START_X + MAX_CELL_NUM  * CELL_SIZE
#define  CELL_END_Y    CELL_START_Y + MAX_CELL_CHAR * CELL_SIZE

	enum CellColor
	{
	
		_WHITE,
		_BLACK

	};

	enum CellLocNum
	{
	  _1 = 0,
	  _2 = 1,
	  _3 = 2,
	  _4 = 3,
	  _5 = 4,
	  _6 = 5,
	  _7 = 6,
	  _8 = 7,
	};

	enum CellLocChar
	{
	
		_A = 0,
		_B = 1,
		_C = 2,
		_D = 3,
		_E = 4,
		_F = 5,
		_G = 6,
		_H = 7,

	};



	hgeSprite* GetSprite(CellColor);

private:

	CellLocChar _cLoc;
	CellLocNum  _nLoc;
	CellColor  _color;

public:

	bool Equals(GameCell* gc);
	std::pair<CellLocNum, CellLocChar> GetLoc();
	std::pair<std::string, std::string> GetStringLoc();
	CellColor                        GetColor();

	GameCell(CellLocNum, CellLocChar, CellColor);

};

#endif