#include "EdgeAddition.h"

EdgeAddition::EdgeAddition(Edge * edge) :EdgeUpdate(edge)
{
}

EdgeAddition::EdgeAddition(string str, GraphDataStructure * gds, Graph * g, map<int, Node*>* addedNodes): EdgeUpdate(gds->newEdgeInstance(str, g, addedNodes))
{
}

bool EdgeAddition::apply_(Graph * g)
{
	if (!g->addEdge(this->edge))
	{
		Log::error("could not add edge " + this->edge->asString());
		if (g->containsEdge(this->edge))
		{
			Edge* old = g->getEdge(this->edge->getN1(), this->edge->getN2());
			Log::error("edge already exists! " + old->asString());
		}
		else {
			Log::error("BUT edge not contained in list...");
		}
		return false;
	}
	if (!this->edge->connectToNodes()) {
		return false;
	}
	return true;
}

string EdgeAddition::getType()
{
	return this->UpdateTypeToString(EA);
}

string EdgeAddition::asString_()
{
	return this->edge->asString();
}

string EdgeAddition::toString_()
{
	return this->edge->asString();
}
