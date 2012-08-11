#include "StepBlankNode.h"

StepBlankNode::StepBlankNode(std::string str, Checker::CheckerColor color)
{
  _str = str;
  switch (color)
  {
  case Checker::_WHITE:
	  _spr = new hgeSprite(_hge->Texture_Load("BLANK_NODE_WHITE.png"), 0, 0, BLANK_NODE_SIZE_X, BLANK_NODE_SIZE_Y);
	  break;
  case Checker::_BLACK:
	  _spr = new hgeSprite(_hge->Texture_Load("BLANK_NODE_BLACK.png"), 0, 0, BLANK_NODE_SIZE_X, BLANK_NODE_SIZE_Y);
	  break;
  }
  _fnt = new hgeFont("font1.fnt");
  _fnt->SetColor((_fntColor = new hgeColor(255, 0, 0, 255))->GetHWColor());
}

StepBlankNode::StepBlankNode(std::string str, hgeColor* clr, Checker::CheckerColor color)
{
  _str = str;
  switch (color)
  {
  case Checker::_WHITE:
	  _spr = new hgeSprite(_hge->Texture_Load("BLANK_NODE_WHITE.png"), 0, 0, BLANK_NODE_SIZE_X, BLANK_NODE_SIZE_Y);
	  break;
  case Checker::_BLACK:
	  _spr = new hgeSprite(_hge->Texture_Load("BLANK_NODE_BLACK.png"), 0, 0, BLANK_NODE_SIZE_X, BLANK_NODE_SIZE_Y);
	  break;
  }
  _fnt = new hgeFont("font1.fnt");
  _fntColor = clr;
  _fnt->SetColor(_fntColor->GetHWColor());
}


void StepBlankNode::Render(float y, int number)
{
	_spr->Render(BLANK_NODE_POS_X, y);
	_fnt->printf(BLANK_NODE_POS_X+10, y+5, 3, "%d. %s", number, _str.c_str());
}