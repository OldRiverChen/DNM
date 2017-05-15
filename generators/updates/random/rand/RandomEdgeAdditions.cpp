#include "RandomEdgeAdditions.h"
#include "..\..\..\..\util\parameters\IntParameter.h"

RandomEdgeAdditions::RandomEdgeAdditions(int count):BatchGenerator("RandomEdgeAdditions", NULL)
{
	Parameter* defaultArray[] = { new IntParameter("C",count) };
	//通过set注入
	this->setParameters(ParameterList::ArrayToVector(defaultArray, 1));
	this->count = count;
}

Batch * RandomEdgeAdditions::generate(Graph* g)
{
	Batch* b = new Batch(g->getGraphDatastructures(), g->getTimestamp(), g->getTimestamp() + 1, 0, 0, this->count, 0);
	set<Edge*, Edge_compare>* added = new set<Edge*, Edge_compare>();
	int maxEdgesToAdd = this->count;

	int oldEdgeCount = g->getEdgeCount();
	BigInteger maxEdgeCount = g->getMaxEdgeCount();
	BigInteger absoluteMaximumToInsert = maxEdgeCount - oldEdgeCount;
	/**
	* absoluteMaximumToInsert holds the upper bound of edges to be inserted
	* into the current graph
	*/
	if (absoluteMaximumToInsert < maxEdgesToAdd)
	{
		/**
		* The absolute maximum is smaller than the number of edges that
		* should be inserted by this batch generator. But as we cannot
		* insert more edges than the maximum dictated by the graph itself,
		* adjust the bound
		*/
		maxEdgesToAdd = absoluteMaximumToInsert.IntValue();
	}
	while (added->size() < maxEdgesToAdd)
	{
		Node* n1 = g->getRandomNode();
		Node* n2 = g->getRandomNode();
		if (n1->equals(n2)) {
			continue;
		}
		Edge* e = g->getGraphDatastructures()->newEdgeInstance(n1, n2);
		if (g->containsEdge(e) || added->find(e) != added->end())
		{
			continue;
		}
		added->insert(e);
		b->add(new EdgeAddition(e));
	}
	return b;
}

bool RandomEdgeAdditions::isFurtherBatchPossible(Graph * g)
{
	int oldEdgeCount = g->getEdgeCount();//获取上一个时间点的图边数
	BigInteger maxEdgeCount = g->getMaxNodeIndex();
	BigInteger absoluteMaximumToInsert = maxEdgeCount - BigInteger(oldEdgeCount);
	return (absoluteMaximumToInsert > BigInteger::ZERO);
}

void RandomEdgeAdditions::show()
{
	cout << "EdgeAdditions's name:" << this->getNamePlain() << endl;
	if (this->getParameters() != NULL)
	{
		cout << "EdgeAdditions's parameters: " << endl;
		vector<Parameter*>* params = this->getParameters();
		for (vector<Parameter*>::iterator iter = params->begin(); iter != params->end(); iter++)
		{
			Parameter* p = (*iter);
			cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
		}
	}
}
