#include <string>
#include <iostream>
#include <vector>
#include "..\..\util\Parameter.h"

#include "..\..\util\ParameterList.h"
#include "RandomGraph.h"
using namespace std;
RandomGraph::RandomGraph(GraphDataStructure* gds, int nodes, int edges) :GraphGenerator("UndirectedRandomGraph",gds, 0, nodes, edges)
{
	Parameter* defaultArray[] = { new IntParameter("N", nodes), new IntParameter("E", edges) };//默认参数值
	//通过set注入
	this->setParameters(ParameterList::ArrayToVector(defaultArray,2));
}

void RandomGraph::reset()
{
}

void RandomGraph::show()
{
	cout << "RandomGraph's name:" << this->getNamePlain() << endl;
	if (this->getParameters() != NULL)
	{
		cout <<"RandomGraph's parameters: " << endl;
		vector<Parameter*>* params = this->getParameters();
		for (vector<Parameter*>::iterator iter = params->begin(); iter != params->end(); iter++)
		{
			Parameter* p = (*iter);
			cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
		}
	}
	cout << "RandomGraph's init node num :" << this->nodesInit << endl;
	cout << "RandomGraph's init edge num :" << this->edgesInit << endl;
	cout << "RandomGraph's timestampInit :" <<this->timestampInit<< endl;
	if (this->gds != NULL) {
		cout << "gds is not NULL" << endl;
		//cout << "gds's defaultListSize:" << this->gds->getDefaultListSize()<< endl;
	}
}

Graph * RandomGraph::generate()
{
	Graph* graph = this->newGraphInstance();

	for (int i = 0; i < this->nodesInit; i++)
	{
		Node* node = this->gds->newNodeInstance(i);
		graph->addNode(node);
	}
	while (graph->getEdgeCount() < this->edgesInit)
	{
		Node* src = graph->getRandomNode();
		Node* dst = graph->getRandomNode();
		if (!src->deepEquals(dst))
		{
			Edge* edge = this->gds->newEdgeInstance(src, dst);
			if (graph->addEdge(edge)) 
			{
				edge->connectToNodes();
			}
		}
	}
	graph->show();
	return graph;
}
