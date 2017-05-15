#ifndef _A_GRAPHGENERATOR_H_

#define _A_GRAPHGENERATOR_H_

//一个抽象类
#include <string>
#include <vector>
#include "..\graph\Graph.h"
#include "..\util\Parameter.h"
#include "..\util\ParameterList.h"
#include "..\util\parameters\IntParameter.h"
#include "..\graph\datastructures\GraphDataStructure.h"
using namespace std;
class GraphGenerator: public ParameterList
{
protected:
	long long timestampInit;
	int	nodesInit;//图顶点初始的数量
	int edgesInit;//图边初始的数量
	GraphDataStructure* gds;
public:
	long long getTimestampInit()
	{
		return this->timestampInit;
	}
	int getNodesInit() 
	{
		return this->nodesInit;
	}
	int getEdgesInit()
	{
		return this->edgesInit;
	}
	GraphDataStructure* getGds()
	{
		return this->gds;
	}
	void setGds(GraphDataStructure* newGDS)
	{
		this->gds = newGDS;
	}

public:
	GraphGenerator(string name,GraphDataStructure* gds,
		long long timestampInit, int nodesInit, int edgesInit):ParameterList(name,NULL)
	{
		this->timestampInit = timestampInit;
		this->nodesInit = nodesInit;
		this->edgesInit = edgesInit;

		this->gds = gds;
	}
public:
	GraphDataStructure* getGraphDataStructure()
	{
		return this->gds;
	}

	Graph* newGraphInstance()
	{
		GraphDataStructure* newGDS = gds->clone();
		//delete gds;
		return  newGDS->newGraphInstance(this->getName(),this->timestampInit,this->nodesInit,this->edgesInit);
	}

public:
	virtual void show() 
	{

	}
	virtual Graph* generate()
	{
		return NULL;
	}
};

#endif
