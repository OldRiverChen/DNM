#include "DummyUndirectedEdge.h"
#include "..\nodes\UndirectedNode.h"

DummyUndirectedEdge::DummyUndirectedEdge(UndirectedNode * src, UndirectedNode * dst):UndirectedEdge(src,dst)
{
}

void DummyUndirectedEdge::setNodes(int n1, int n2)
{
	this->n1->setIndex(min(n1,n2));
	this->n2->setIndex(max(n1,n2));
}
