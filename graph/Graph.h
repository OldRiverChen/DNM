#ifndef _GRAPH_H_

#define _GRAPH_H_


#include <string>
#include <iostream>
#include "nodes\INodeListDatastructure.h"
#include "edges\IEdgeListDatastructure.h"
#include "IElement.h"
#include "..\util\BigInteger.h"
#include "..\util\Log.h"
using namespace std;
/*
Receive a new graph generated through this generator
*/
class GraphDataStructure;
class Graph
{
public:
	INodeListDatastructure* nodes;
	IEdgeListDatastructure* edges;
protected:
	GraphDataStructure* gds;
private:
	string name;
	long long timestamp;
public:
	Graph(string name, long long timestamp, GraphDataStructure* gds, int nodeSize, int edgeSize);
public:
	bool addNode(Node* n);
	/**
	* Retrieve the number of edges within this graph
	*
	* @return
	*/
	int getEdgeCount();
	/**
	* Retrieve a random node
	*
	* @return
	*/
	Node* getRandomNode();
	/**
	* Retrieve the highest node index within this graph
	*
	* @return
	*/
	int getMaxNodeIndex();

	GraphDataStructure*	getGraphDatastructures();
	bool equals(Graph* obj);

	bool addEdge(Edge* e);
	void setTimestamp(long long timestamp);
	long long getTimestamp();
	string getName();
	INodeListDatastructure* getNodes();
	Edge* getEdge(Node* n1,Node* n2);
	Node* getNode(int index);
	int getNodeCount();
	bool containsEdge(Edge* e);
	bool containsEdge(Node* n1, Node* n2);
	Edge* getRandomEdge();
	bool removeEdge(Edge* e);
	/**
	* Check whether this is a directed graph or not
	*
	* @return true, if the graph is directed; fals otherwise
	*/
	bool isDirected();
	/**
	*
	* i.e., V*(V-1) in case of a directed graph, V*(V-1)/2 in case of an
	* undirected graph
	*
	* @return maximum number of edges the graph could have with the current
	*         number of nodes
	*/
	BigInteger getMaxEdgeCount();

public:
	void show();
	
};

#endif
