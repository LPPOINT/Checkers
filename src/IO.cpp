#include "IO.h"


HGE* IO::_hge = NULL;

#pragma comment(lib, "hge.lib")
#pragma comment(lib, "hgehelp.lib")

IO::IO()
{
	_hge = hgeCreate(HGE_VERSION);
}

IO::~IO()
{
	_hge->Release();
}