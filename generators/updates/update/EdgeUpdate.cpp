#include "EdgeUpdate.h"
#include "..\..\..\graph\nodes\Node.h"

EdgeUpdate::EdgeUpdate(Edge * edge)
{
	this->edge = edge;
}

Edge * EdgeUpdate::getEdge()
{
	return edge;
}

bool EdgeUpdate_less::operator()(EdgeUpdate * e1, EdgeUpdate * e2) const
{
	if (e1->getEdge()->getN1()->getIndex()!= e2->getEdge()->getN1()->getIndex())
	{
		return e1->getEdge()->getN1()->getIndex() < e2->getEdge()->getN1()->getIndex();
	}
	else return  e1->getEdge()->getN2()->getIndex()<  e2->getEdge()->getN2()->getIndex();
}
