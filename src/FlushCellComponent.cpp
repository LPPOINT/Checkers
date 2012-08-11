#include "FlushCellComponent.h"

bool FlushCellComponent::Equals(CellComponent* c)
{
		return (bool)dynamic_cast<FlushCellComponent*>(c);
}