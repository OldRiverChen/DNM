
#include "DegreeDistribution.h"
#include "..\..\graph\nodes\INodeListDatastructure.h"
#include "..\..\graph\nodes\UndirectedNode.h"
#include "..\..\series\data\Value.h"


DegreeDistribution::DegreeDistribution(string name):Metric(name,"exact")
{

}

bool DegreeDistribution::compute()
{
	//����ͼ
	this->degree = new BinnedIntDistr("DegreeDistribution");//ͳ��graph���������ķֲ������Ƕ���Ϊ0���м���������Ϊ1���м���������
	this->inDegree = NULL;
	this->outDegree = NULL;
	INodeListDatastructure* inode = this->getNodesOfAssignedTypes();
	for (int i = 0; i < inode->size(); i++)
	{
		UndirectedNode* un = (UndirectedNode*)inode->get(i);
		int d = un->getDegree();
		this->degree->incr(d);
	}
	return true;
}

void DegreeDistribution::setGraph(Graph * graph)
{
	Metric::setGraph(graph);
}

vector<Value*>* DegreeDistribution::getValues()
{
	//����ͼ
	vector<Value*>* vv = new vector<Value*>();
	Value* min = new Value("DegreeMin", this->degree->getMinNonZeroIndex());
	Value* max = new Value("DegreeMax", this->degree->getMaxNonZeroIndex());
	vv->push_back(min);
	vv->push_back(max);
	return vv;
}

vector<Distr<int, vector<long>>*>* DegreeDistribution::getDistributions()
{
	vector<Distr<int, vector<long>>*>* vd = new vector<Distr<int, vector<long>>*>();
	vd->push_back(this->degree);
	return vd;
}

vector<NodeValueList*>* DegreeDistribution::getNodeValueLists()
{
	return new vector<NodeValueList*>();//�൱��java   return new NodeValueList[0];һ������Ϊ0�Ŀ����飬���ǿ���ʹ��.length��NULL����ʹ��
}

vector<NodeNodeValueList*>* DegreeDistribution::getNodeNodeValueLists()
{
	return new vector<NodeNodeValueList*>();
}

bool DegreeDistribution::isComparableTo(IMetric * m)
{
	return instanceof<DegreeDistribution>(m);
}
