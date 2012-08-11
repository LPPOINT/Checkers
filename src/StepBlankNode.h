#ifndef _StepBlankNode_
#define _StepBlankNode_





#include "IO.h"
#include <HGE\hgecolor.h>
#include <string>
#include "Checker.h"
#include <HGE\hgefont.h>

#define STEP_BLANK_POS_X CELL_END_X + 25
#define STEP_BLANK_POS_Y CELL_END_Y / 2 / 2
#define STEP_BLANK_SIZE_X 250
#define STEP_BLANK_SIZE_Y 525
#define STEP_BLANK_MAX_VIS_NODES 9
#define BLANK_NODE_POS_X STEP_BLANK_POS_X + 10
#define BLANK_NODE_SIZE_Y STEP_BLANK_SIZE_Y / STEP_BLANK_MAX_VIS_NODES-7
#define BLANK_NODE_SIZE_X STEP_BLANK_SIZE_X-17

class StepBlankNode : public IO
{

public:

	void Render(float y, int number);

private:

	hgeFont*    _fnt;
	hgeColor*   _fntColor;
	hgeSprite*  _spr;
	std::string _str;

public:

	StepBlankNode(std::string str, Checker::CheckerColor color);
	StepBlankNode(std::string str, hgeColor* clr, Checker::CheckerColor color);
};

#endif