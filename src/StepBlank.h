#ifndef _StepBlank_
#define _StepBlank_





#include "StepBlankNode.h"
#include <HGE\hgesprite.h>
#include <HGE\hgerect.h>


class StepBlank : public IO
{

private:

	std::vector<StepBlankNode*> _nodes;
	int _curUpNode;
	hgeSprite* _spr;
	hgeRect* _rect;

public:

	static StepBlank* Get();

	void Render();
	void Update();

	void Down();
	void Up();

	void AddNode(StepBlankNode* node);
	void Clear();

	StepBlank();

};

#endif