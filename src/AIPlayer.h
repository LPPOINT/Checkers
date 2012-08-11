#ifndef _AIPlayer_
#define _AIPlayer_

#include "Player.h"
#include <time.h>

#define AIPLAYER_STEP_TIME 0.3

class AIPlayer : public Player
{

public:
	void Init(){};
	bool Update();
	AIPlayer(Checker::CheckerColor clr) : Player(clr){};

};

#endif