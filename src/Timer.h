#ifndef _Timer_
#define _Timer_

class Timer
{

private:

	float _msec;
	float _sec;

public:

	void Reset() {_msec=0;_sec=0;}
	void Update(float msec);
	float GetMsec() {return _msec;}
	float GetSec() {return _sec;}

};

#endif