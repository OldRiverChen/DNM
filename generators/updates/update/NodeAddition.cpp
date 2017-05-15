#include "NodeAddition.h"



NodeAddition::NodeAddition(Node * node):NodeUpdate(node)
{
}

NodeAddition::NodeAddition(string str, GraphDataStructure * gds): NodeUpdate(gds->newNodeInstance(str))
{
}

bool NodeAddition::apply_(Graph * g)
{
	return false;
}

string NodeAddition::getType()
{
	return this->UpdateTypeToString(NA);
}

string NodeAddition::asString_()
{
	return this->node->asString();
}

string NodeAddition::toString_()
{
	return this->node->asString();
}
