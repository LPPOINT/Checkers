#ifndef _Cell_
#define _Cell_

class CellComponent;


#include "IO.h"
#include <HGE\hgesprite.h>
#include <HGE\hgerect.h>
#include <vector>
#include "CellComponent.h"
#include <map>
#include "Sprite.h"
#include <string>
//#include "Checker.h"


#define CELL_SIZE 125



class Cell : public IO, public Sprite
{
public:




private:


	std::vector<CellComponent*> _components;

public:

	void Render();


	void AddComponent(CellComponent* c);
	void EraseComponent(CellComponent* c);

	std::vector<CellComponent*> GetComponents() { return _components; };

	Cell(float x, float y, hgeSprite* spr);
	~Cell();

};

#endif