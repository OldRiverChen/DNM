#include "UndirectedClusteringCoefficientU.h"
#include "..\..\graph\nodes\UndirectedNode.h"
#include "..\..\graph\datastructures\DArrayList.h"

UndirectedClusteringCoefficientU::UndirectedClusteringCoefficientU():UndirectedClusteringCoefficient("UndirectedClusteringCoefficientU")
{}

void UndirectedClusteringCoefficientU::setGraph(Graph * g)
{
	Metric::setGraph(g);
}

bool UndirectedClusteringCoefficientU::instanceOf(string className)
{
	return (className.compare("IDynamicAlgorithm") == 0);
}

bool UndirectedClusteringCoefficientU::isAssignableFrom(string className)
{
	bool f;
	f = (className.compare("IDynamicAlgorithm") == 0) || ((className.compare("IBeforeNA") == 0)) || ((className.compare("IBeforeNR") == 0))
		|| ((className.compare("IBeforeEA") == 0)) || ((className.compare("IAfterER") == 0));
	return f;
}

string UndirectedClusteringCoefficientU::getTrueInstanceName()
{
	return "UndirectedClusteringCoefficientU";
}

bool UndirectedClusteringCoefficientU::init()
{
	return this->compute();
}

bool UndirectedClusteringCoefficientU::applyBeforeUpdate(NodeAddition * na)
{
	return false;
}

bool UndirectedClusteringCoefficientU::applyBeforeUpdate(NodeRemoval * nr)
{
	return false;
}

bool UndirectedClusteringCoefficientU::applyBeforeUpdate(EdgeAddition * ea)
{
	if (!this->g->isDirected())
	{
		return this->applyBeforeUpdateUndirected(ea);
	}
}

bool UndirectedClusteringCoefficientU::applyAfterUpdate(EdgeRemoval * er)//每删除一条边，就更新一次聚类系数
{
	if (!this->g->isDirected())
	{
		return this->applyAfterUpdateUndirected(er);
	}
}

bool UndirectedClusteringCoefficientU::isComparableTo(IMetric * m)
{
	return ClusteringCoefficient::isComparableTo(m);
}

bool UndirectedClusteringCoefficientU::applyAfterUpdateUndirected(EdgeRemoval * er)
{
	UndirectedEdge* e = (UndirectedEdge*)er->getEdge();
	UndirectedNode* a = e->getNode1();
	UndirectedNode* b = e->getNode2();

	IEdgeListDatastructure* aEdges = a->getEdges();//获取对应顶点a的邻接边集
	DArrayList* dal_aEdges = (DArrayList*)aEdges;//向下转
	for (int j = 0; j < dal_aEdges->size(); j++) {
		UndirectedEdge* a_ = (UndirectedEdge*)dal_aEdges->getEdge(j);
		UndirectedNode* c = (UndirectedNode*)a_->getDifferingNode(a);
		if (c->hasEdge(c, b))
		{
			// remove triangles
			this->removeTriangle(a);
			this->removeTriangle(b);
			this->removeTriangle(c);
		}
	}
	// remove potentials
	this->removePotentials(a, a->getDegree());
	this->removePotentials(b, b->getDegree());

	return true;
}

bool UndirectedClusteringCoefficientU::applyBeforeUpdateUndirected(EdgeAddition * ea)
{
	UndirectedEdge* e = (UndirectedEdge*)ea->getEdge();
	UndirectedNode* a = e->getNode1();
	UndirectedNode* b = e->getNode2();
	// new triangles
	IEdgeListDatastructure* aEdges = a->getEdges();//获取对应顶点a的邻接边集
	DArrayList* dal_aEdges = (DArrayList*)aEdges;//向下转
	for (int j = 0; j < dal_aEdges->size(); j++) {
		UndirectedEdge* c_ = (UndirectedEdge*)dal_aEdges->getEdge(j);
		UndirectedNode* c = (UndirectedNode*)c_->getDifferingNode(a);
		if (c->hasEdge(c, b)) {
			this->addTriangle(a);
			this->addTriangle(b);
			this->addTriangle(c);
		}
	}
	// new potentials
	this->addPotentials(a, a->getDegree());
	this->addPotentials(b, b->getDegree());
	
	return true;
}
