#include "UndirectedNode.h"

void UndirectedNode::init(GraphDataStructure * gds)
{
	this->edges = (IEdgeListDatastructure*)gds->newList(Localedgelist);
}

IEdgeListDatastructure * UndirectedNode::getEdges()
{
	return this->edges;
}

bool UndirectedNode::addEdge(Edge * e)
{
	bool f1 = this->edges->contains(e);
	bool f2 = this->edges->add(e);
	return (!f1)&&(f2);
}

int UndirectedNode::getDegree()
{
	return this->edges->size();
}

bool UndirectedNode::hasEdge_(Edge * e)
{
	return this->edges->contains(e);
}

bool UndirectedNode::removeEdge(Edge * e)
{
	return edges->remove(e);
}
