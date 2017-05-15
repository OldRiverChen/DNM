#include "GraphDataStructure.h"
#include "DataStructure.h"
#include "..\nodes\Node.h"
#include "..\edges\Edge.h"
#include "..\Graph.h"
#include "DArray.h"
#include "DHashArrayList.h"
#include "..\nodes\UndirectedNode.h"
#include "..\edges\UndirectedEdge.h"
#include "DArrayList.h"
GraphDataStructure* GraphDataStructure::currentGDS = NULL;
GraphDataStructure::GraphDataStructure(Node * nodeType, Edge * edgeType)
{
	this->edgeType = edgeType;
	this->nodeType = nodeType;
	this->defaultListSizes.insert(pair<string, int>(GlobalNodeList, defaultSize));
	this->defaultListSizes.insert(pair<string, int>(GlobalEdgeList, defaultSize));
	this->defaultListSizes.insert(pair<string, int>(LocalEdgeList, defaultSize));
	this->defaultListSizes.insert(pair<string, int>(LocalNodeList, defaultSize));
	this->edgeDummy = NULL;
}

map<string, int> GraphDataStructure::getDefaultListSizes()
{
	return defaultListSizes;
}

GraphDataStructure * GraphDataStructure::clone()
{

	return GDS::undirected();
}

Graph * GraphDataStructure::newGraphInstance(string name, long long timestamp, int nodes, int edges)
{
	//insert不能修改key相同的value值，用下面方法
	this->defaultListSizes[GlobalNodeList]= nodes;
	this->defaultListSizes[GlobalEdgeList]=edges;
	if (nodes > 0)
	{
		int estimatedMeanSize = (int)((edges / nodes) * 1.1);
		if (estimatedMeanSize < 1) 
		{
			estimatedMeanSize = 1;
		}
		this->defaultListSizes[LocalEdgeList]=estimatedMeanSize;
		this->defaultListSizes[LocalNodeList]=estimatedMeanSize;
	}
	setCurrent(this);
	return new Graph(name,timestamp,this,nodes,edges);
}


IDataStructure* GraphDataStructure::newList(ListType lt)
{
	IDataStructure* rs = NULL;
	//查找defaultListSizes 中对应值
	string key = ListTypeToString(lt);
	int value = -1;
	map<string, int>::iterator it;
	it = defaultListSizes.find(key);
	if (it != defaultListSizes.end())
		value = it->second;

	if (key.compare(GlobalNodeList)==0)//创建DArray对象
	{
		DArray* da = new DArray();
		da->init(value);
		INodeListDatastructure* in = da;
		rs = in;
	}
	else if(key.compare(GlobalEdgeList)==0)//创建DHashArrayList对象
	{
		DHashArrayList* dhal = new DHashArrayList();
		dhal->init(value);
		IEdgeListDatastructure* ie = dhal;
		rs = ie;
	}
	else if (key.compare(LocalEdgeList) == 0)//创建DArrayList对象
	{
		DArrayList * dal = new DArrayList();
		dal->init(value);
		IEdgeListDatastructure* ie = dal;
		rs = ie;
	}
	else
	{
		cout << "没有对应的ListType" << endl;
		exit(1);
	}
	return rs;
}

Node * GraphDataStructure::newNodeInstance(int index)
{
	Node* c = NULL;
	c = new UndirectedNode(index,this);
	c->init(this);
	return c;
}

Node * GraphDataStructure::newNodeInstance(string str)
{
	return NULL;
}

Edge * GraphDataStructure::newEdgeInstance(Node * src, Node * dst)
{
	Edge* edge = nullptr;
	edge = new UndirectedEdge((UndirectedNode*)src, (UndirectedNode*)dst);
	return edge;
}

Edge * GraphDataStructure::newEdgeInstance(string str, Graph * graph, map<int, Node*>* addedNodes)
{
	return NULL;
}

Edge * GraphDataStructure::getDummyEdge(Node * n1, Node * n2)
{
	Edge* e = this->getDummyEdge(n1->getIndex(), n2->getIndex());
	return e;
}

Edge * GraphDataStructure::getDummyEdge(int n1, int n2)
{
	if (edgeDummy == NULL)
	{
		UndirectedNode* node1 = new UndirectedNode(1, this);
		UndirectedNode* node2 = new UndirectedNode(2, this);
		edgeDummy = new DummyUndirectedEdge(node1, node2);
	}
	edgeDummy->setNodes(n1, n2);
	DummyUndirectedEdge* eDumy = (DummyUndirectedEdge*)edgeDummy;
	UndirectedEdge* eUn = (UndirectedEdge*)eDumy;
	Edge* e = eUn;
	return e;
}

//static
GraphDataStructure * GraphDataStructure::getCurrent()
{
	return currentGDS;
}
void GraphDataStructure::setCurrent(GraphDataStructure * gds)
{
	currentGDS = gds;
}