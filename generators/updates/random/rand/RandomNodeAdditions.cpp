#include "RandomNodeAdditions.h"
#include "..\..\..\..\util\parameters\IntParameter.h"

RandomNodeAdditions::RandomNodeAdditions(int count):BatchGenerator("RandomNodeAdditions", NULL)
{
	Parameter* defaultArray[] = { new IntParameter("C",count) };
	//Í¨¹ýset×¢Èë
	this->setParameters(ParameterList::ArrayToVector(defaultArray, 1));
	this->count = count;
}

Batch * RandomNodeAdditions::generate(Graph * g)
{
	Batch* b = new Batch(g->getGraphDatastructures(), g->getTimestamp(),
		g->getTimestamp() + 1, this->count,0, 0, 0);

	set<Node*>* added = new set<Node*>();
	int index = g->getMaxNodeIndex()+1;
	while (added->size() < this->count)
	{
		Node* n = g->getGraphDatastructures()->newNodeInstance(index++);
		added->insert(n);
		b->add(new NodeAddition(n));
	}

	return b;
}

void RandomNodeAdditions::reset()
{
}

bool RandomNodeAdditions::isFurtherBatchPossible(Graph * g)
{
	return true;
}

void RandomNodeAdditions::show()
{
	cout << "NodeAdditions's name:" << this->getNamePlain() << endl;
	if (this->getParameters() != NULL)
	{
		cout << "NodeAdditions's parameters: " << endl;
		vector<Parameter*>* params = this->getParameters();
		for (vector<Parameter*>::iterator iter = params->begin(); iter != params->end(); iter++)
		{
			Parameter* p = (*iter);
			cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
		}
	}
}
