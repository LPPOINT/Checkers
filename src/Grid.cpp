#include "Grid.h"
#include "Checker.h"
#include <iostream>
#include "SelectedCheckerCellComponent.h"
#include "CheckerFlushCellComponent.h"
#include "MoveCellComponent.h"
#include "NotMoveCellComponent.h"

Grid::Grid()
{
   bool white = 1;
   GameCell::CellColor curColor;

   for(int i = 0; i < MAX_CELL_NUM; i++)
   {
	   for(int j = 0; j < MAX_CELL_CHAR; j++)
	   {
	     if(white)
			 curColor = GameCell::_WHITE;
		 if(!white)
			 curColor = GameCell::_BLACK;

		 white = !white;

		 GameCell::CellLocChar cl = (GameCell::CellLocChar)j;
		 GameCell::CellLocNum  nl = (GameCell::CellLocNum)i;
		 
		 GameCell* cell = new GameCell(nl, cl, curColor);
		 
		 if(curColor==GameCell::_BLACK)
			 switch (cl)
		 {
			 case GameCell::_A:
			 case GameCell::_B:
			 case GameCell::_C:
				 new Checker(cell, Checker::_WHITE);
				 break;
			 case GameCell::_D:
				 break;
			 case GameCell::_E:
				 break;
			 case GameCell::_F:
			 case GameCell::_G:
			 case GameCell::_H:
				  new Checker(cell, Checker::_BLACK);
				 break;
			 default:
				 break;
		 }


		 _cells.push_back(cell);

	   }

	   white = !white;
   }
		   
}

std::vector<Checker*> Grid::GetAllChecker(Checker::CheckerColor clr)
{
	std::vector<Checker*> c;
	for(int i = 0; i < _cells.size(); i++)
	{
		if(GetChecker(_cells[i]))
			if(GetChecker(_cells[i])->GetColor()==clr)
			    c.push_back(GetChecker(_cells[i]));
	}
	return c;
}

void Grid::Reset()
{
	std::vector<Checker*> c1 = Grid::GetAllChecker(Checker::_WHITE);
	std::vector<Checker*> c2 = Grid::GetAllChecker(Checker::_BLACK);
	c1.insert(c1.end(), c2.begin(), c2.end());
	for(int i = 0; i < c1.size(); i++)
	{
		c1[i]->Eat();
	}

}

bool Grid::UpdateCell(GameCell* cell, Checker::CheckerColor clr)
{

	for(int i = 0; i < _specCells.size(); i++)
	{
	if(_specCells[i].first)
	  {
		if(cell&&_specCells[i].first->Equals(cell))
		{
			if(_selectedChecker)
			{
				
			   bool val = _selectedChecker->CreateMove(_specCells[i].second)._sucsessful;
			   _selectedChecker = nullptr;
			  for(int i = 0; i < _specCells.size(); i++)
			  {
				  if(_specCells[i].first)
				  {
				    if(GetChecker(_specCells[i].first))
			        {
					   // _specCells[i].first->EraseComponent(new CheckerFlushCellComponent);
				    }
				     else   _specCells[i].first->EraseComponent(new MoveCellComponent); 
				    }
			  }
			  _specCells.clear();
			  return val;
			}
		}
	  }
	}

	Checker* checker;

	if((checker = GetChecker(cell)))
	{
		if(checker->GetColor()==clr)
		{
			for(int i = 0; i < _specCells.size(); i++)
			{
				if(_specCells[i].first) 
				{
					_specCells[i].first->EraseComponent(new MoveCellComponent);
					Checker* hasChecker;
					if((hasChecker = GetChecker(_specCells[i].first))&&hasChecker->GetColor()==clr)
						_specCells[i].first->AddComponent(new CheckerFlushCellComponent);
				}
			}
		  _specCells.clear();
		  _specCells = checker->GetSteps();
		  for(int i = 0; i < _specCells.size(); i++)
		  {
			  if(_specCells[i].first)
				 if(!GetChecker(_specCells[i].first)) _specCells[i].first->AddComponent(new MoveCellComponent);
		  }
		  _selectedChecker = checker;
		}
	}

	return false;

}

void Grid::SelectCheker(Checker::CheckerColor clr)
{
	Checker* checker;
	for(int i = 0; i < _cells.size(); i++)
	{
		if(checker = GetChecker(_cells[i]))
		{
			if(checker->GetColor()==clr)
			{
				checker->GetCell()->AddComponent(new CheckerFlushCellComponent);
			}
			else if(checker->GetColor()!=clr)
			{
				checker->GetCell()->EraseComponent(new CheckerFlushCellComponent);
			}
		}
		else _cells[i]->EraseComponent(new CheckerFlushCellComponent);
	}
}

Grid* Grid::Get()
{
  static Grid* self;
  if(!self)
	  self = new Grid();
  return self;
}

GameCell* Grid::GetCell(GameCell::CellLocNum nc, GameCell::CellLocChar cc)
{

	for(int i = 0; i < _cells.size(); i++)
		if(_cells[i]->GetLoc().first == nc && _cells[i]->GetLoc().second == cc)
			return _cells[i];
	return nullptr;

}

GameCell* Grid::GetCell(float x, float y)
{

	for(int i = 0; i < _cells.size(); i++)
		if(_cells[i]->GetPos().x<=x&&
			x<=_cells[i]->GetPos().x+CELL_SIZE)
			  if(_cells[i]->GetPos().y<=y && y<=_cells[i]->GetPos().y+CELL_SIZE)
			     return _cells[i];
	return nullptr;

}



Checker* Grid::GetChecker(Cell* c)
{
	if(c)
	 {
		 Checker* ch;
		 std::vector<CellComponent*> _c = c->GetComponents();
		 for(int i = 0; i < _c.size(); i++)
			 if((ch = dynamic_cast<Checker*>(_c[i])))
				 return ch;
		 return nullptr;
	 }
	 return nullptr;
}

void Grid::Render()
{
	for(int i = 0; i < _cells.size(); i++)
		_cells[i]->Render();
}