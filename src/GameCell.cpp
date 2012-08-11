#include "GameCell.h"
#include "Grid.h"

GameCell::GameCell(CellLocNum cl, CellLocChar cc, CellColor clr) 
	: Cell(CELL_START_X+cl*CELL_SIZE, CELL_START_Y+cc*CELL_SIZE, GetSprite(clr))
{
  _cLoc = cc;
  _nLoc = cl;
  _color = clr;
}

std::pair<GameCell::CellLocNum, GameCell::CellLocChar> GameCell::GetLoc()
{
	return std::make_pair(_nLoc, _cLoc);
}

std::pair<std::string, std::string> GameCell::GetStringLoc()
{
	std::string n;
	std::string c;
	std::pair<std::string, std::string> p;

	switch (GetLoc().second)
	{
	case CellLocChar::_A:
		c+="A";
        break;
	case CellLocChar::_B:
		c+="B";
        break;
	case CellLocChar::_C:
		c+="C";
        break;
	case CellLocChar::_D:
		c+="D";
        break;
	case CellLocChar::_E:
		c+="E";
        break;
	case CellLocChar::_F:
		c+="F";
        break;
	case CellLocChar::_G:
		c+="G";
        break;
	case CellLocChar::_H:
		c+="H";
        break;
	default:
		break;
	}

	p.first = c;

	switch (GetLoc().first)
	{

	case CellLocNum::_1:
		n+="1";
		break;
	case CellLocNum::_2:
		n+="2";
		break;
	case CellLocNum::_3:
		n+="3";
		break;
	case CellLocNum::_4:
		n+="4";
		break;
	case CellLocNum::_5:
		n+="5";
		break;
	case CellLocNum::_6:
		n+="6";
		break;
	case CellLocNum::_7:
		n+="7";
		break;
	case CellLocNum::_8:
		n+="8";
		break;

	default:
		break;
	}

	p.second = n;

	return p;

}

GameCell::CellColor GameCell::GetColor()
{
	 return _color;
}

bool GameCell::Equals(GameCell* gc)
{

	return GetLoc() == gc->GetLoc();

}

hgeSprite* GameCell::GetSprite(CellColor c)
{
	if(!_hge) _hge = hgeCreate(HGE_VERSION);
	switch (c)
	{
	case GameCell::_WHITE:
		return new hgeSprite(_hge->Texture_Load("FIGURE_WHITE.png"),0, 0, CELL_SIZE, CELL_SIZE);
		break;
	case GameCell::_BLACK:
		return new hgeSprite(_hge->Texture_Load("FIGURE_BLACK.png"),0, 0, CELL_SIZE, CELL_SIZE);
		break;
	default:
		break;
	}
}