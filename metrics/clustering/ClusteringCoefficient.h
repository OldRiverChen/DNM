#ifndef _A_CLUSTERINGCOEFFICIENT_H_

#define _A_CLUSTERINGCOEFFICIENT_H_

//一个抽象类
#include <string>
#include <iostream>
#include "..\Metric.h"
#include "..\..\series\data\nodevaluelists\NodeValueList.h"
#include "..\..\series\data\lists\LongList.h"
#include "..\..\series\data\Value.h"
using namespace std;

class ClusteringCoefficient : public Metric
{
public:
	double globalCC;
	double averageCC;
	NodeValueList* localCC;
	long triangleCount;
	long potentialCount;
	LongList* nodeTriangleCount;
	LongList* nodePotentialCount;

public:
	ClusteringCoefficient(string name) :Metric(name, "exact")
	{}
public:
	
public://实现（重写）父类的方法
	vector<Value*>* getValues()
	{
		vector<Value*>* vv = new vector<Value*>();
		Value* globalCC = new Value("globalCC", this->globalCC);
		Value* averageCC = new Value("averageCC", this->averageCC);
		Value* triangleCount = new Value("triangleCount", this->triangleCount);
		Value* potentialCount = new Value("potentialCount", this->potentialCount);
		vv->push_back(globalCC);
		vv->push_back(averageCC);
		vv->push_back(triangleCount);
		vv->push_back(potentialCount);
		return vv;
	}
	vector<Distr<int, vector<long>>*>* getDistributions()
	{
		vector<Distr<int, vector<long>>*>* vd = new vector<Distr<int, vector<long>>*>();
		return vd;
	}
	vector<NodeValueList*>* getNodeValueLists()
	{
		NodeValueList* nodeTriangleCount = new NodeValueList("nodeTriangleCount", this->nodeTriangleCount->getValues());
		NodeValueList* nodePotentialCount = new NodeValueList("nodePotentialCount", this->nodePotentialCount->getValues());
		/*vector<NodeValueList*>* vnvl = new vector<NodeValueList*>();
		vnvl->push_back(this->localCC);
		vnvl->push_back(nodeTriangleCount);
		vnvl->push_back(nodePotentialCount);*/
		return new vector<NodeValueList*>{this->localCC, nodeTriangleCount, nodePotentialCount};
	}
	vector<NodeNodeValueList*>* getNodeNodeValueLists()
	{
		return new vector<NodeNodeValueList*>();
	}
	virtual bool isComparableTo(IMetric* m)
	{
		return m != NULL &&instanceof<ClusteringCoefficient>(m);
	}
};

#endif