#ifndef _Move_
#define _Move_

#include "Cell.h"
#include <vector>

struct Move
{
	std::pair<Cell*, Cell*> _move;
	bool _sucsessful;
};

#endif