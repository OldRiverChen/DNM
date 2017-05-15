
#include "UndirectedClusteringCoefficient.h"
#include "..\..\graph\nodes\UndirectedNode.h"
#include "..\..\graph\edges\UndirectedEdge.h"
#include "..\..\graph\datastructures\DArrayList.h"

UndirectedClusteringCoefficient::UndirectedClusteringCoefficient(string name):ClusteringCoefficient(name)
{
}

bool UndirectedClusteringCoefficient::compute()
{
	this->globalCC = 0;
	this->averageCC = 0;
	this->localCC = new NodeValueList("localCC",this->g->getMaxNodeIndex() + 1);
	this->triangleCount = 0;
	this->potentialCount = 0;
	this->nodePotentialCount = new LongList(g->getMaxNodeIndex() + 1);
	this->nodeTriangleCount = new LongList(g->getMaxNodeIndex() + 1);
	return this->computeUndirected();
}

bool UndirectedClusteringCoefficient::computeUndirected()//计算可能的V形，三角形（3顶点连通结构，2种情形）的个数
{
	INodeListDatastructure* allNode = this->getNodesOfAssignedTypes();
	for (int i = 0; i < allNode->size(); i++)//
	{
		UndirectedNode* a = (UndirectedNode*)allNode->get(i);//获取一个顶点a
		IEdgeListDatastructure* aEdges = a->getEdges();//获取对应顶点a的邻接边集
		DArrayList* dal_aEdges = (DArrayList*)aEdges;//向下转
		for (int j = 0; j < dal_aEdges->size(); j++)//任取a的两条边,
		{
			UndirectedEdge* e1 = (UndirectedEdge*)dal_aEdges->getEdge(j);//获取顶点a的一条边e1
			UndirectedNode* b = (UndirectedNode*)e1->getDifferingNode(a);//获取顶点a沿e1的另一个端点b
			for (int k = 0; k < dal_aEdges->size(); k++)
			{
				UndirectedEdge* e2 = (UndirectedEdge*)dal_aEdges->getEdge(k); // 获取顶点a的另外一条边e2
				UndirectedNode* c = (UndirectedNode*)e2->getDifferingNode(a);////获取顶点a沿e2的另一个端点c
				if (b->equals(c)) {//说明e1和e2是同一条边,
					continue;
				}
				this->nodePotentialCount->incr(a->getIndex());//说明a顶点的可能的V形的个数+1，个数会有重复 0,1,2,   0,2,1为两个不同的形状
				if (b->hasEdge(b, c))//看b顶点是否存在一条边指向c，
				{
					this->nodeTriangleCount->incr(a->getIndex());//说明a顶点的可能的三角形的个数+1，个数会有重复，不同的排列视为不同，0,1,2,   0,2,1为两个不同的形状
				}
			}
		}
		this->nodeTriangleCount->div(a->getIndex(), 2);//去重复
		this->nodePotentialCount->div(a->getIndex(),2);//去重复

		this->update(a->getIndex());//更新各个顶点的聚类系数

	}
	this->update();//更新全局的聚类系数
	this->averageCC = ArrayUtils::avgIgnoreNaN(this->localCC->getValues());
	return true;
}

void UndirectedClusteringCoefficient::update(int index)
{
	this->triangleCount+= this->nodeTriangleCount->getValue(index);
	this->potentialCount += this->nodePotentialCount->getValue(index);
	if (this->nodePotentialCount->getValue(index) == 0) {
		this->localCC->setValue(index, 0);
	}
	else {
		this->localCC->setValue(index, (double) this->nodeTriangleCount->getValue(index) / 
			(double) this->nodePotentialCount->getValue(index));
	}
}

void UndirectedClusteringCoefficient::update()
{
	if (this->potentialCount == 0) {
		this->globalCC = 0;
	}
	else {
		this->globalCC = (double) this->triangleCount
			/ (double) this->potentialCount;
	}
}

void UndirectedClusteringCoefficient::removeTriangle(Node * origin)
{
	this->triangleCount--;
	this->nodeTriangleCount->decr(origin->getIndex());
	this->updateNode(origin->getIndex());
}

void UndirectedClusteringCoefficient::updateNode(int index)
{
	if (this->nodePotentialCount->getValue(index) == 0) {
		this->localCC->setValue(index, 0);
	}
	else {
		this->localCC->setValue(index,
			(double) this->nodeTriangleCount->getValue(index)
			/ this->nodePotentialCount->getValue(index));
	}
	if (this->potentialCount == 0) {
		this->globalCC = 0;
		this->averageCC = 0;
	}
	else {
		this->globalCC = (double) this->triangleCount
			/ (double) this->potentialCount;
		this->averageCC = ArrayUtils::avgIgnoreNaN(this->localCC->getValues());
	}
}

void UndirectedClusteringCoefficient::removePotentials(Node * origin, int count)
{
	this->potentialCount -= count;
	this->nodePotentialCount->sub(origin->getIndex(), count);
	this->updateNode(origin->getIndex());
}

void UndirectedClusteringCoefficient::addTriangle(Node * origin)
{
	this->triangleCount++;
	this->nodeTriangleCount->incr(origin->getIndex());
	this->updateNode(origin->getIndex());
}

void UndirectedClusteringCoefficient::addPotentials(Node * origin, int count)
{
	this->potentialCount += count;
	this->nodePotentialCount->add(origin->getIndex(), count);
	this->updateNode(origin->getIndex());
}

