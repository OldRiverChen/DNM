
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

bool UndirectedClusteringCoefficient::computeUndirected()//������ܵ�V�Σ������Σ�3������ͨ�ṹ��2�����Σ��ĸ���
{
	INodeListDatastructure* allNode = this->getNodesOfAssignedTypes();
	for (int i = 0; i < allNode->size(); i++)//
	{
		UndirectedNode* a = (UndirectedNode*)allNode->get(i);//��ȡһ������a
		IEdgeListDatastructure* aEdges = a->getEdges();//��ȡ��Ӧ����a���ڽӱ߼�
		DArrayList* dal_aEdges = (DArrayList*)aEdges;//����ת
		for (int j = 0; j < dal_aEdges->size(); j++)//��ȡa��������,
		{
			UndirectedEdge* e1 = (UndirectedEdge*)dal_aEdges->getEdge(j);//��ȡ����a��һ����e1
			UndirectedNode* b = (UndirectedNode*)e1->getDifferingNode(a);//��ȡ����a��e1����һ���˵�b
			for (int k = 0; k < dal_aEdges->size(); k++)
			{
				UndirectedEdge* e2 = (UndirectedEdge*)dal_aEdges->getEdge(k); // ��ȡ����a������һ����e2
				UndirectedNode* c = (UndirectedNode*)e2->getDifferingNode(a);////��ȡ����a��e2����һ���˵�c
				if (b->equals(c)) {//˵��e1��e2��ͬһ����,
					continue;
				}
				this->nodePotentialCount->incr(a->getIndex());//˵��a����Ŀ��ܵ�V�εĸ���+1�����������ظ� 0,1,2,   0,2,1Ϊ������ͬ����״
				if (b->hasEdge(b, c))//��b�����Ƿ����һ����ָ��c��
				{
					this->nodeTriangleCount->incr(a->getIndex());//˵��a����Ŀ��ܵ������εĸ���+1�����������ظ�����ͬ��������Ϊ��ͬ��0,1,2,   0,2,1Ϊ������ͬ����״
				}
			}
		}
		this->nodeTriangleCount->div(a->getIndex(), 2);//ȥ�ظ�
		this->nodePotentialCount->div(a->getIndex(),2);//ȥ�ظ�

		this->update(a->getIndex());//���¸�������ľ���ϵ��

	}
	this->update();//����ȫ�ֵľ���ϵ��
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

