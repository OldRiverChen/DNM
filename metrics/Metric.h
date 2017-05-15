#ifndef _A_METRIC_H_

#define _A_METRIC_H_

//一个抽象类
#include <string>
#include <iostream>
#include "IMetric.h"
#include "..\util\ParameterList.h"
#include "..\graph\Graph.h"
#include "..\series\data\MetricData.h"
#include "..\series\data\Value.h"
#include "..\series\data\distr\Distr.h"
#include "..\series\data\nodevaluelists\NodeNodeValueList.h"
#include "..\util\Util.h"
#include "..\generators\updates\update\EdgeAddition.h"
#include "..\generators\updates\update\EdgeRemoval.h"
#include "..\generators\updates\update\NodeAddition.h"
#include "..\generators\updates\update\NodeRemoval.h"
using namespace std;

class Metric : public ParameterList, public IMetric
{
protected:
	string metricType;
	string nodeTypes;
	Graph* g;
public:
	Metric(string name, string metricType) :ParameterList(name)
	{
		this->metricType = metricType;
		this->nodeTypes = "";
	}
public:
	bool reset()
	{
		return true;
	}
	void setGraph(Graph* graph)
	{
		this->g = graph;
	}
	Graph* getGraph()
	{
		return this->g;
	}
	INodeListDatastructure* getNodesOfAssignedTypes()
	{
		return this->g->getNodes();
	}

	MetricData* getData()
	{
		// remove metric type from all components
		string name = this->getName();
		string type = "exact";
		vector<Value*>* values = this->getValues();//获取最大度与最小度
		vector<Distr<int, vector<long>>*>* distributions = this->getDistributions();
		vector<NodeValueList*>* nodevalues = this->getNodeValueLists();//NodeValueList一个一维矩阵
		vector<NodeNodeValueList*>* nodenodevalues = this->getNodeNodeValueLists();//NodeNodeValueList一个二维矩阵
		return new MetricData(name, type,values, distributions, nodevalues, nodenodevalues);
	}


public:
	void show()
	{
		cout << "Metric's name:" << this->getNamePlain() << endl;
		cout << "Metric's name:" << this->metricType << endl;
	}
public:
	virtual bool init()
	{
		return false;
	}
	virtual bool applyBeforeUpdate(EdgeAddition* ea)
	{
		return false;
	}
	virtual bool applyAfterUpdate(EdgeRemoval* er)
	{
		return false;
	}
	virtual bool recompute()
	{
		return false;
	}

	/**
	*
	* @return all the values computed by this metric
	*/
	virtual vector<Value*>* getValues()
	{
		return NULL;
	}
	/**
	*
	* @return all the distributions computed by this metric
	*/
	virtual vector<Distr<int,vector<long>>* >* getDistributions()
	{
		return NULL;
	}
	/**
	*
	* @return all the nodevaluelists computed by this metric
	*/
	virtual vector<NodeValueList*>* getNodeValueLists()
	{
		return NULL;
	}
	/**
	*
	* @return all the nodenodevaluelists computed by this metric
	*/
	virtual vector<NodeNodeValueList*>* getNodeNodeValueLists()
	{
		return NULL;
	}

};

#endif