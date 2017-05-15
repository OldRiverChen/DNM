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
public://ʵ�ָ��෽��
	void setGraph(Graph* g);
	bool instanceOf(string className);//�ж϶����Ƿ���className��һ��ʵ�������ڶ��̳У���className��������2��
	bool isAssignableFrom(string className);//�ж϶�������Ƿ���className��ͬ����className������,���ڶ��̳У���className��������2��
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