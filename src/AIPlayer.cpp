
#include "AIPlayer.h"

bool AIPlayer::Update()
{

	static float timer = 0;
	timer += _hge->Timer_GetDelta();
	if(timer >= AIPLAYER_STEP_TIME)
	{
	  timer = 0;
	  std::vector<Checker*> checkers = Grid::Get()->GetAllChecker(_mycolor);
	  for(int i = 0; i < checkers.size(); i++)
	  {
		  if(checkers[i]->CanEat())
		  {
			  std::vector<std::pair<GameCell*, Checker::MoveList>> steps = checkers[i]->GetSteps();
			  for(int i = 0; i < steps.size(); i++)
			  {
				  if(steps[i].second>=Checker::_EAT_UP_1&&steps[i].second<=Checker::_EAT_DOWN_2)
				  {
					  return checkers[i]->CreateMove(steps[i].second)._sucsessful;
		          }
			   }
		  }
	  }

	  srand(time(NULL));
	  int rnd = rand() % checkers.size() + 0;
	  std::vector<std::pair<GameCell*, Checker::MoveList>> steps = checkers[rnd]->GetSteps();
	  int srnd = rand() % steps.size() + 0 ;
	  Grid::Get()->UpdateCell(dynamic_cast<GameCell*>(checkers[rnd]->GetCell()), _mycolor);
	  return Grid::Get()->UpdateCell(steps[srnd].first, _mycolor );
	}
	return false;
	
};