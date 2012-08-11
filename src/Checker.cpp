#include "Checker.h"
#include "Grid.h"
#include "CheckerFlushCellComponent.h"
#include "StepBlank.h"
#include <iostream>
#include "SelectedCheckerCellComponent.h"
#include "NotMoveCellComponent.h"

Checker::Checker(Cell* cell, CheckerColor color) : SpriteCellComponent(GetSprite(color), 0, 0, CELL_SIZE, CELL_SIZE)
{
	_color = color;
	cell->AddComponent(this);
	if(!_hge) _hge = hgeCreate(HGE_VERSION); 
	_setSnd = _hge->Effect_Load("111.wav");
}

void  Checker::SetCell(Cell* c)
{
	SpriteCellComponent::SetCell(c);
	if(!_hge) _hge = hgeCreate(HGE_VERSION);
	_hge->Effect_Play(_setSnd);
}

std::vector<std::pair<GameCell*, Checker::MoveList>> Checker::GetSteps()
{

	std::pair<GameCell*, Checker::MoveList> step;
	std::vector<std::pair<GameCell*, Checker::MoveList>> stepVec;
	GameCell* myCell = dynamic_cast<GameCell*>(GetCell());

	bool ret=false;

   for(int i = _EAT_UP_1; i <= _EAT_DOWN_2; i++ )
	{
	  if(GetEatedChecker((Checker::MoveList)i))
	  {
		  if((GetEatedChecker( (Checker::MoveList)i)->GetColor())!=GetColor())
		  {
			std::pair<GameCell::CellLocNum, GameCell::CellLocChar> tmp =  GetCellLoc(GetEatedChecker( (Checker::MoveList)i)->GetCell(), (Checker::MoveList)(i - 4));
			if(!Grid::Get()->GetChecker(Grid::Get()->GetCell(tmp.first, tmp.second)))
			{
				if(Grid::Get()->GetCell(tmp.first, tmp.second))
				{
		        step.second = (Checker::MoveList)i;
		        step.first = Grid::Get()->GetCell(GetCellLoc(GetCell(), (Checker::MoveList)i).first, GetCellLoc(GetCell(), (Checker::MoveList)i).second );
	            stepVec.push_back(step);
			    ret = true;
				}
			}
		  }
     	}
	}

   if(ret) return stepVec;
	   

	for(int i = 0; i <= _DOWN_2; i++ )
	{
	  	step.second = (Checker::MoveList)i;
		step.first = Grid::Get()->GetCell(GetCellLoc(GetCell(), (Checker::MoveList)i).first, GetCellLoc(GetCell(),(Checker::MoveList)i).second );
	    stepVec.push_back(step);
	}


	return stepVec;

}

Checker* Checker::GetEatedChecker(MoveList move)
{
	switch (move)
	{
	case Checker::_EAT_UP_1:
	case Checker::_EAT_UP_2:
	case Checker::_EAT_DOWN_1:
	case Checker::_EAT_DOWN_2:
		return Grid::Get()->GetChecker(Grid::Get()->GetCell(GetCellLoc(GetCell(), (MoveList)(move-4)).first, GetCellLoc(GetCell(), (MoveList)(move-4)).second));
	default:
		break;
	}
	return nullptr;
}

std::pair<GameCell::CellLocNum, GameCell::CellLocChar> Checker::GetCellLoc(Cell* cell, MoveList mList)
{

  GameCell* myCell = dynamic_cast<GameCell*>(cell);

   GameCell::CellLocNum  n; 
   GameCell::CellLocChar c;
   int pNum = 1;
   switch (mList)
   {
   case Checker::_UP_1:

	   n =  (GameCell::CellLocNum)(int)((myCell->GetLoc().first)-pNum);
	   c =  (GameCell::CellLocChar)(int)((myCell->GetLoc().second)-pNum);

	   break;
   case Checker::_UP_2:

	   n =  (GameCell::CellLocNum)(int)((myCell->GetLoc().first)+pNum);
	   c =  (GameCell::CellLocChar)(int)((myCell->GetLoc().second)-pNum);

	   break;
   case Checker::_DOWN_1:

	   n =  (GameCell::CellLocNum)(int)((myCell->GetLoc().first)-pNum);
	   c =  (GameCell::CellLocChar)(int)((myCell->GetLoc().second)+pNum);

	   break;
   case Checker::_DOWN_2:

	   
	   n =  (GameCell::CellLocNum)(int)((myCell->GetLoc().first)+pNum);
	   c =  (GameCell::CellLocChar)(int)((myCell->GetLoc().second)+pNum);

	   break;
   case Checker::_EAT_UP_1:

	   
	   n =  (GameCell::CellLocNum)(int)((myCell->GetLoc().first)-2);
	   c =  (GameCell::CellLocChar)(int)((myCell->GetLoc().second)-2);

	   break;
	case Checker::_EAT_UP_2:

	   
	   n =  (GameCell::CellLocNum)(int)((myCell->GetLoc().first)+2);
	   c =  (GameCell::CellLocChar)(int)((myCell->GetLoc().second)-2);

	   break;
	 case Checker::_EAT_DOWN_1:


	   n =  (GameCell::CellLocNum)(int)((myCell->GetLoc().first)-2);
	   c =  (GameCell::CellLocChar)(int)((myCell->GetLoc().second)+2);

	   break;
	 case Checker::_EAT_DOWN_2:

	   
	   n =  (GameCell::CellLocNum)(int)((myCell->GetLoc().first)+2);
	   c =  (GameCell::CellLocChar)(int)((myCell->GetLoc().second)+2);

	   break;
   default:
	   break;
   }

   std::pair<GameCell::CellLocNum, GameCell::CellLocChar> p;
   p.first = n;
   p.second = c;
   return p;

}

void Checker::Eat()
{
	GetCell()->EraseComponent(this);
	GetCell()->EraseComponent(new CheckerFlushCellComponent);
}

void Checker::EatChecker(Checker* checker)
{
	if(!checker) return;
	checker->Eat();
}

bool Checker::IsLegalMove(Checker::MoveList ml)
{
    std::vector<std::pair<GameCell*, Checker::MoveList>> steps = GetSteps();

	std::vector<Checker*> checkers = Grid::Get()->GetAllChecker(GetColor());
	bool retval=false;
	for(int i = 0; i < checkers.size(); i++)
		if(checkers[i]->CanEat())
		{
			switch (ml)
			{
			case Checker::_UP_1:
			case Checker::_UP_2:
			case Checker::_DOWN_1:
			case Checker::_DOWN_2:
				checkers[i]->GetCell()->AddComponent(new CheckerFlushCellComponent);
			    if(!retval)
				{
					Beep(294, 1000/8);
					StepBlank::Get()->AddNode(new StepBlankNode("You should jump!", new hgeColor(255, 255, 0, 255), Checker::_WHITE));
				}
				retval =  true;
				break;
			case Checker::_EAT_UP_1:
				break;
			case Checker::_EAT_UP_2:
				break;
			case Checker::_EAT_DOWN_1:
				break;
			case Checker::_EAT_DOWN_2:
				break;
			default:
				break;
			}
		}
		if(retval) return false;
	  for(int i = 0; i < steps.size(); i++)
	  {
		  if((((int)(steps[i].second)>=_EAT_UP_1))&&((int)((steps[i].second)<=_EAT_DOWN_2)))
		  {
			  if(((int)(ml)>=_EAT_UP_1)&&((int)(ml)<=_EAT_DOWN_2))
			  {
				 return true;
			  }    
			  return false;
		  }
	  }
	 
	return true;
}

bool Checker::CanEat()
{
  std::vector<std::pair<GameCell*, Checker::MoveList>> steps = GetSteps();
   for(int i = 0; i < steps.size(); i++)
   {
     if((((int)(steps[i].second)>=_EAT_UP_1))&&((int)((steps[i].second)<=_EAT_DOWN_2)))
		 return true;
   }
   return false;
}

Move Checker::CreateMove(Checker::MoveList ml)
{
   Move move;
   GameCell* newCell;
   GameCell* myCell = dynamic_cast<GameCell*>(GetCell());
   std::string nodeStr = myCell->GetStringLoc().second+myCell->GetStringLoc().first+"-";
   move._move.first = GetCell();
   move._sucsessful = true;


   GameCell::CellLocNum  n = GetCellLoc(GetCell(), ml).first; 
   GameCell::CellLocChar c = GetCellLoc(GetCell(), ml).second;

     	   if(Grid::Get()->GetChecker(
		   newCell =   Grid::Get()->GetCell( n, c )
		   )==nullptr&&IsLegalMove(ml)) 
		   {
			   if(newCell)
			   {
				   if(ml>=_EAT_UP_1&&ml<=_EAT_DOWN_2)
				   {
				     GetEatedChecker(ml)->Eat();
					 GameCell* tmp = myCell;
					 GetCell()->EraseComponent(this);
					 newCell->AddComponent(this);
						 if(CanEat())
						 {
							 GetCell()->EraseComponent(new SelectedCheckerCellComponent);
							 GetCell()->AddComponent(new CheckerFlushCellComponent);
							 move._sucsessful = false;
							 tmp->EraseComponent(new CheckerFlushCellComponent);
						 }
				   }
				   else {
				   	GetCell()->EraseComponent(this);
				    newCell->AddComponent(this);
				   }

			     nodeStr+=newCell->GetStringLoc().second+newCell->GetStringLoc().first;
		    	 StepBlank::Get()->AddNode(new StepBlankNode(nodeStr, GetColor()));
				 move._move.second = GetCell();
				 return move;
				 move._sucsessful = false;
 			   }
		   } else move._sucsessful = false;
		   return move;

}

bool Checker::Equals(CellComponent* c)
{
	return (bool)dynamic_cast<Checker*>(c);
}

hgeSprite* Checker::GetSprite(CheckerColor color)
{
	if(!_hge) _hge = hgeCreate(HGE_VERSION);
	switch (color)
	{
	case Checker::_WHITE:
		return new hgeSprite(_hge->Texture_Load("CHECKER_WHITE.png"), 0, 0, CELL_SIZE, CELL_SIZE);
		break;
	case Checker::_BLACK:
		return new hgeSprite(_hge->Texture_Load("CHECKER_BLACK.png"), 0, 0, CELL_SIZE, CELL_SIZE);
		break;
	default:
		break;
	}
}