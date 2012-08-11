#include "StepBlank.h"

StepBlank::StepBlank()
{
	_curUpNode = 0;
	if(!_hge) _hge = hgeCreate(HGE_VERSION);
	_spr = new hgeSprite(_hge->Texture_Load("BLANK_BG.png"),0,0, STEP_BLANK_SIZE_X, STEP_BLANK_SIZE_Y);
	_rect = new hgeRect();
	_rect->Set(STEP_BLANK_POS_X, STEP_BLANK_POS_Y, STEP_BLANK_SIZE_X, STEP_BLANK_SIZE_Y);
}

void StepBlank::Render()
{
	_spr->Render(STEP_BLANK_POS_X, STEP_BLANK_POS_Y);
	for(int i = _curUpNode; i < STEP_BLANK_MAX_VIS_NODES; i++)
		if(i<_nodes.size()&&i>=0)
		{
			_nodes[i]->Render(STEP_BLANK_POS_Y+i*BLANK_NODE_SIZE_Y+15, i+1);
		}
		else break;
}

StepBlank* StepBlank::Get()
{
 static StepBlank* self;
 if(!self)
	 self = new StepBlank();
 return self;
}

void StepBlank::AddNode(StepBlankNode* node)
{
	if(_nodes.size()>=STEP_BLANK_MAX_VIS_NODES) Clear();
	_nodes.push_back(node);
}

void StepBlank::Up()
{
	_curUpNode++;
}

void StepBlank::Clear()
{
	_nodes.clear();
}

void StepBlank::Down()
{
	_curUpNode--;
}