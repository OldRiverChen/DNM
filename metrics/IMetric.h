#ifndef _I_METRIC_H_

#define _I_METRIC_H_

//一个接口
#include <string>
#include <iostream>
#include "..\graph\Graph.h"
using namespace std;

enum MetricType {
	Exact, Heuristic, Quality
};
class IMetric
{
public:
	virtual void setGraph(Graph* graph)=0;
	virtual bool instanceOf(string className) = 0;
	virtual bool isAssignableFrom(string className) = 0;
	virtual string getTrueInstanceName()=0;//获取真实的实例名称
	/**
	*
	* @param m
	* @return true, if the metric can be compared, i.e., they compute the same
	*         properties of a graph
	*/
	virtual bool isComparableTo(IMetric* m)=0;
};

#endif