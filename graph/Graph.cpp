#include "Graph.h"
#include "datastructures\GraphDataStructure.h"
#include "..\graph\datastructures\DHashArrayList.h"
#include "datastructures\DArray.h"
#include "datastructures\DArrayList.h"
#include "nodes\UndirectedNode.h"

Graph::Graph(string name, long long timestamp, GraphDataStructure* gds, int nodeSize, int edgeSize)
{
	this->name = name;
	this->timestamp = timestamp;
	this->gds = gds;
	this->nodes = (INodeListDatastructure*)gds->newList(Globalnodelist);
	this->edges = (IEdgeListDatastructure*)gds->newList(Globaledgelist);
	this->gds = gds;
}
bool Graph::addNode(Node* n)
{
	return this->nodes->add(n);
}


int Graph::getEdgeCount()
{
	int c = edges->size();
	return c;
}

Node* Graph::getRandomNode()
{
	Node* rs = (Node*)nodes->getRandom();
	return rs;
}
int Graph::getMaxNodeIndex()
{
	return nodes->getMaxNodeIndex();
}

GraphDataStructure* Graph::getGraphDatastructures()
{
	return this->gds;
}

bool Graph::equals(Graph* obj)
{
	Log::debug("Running equality check for graphs");
	if (this == obj)
		return true;
	if (obj == NULL) {
		return false;
	}
	Graph* other = obj;
	if (gds == NULL) {
		if (other->gds != NULL)
			return false;
	}
	return false;
}

bool Graph::addEdge(Edge* e)
{
	return edges->add(e);
}
string Graph::getName()
{
	return this->name;
}

void Graph::setTimestamp(long long timestamp)
{
	this->timestamp = timestamp;
}
long long Graph::getTimestamp()
{
	return this->timestamp;
}

INodeListDatastructure* Graph::getNodes()
{
	return this->nodes;
}
Edge* Graph::getEdge(Node* n1, Node* n2)
{
	Edge* rs = (Edge*)edges->get(gds->getDummyEdge(n1,n2));
	return rs;
}
Node* Graph::getNode(int index)
{
	Node* rs = (Node*)nodes->get(index);
	return rs;
}
int Graph::getNodeCount()
{
	return this->nodes->size();
}
bool Graph::containsEdge(Edge* e)
{
	return this->edges->contains(e);
}
bool Graph::containsEdge(Node* n1, Node* n2)
{
	return this->edges->contains(gds->getDummyEdge(n1,n2));
}
Edge* Graph::getRandomEdge()
{
	Edge* rs = (Edge*)edges->getRandom();
	return rs;
}
bool Graph::removeEdge(Edge* e)
{
	return edges->remove(e);
}
bool Graph::isDirected()
{
	return false;
}

BigInteger Graph::getMaxEdgeCount()
{
	int nodeCount = this->getNodeCount();
	BigInteger res = nodeCount;
	res *= res - 1;
	if (!this->isDirected())
	{
		res /= 2;
	}
	return res;
}

void Graph::show()
{
	cout << "Graph's name:" << this->getName() << endl;
	cout << "Graph's node's num:" << this->nodes->size() << endl;
	cout << "Graph's edge's num:" << this->edges->size() << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Graph's edge:" << endl;
	DHashArrayList* dhal = (DHashArrayList*)this->edges;
	for (vector<IElement*>::iterator iter = dhal->lists->begin(); iter != dhal->lists->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
	cout << endl;
	for (set<IElement*>::iterator iter = dhal->sets->begin(); iter != dhal->sets->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
	DArray* da = (DArray*)this->nodes;
	for (int i = 0; i < da->length;i++)
	{
		if (da->lists[i] != NULL)
			cout << da->lists[i]->asString() << ", ";
		else cout << "NULL" << " ";
	}
	cout << endl;
	cout << "----------------------------------------------" << endl;
	cout << "graph's node's detail:" << endl;
	for (int i = 0; i < da->length; i++)
	{
		UndirectedNode* node = (UndirectedNode*)da->lists[i];
		cout << "node index:" << node->getIndex() << endl;
		DArrayList *dal = (DArrayList *)node->edges;
		for (vector<IElement*>::iterator iter = dal->lists->begin(); iter != dal->lists->end(); iter++)
		{
			Edge* e = (Edge*)(*iter);
			cout << e->asString() << ",";
		}
		cout << endl;
	}


}