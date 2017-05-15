#ifndef _A_DEGREEDISTRIBUTION_H_

#define _A_DEGREEDISTRIBUTION_H_

//一个抽象类
#include <string>
#include <iostream>
#include "..\Metric.h"
#include "..\..\series\data\distr\BinnedIntDistr.h"
#include "..\..\graph\Graph.h"
using namespace std;

class DegreeDistribution : public Metric
{
public:
	BinnedIntDistr* degree;
	BinnedIntDistr* inDegree;
	BinnedIntDistr* outDegree;
public:
	DegreeDistribution(string name);
public:
	bool compute();
	void setGraph(Graph* graph);
	vector<Value*>* getValues();
	vector<Distr<int, vector<long>>* >* getDistributions();
	vector<NodeValueList*>* getNodeValueLists();
	vector<NodeNodeValueList*>* getNodeNodeValueLists();
	/**
	*
	* @param m
	* @return true, if the metric can be compared, i.e., they compute the same
	*         properties of a graph
	*/
	virtual bool isComparableTo(IMetric* m);
};

#endif