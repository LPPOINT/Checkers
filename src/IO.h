#ifndef _IO_
#define _IO_





#include <HGE\hge.h>
#include <vector>

typedef POINT Point;
typedef POINT Size;
typedef POINT Scale;



class IO
{

protected:

	static HGE* _hge;

public:

	IO();
	~IO();

};


#endif