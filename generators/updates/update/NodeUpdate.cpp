#include "NodeUpdate.h"

NodeUpdate::NodeUpdate(Node * node)
{
	this->node = node;
}

Node * NodeUpdate::getNode()
{
	return this->node;
}

bool NodeUpdate_less::operator()(NodeUpdate * n1, NodeUpdate * n2) const
{
	return n1->getNode()->getIndex() < n2->getNode()->getIndex();
}
