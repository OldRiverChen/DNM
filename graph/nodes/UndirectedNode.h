#ifndef _A_UNDIRECTEDNODE_H_

#define _A_UNDIRECTEDNODE_H_

//一个抽象类
#include <string>
#include <vector>
#include <iostream>
#include "..\edges\IEdgeListDatastructure.h"
#include "..\datastructures\GraphDataStructure.h"
#include "Node.h"
#include "..\..\util\Util.h"


using namespace std;

class UndirectedNode : public Node
{
public:
	IEdgeListDatastructure* edges;

public:
	UndirectedNode(int index, GraphDataStructure* gds):Node(index, gds)
	{
	}
	UndirectedNode(string str, GraphDataStructure* gds) :Node(str, gds)
	{
	}

public:
	void init(GraphDataStructure* gds);
	IEdgeListDatastructure* getEdges();


public://实现父类的方法
	bool addEdge(Edge* e);
	int getDegree();
	bool hasEdge_(Edge* e);
	bool removeEdge(Edge* e);

};

#endif
