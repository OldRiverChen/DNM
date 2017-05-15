#include "RandomEdgeRemovals.h"
#include "..\..\..\..\util\parameters\IntParameter.h"

RandomEdgeRemovals::RandomEdgeRemovals(int count):BatchGenerator("RandomEdgeRemovals", NULL)
{
	Parameter* defaultArray[] = { new IntParameter("C",count) };
	//Í¨¹ýset×¢Èë
	this->setParameters(ParameterList::ArrayToVector(defaultArray, 1));
	this->count = count;
}

Batch * RandomEdgeRemovals::generate(Graph * g)
{
	Batch* b = new Batch(g->getGraphDatastructures(), g->getTimestamp(), g->getTimestamp() + 1, 0, 0, 0, this->count);
	set<Edge*, Edge_compare>* removed = new set<Edge*, Edge_compare>();

	while (removed->size() < this->count && removed->size() < g->getEdgeCount()) {
		Edge* e = g->getRandomEdge();
		if (removed->find(e) != removed->end()) {
			continue;
		}
		removed->insert(e);
		b->add(new EdgeRemoval(e));
	}

	return b;
}

void RandomEdgeRemovals::reset()
{
}

bool RandomEdgeRemovals::isFurtherBatchPossible(Graph * g)
{
	return g->getEdgeCount()>0;
}

void RandomEdgeRemovals::show()
{
	cout << "EdgeRemovals's name:" << this->getNamePlain() << endl;
	if (this->getParameters() != NULL)
	{
		cout << "EdgeRemovals's parameters: " << endl;
		vector<Parameter*>* params = this->getParameters();
		for (vector<Parameter*>::iterator iter = params->begin(); iter != params->end(); iter++)
		{
			Parameter* p = (*iter);
			cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
		}
	}
}
