#include "Timer.h"

void Timer::Update(float msec)
{
  if((_msec+=msec)>1000)
  {
    _sec++;
	_msec-= 1000;
  }

}