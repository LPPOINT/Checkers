
#include "CellComponent.h"

CellComponent::CellComponent()
{
}

bool CellComponent::operator!=(CellComponent* c)
{
	return !Equals(c);
}

void CellComponent::SetCell(Cell* cell)
{
	_myCell = cell;
}