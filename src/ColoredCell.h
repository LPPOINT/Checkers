#ifndef _ColoredCell_
#define _ColoredCell_




#include "Cell.h"
#include <HGE\hgecolor.h>

class ColoredCell : public Cell
{
  
private:

	hgeColor*  _color;
	hgeSprite* GetSprite();
	hgeSprite* GetSprite(hgeColor* color);

public:

	ColoredCell(hgeColor* color, float x, float y);
	~ColoredCell();

};

#endif