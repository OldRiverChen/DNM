#include "NodeRemoval.h"
#include "..\..\..\util\Util.h"
#include "..\..\..\graph\nodes\UndirectedNode.h"
#include "..\..\..\util\Log.h"



NodeRemoval::NodeRemoval(Node * node):NodeUpdate(node)
{
}

NodeRemoval::NodeRemoval(string str, Graph * g):NodeUpdate(g->getNode(stringToNum<int>(str)))
{
}

bool NodeRemoval::apply_(Graph * g)
{
	return false;
}

string NodeRemoval::getType()
{
	return this->UpdateTypeToString(NR);
}

string NodeRemoval::asString_()
{
	return to_string(this->node->getIndex());
}

string NodeRemoval::toString_()
{
	return to_string(this->node->getIndex());
}
