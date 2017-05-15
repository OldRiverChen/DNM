#include "EdgeRemoval.h"
#include "..\..\..\util\Util.h"
#include "..\..\..\graph\edges\UndirectedEdge.h"
#include "..\..\..\graph\nodes\UndirectedNode.h"
#include "..\..\..\util\Log.h"


EdgeRemoval::EdgeRemoval(Edge * edge) :EdgeUpdate(edge)
{
}

EdgeRemoval::EdgeRemoval(string str, GraphDataStructure * gds, Graph * g, map<int, Node*>* addedNodes): EdgeUpdate(g->getEdge(NULL,NULL))
{
}

bool EdgeRemoval::apply_(Graph * g)
{
	bool success = g->removeEdge(this->edge);
	success &= this->edge->disconnectFromNodes();
	return success;
}

string EdgeRemoval::getType()
{
	return this->UpdateTypeToString(ER);
}

string EdgeRemoval::asString_()
{
	if (instanceof<UndirectedEdge>(this->edge))//只处理无向图
	{
		UndirectedEdge* e = (UndirectedEdge*) this->edge;
		return to_string(e->getNode1()->getIndex()) + Update::EdgeSeparator
			+ to_string(e->getNode2()->getIndex());
	}
	else {
		Log::error("incompatible edge type: "+this->edge->asString());
		exit(1);
	}
}

string EdgeRemoval::toString_()
{
	return this->edge->asString();
}
