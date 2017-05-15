#ifndef _GRAPHDATASTRUCTURE_H_

#define _GRAPHDATASTRUCTURE_H_


#include <string>
#include <map>
#include"GDS.h"
#include"DataStructure.h"
#include "IDataStructure.h"
#include "..\edges\IEdgeDummy.h"
#include "..\edges\DummyUndirectedEdge.h"
enum ListType
{
	Globalnodelist, Globaledgelist, Localedgelist, Localnodelist
};
class Node;
class Edge;
using namespace std;
class Graph;
class GraphDataStructure
{
private:
	Node* nodeType;
	Edge* edgeType;
	int defaultSize = 10;//默认是10
	map<string, int> defaultListSizes;
	static GraphDataStructure* currentGDS;
	IEdgeDummy* edgeDummy;
private:
	const string GlobalNodeList = "GlobalNodeList";
	const string GlobalEdgeList = "GlobalEdgeList";
	const string LocalEdgeList = "LocalEdgeList";
	const string LocalNodeList = "LocalNodeList";
public:
	GraphDataStructure(Node* nodeType, Edge* edgeType);
public:
	map<string, int> getDefaultListSizes();
	GraphDataStructure* clone();
	Graph* newGraphInstance(string name, long long timestamp, int nodes, int edges);
	IDataStructure* newList(ListType lt);//lt对于是上面四种string,根据lt来判断创建什么对象
	Node* newNodeInstance(int index);
	Node* newNodeInstance(string str);
	Edge* newEdgeInstance(Node* src, Node* dst);
	Edge* newEdgeInstance(string str, Graph* graph, map<int, Node*>* addedNodes);
	Edge* getDummyEdge(Node* n1, Node* n2);
	Edge* getDummyEdge(int n1, int n2);
public:
	static GraphDataStructure* getCurrent();
	static void setCurrent(GraphDataStructure * gds);

	static string ListTypeToString(ListType lt)
	{
		string rs;
		switch (lt)
		{
		case Globalnodelist:
			rs = "GlobalNodeList";
			break;
		case Globaledgelist:
			rs = "GlobalEdgeList";
			break;
		case Localedgelist:
			rs = "LocalEdgeList";
			break;
		case Localnodelist:
			rs = "LocalNodeList";
			break;
		}
		return rs;
	}
	
};

#endif
