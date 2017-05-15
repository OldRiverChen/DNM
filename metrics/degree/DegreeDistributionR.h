#ifndef _DEGREEDISTRIBUTIONR_H_

#define _DEGREEDISTRIBUTIONR_H_

#include <string>
#include <iostream>
#include "DegreeDistribution.h"
#include "..\algorithms\IRecomputation.h"
#include "..\..\graph\Graph.h"
using namespace std;

class DegreeDistributionR : public DegreeDistribution, public IRecomputation
{
public:
	DegreeDistributionR():DegreeDistribution("DegreeDistributionR")
	{}
public:
	bool recompute() {
		return this->compute();
	}
	bool instanceOf(string className)//�ж϶����Ƿ���className��һ��ʵ��
	{
		return className.compare("IRecomputation") == 0;
	}
	bool isAssignableFrom(string className)//�ж϶�������Ƿ���className��ͬ����className������
	{
		bool f = (className.compare("IRecomputation")==0);
		return f;
	}
	string getTrueInstanceName()
	{
		return "DegreeDistributionR";
	}
	void setGraph(Graph* graph)
	{
		DegreeDistribution::setGraph(graph);
	}
	bool isComparableTo(IMetric* m)
	{
		return DegreeDistribution::isComparableTo(m);
	}
};

#endif