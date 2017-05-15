#ifndef _UNDIRECTEDCLUSTERINGCOEFFICIENTU_H_

#define _UNDIRECTEDCLUSTERINGCOEFFICIENTU_H_

#include <string>
#include <iostream>
#include "UndirectedClusteringCoefficient.h"
#include "..\..\metrics\algorithms\IBeforeNA.h"
#include "..\..\metrics\algorithms\IBeforeNR.h"
#include "..\..\metrics\algorithms\IBeforeEA.h"
#include "..\..\metrics\algorithms\IAfterER.h"
using namespace std;

class UndirectedClusteringCoefficientU : public UndirectedClusteringCoefficient,public IBeforeNA, public IBeforeNR,public IBeforeEA,public IAfterER
{
public:
	UndirectedClusteringCoefficientU();
public://实现父类方法
	void setGraph(Graph* g);
	bool instanceOf(string className);//判断对象是否是className的一个实例，用于多层继承，与className差了至少2层
	bool isAssignableFrom(string className);//判断对象的类是否与className相同或是className的子类,用于多层继承，与className差了至少2层
	string getTrueInstanceName();
	bool init();
	bool applyBeforeUpdate(NodeAddition* na);
	bool applyBeforeUpdate(NodeRemoval* nr);
	bool applyBeforeUpdate(EdgeAddition* ea);
	bool applyAfterUpdate(EdgeRemoval* er);
	bool isComparableTo(IMetric* m);
private:
	bool applyAfterUpdateUndirected(EdgeRemoval* er);
	bool applyBeforeUpdateUndirected(EdgeAddition* ea);
};

#endif