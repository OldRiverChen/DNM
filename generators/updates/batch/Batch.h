#ifndef _BATCH_H_

#define _BATCH_H_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "..\..\..\graph\datastructures\GraphDataStructure.h"
#include "..\..\..\graph\nodes\Node.h"
#include "..\..\..\graph\edges\Edge.h"
#include "..\update\EdgeAddition.h"
#include "..\update\EdgeRemoval.h"
#include "..\update\NodeAddition.h"
#include "..\update\NodeRemoval.h"
#include "..\update\Update.h"
using namespace std;
class Batch
{
public:
	map < Node*, NodeAddition*, Node_less> * nodeAdditions;
	map<Node*, NodeRemoval*,Node_less>* nodeRemovals;
	map<Edge*, EdgeAddition*,Edge_less>* edgeAdditions;
	map < Edge*, EdgeRemoval*,Edge_less> * edgeRemovals;
	vector<Update*>* all;//装map里面的value值

	GraphDataStructure* gds;

	long long from;
	long long to;
public:
	Batch(GraphDataStructure* gds, long long from, long long to);
	Batch(GraphDataStructure* gds, long long from, long long to, int nodeAdditions,
		int nodeRemovals, int edgeAdditions,int edgeRemovals);
public:
	bool addAll(vector<Update*>* all);
	bool add(Update* u);
	bool add(NodeAddition* na);
	bool add(NodeRemoval* nr);
	bool add(EdgeAddition* ea);
	bool add(EdgeRemoval* er);
	bool remove(Update* u);
	bool remove(NodeAddition* na);
	bool remove(NodeRemoval* nr);
	bool remove(EdgeAddition* ea);
	bool remove(EdgeRemoval* er);
	int getNodeAdditionsCount();
	int getNodeRemovalsCount();
	int getEdgeAdditionsCount();
	int getEdgeRemovalsCount();
	int getSize();
	long long getTo();
	void setTo();

	vector<Update*>* getAllUpdates();
	vector<NodeAddition*>* getNodeAdditions();
	vector<NodeRemoval*>* getNodeRemovals();
	vector<EdgeAddition*>* getEdgeAdditions();
	vector<EdgeRemoval*>* getEdgeRemovals();

	string toString();
};

#endif
