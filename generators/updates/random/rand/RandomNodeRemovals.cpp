#include "RandomNodeRemovals.h"
#include "..\..\..\..\util\parameters\IntParameter.h"

RandomNodeRemovals::RandomNodeRemovals(int count):BatchGenerator("RandomNodeRemovals", NULL)
{
	Parameter* defaultArray[] = { new IntParameter("C",count) };
	//Í¨¹ýset×¢Èë
	this->setParameters(ParameterList::ArrayToVector(defaultArray, 1));
	this->count = count;
}

Batch * RandomNodeRemovals::generate(Graph * g)
{
	Batch* b = new Batch(g->getGraphDatastructures(), g->getTimestamp(),
		g->getTimestamp() + 1, 0, this->count, 0, 0);
	set < Node*, Node_less > * removed = new set<Node*, Node_less>();
	while (removed->size() < this->count && removed->size() < g->getNodeCount())
	{
		Node* n = g->getRandomNode();
		if (removed->find(n) != removed->end())
			continue;
		removed->insert(n);
		b->add(new NodeRemoval(n));
	}
	return b;
}

void RandomNodeRemovals::reset()
{
}

bool RandomNodeRemovals::isFurtherBatchPossible(Graph * g)
{
	return g->getNodeCount()>0;
}

void RandomNodeRemovals::show()
{
	cout << "NodeRemovals's name:" << this->getNamePlain() << endl;
	if (this->getParameters() != NULL)
	{
		cout << "NodeRemovals's parameters: " << endl;
		vector<Parameter*>* params = this->getParameters();
		for (vector<Parameter*>::iterator iter = params->begin(); iter != params->end(); iter++)
		{
			Parameter* p = (*iter);
			cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
		}
	}
}
