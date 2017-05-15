
//一个抽象方法
#include <string>
#include <vector>
#include <cmath>
#include "..\nodes\Node.h"
#include "..\Element.h"
#include "Edge.h"

using namespace std;

void Edge::init(Node * n1, Node * n2)
{
	this->n1 = n1;
	this->n2 = n2;
}

Node * Edge::getN1()
{
	return this->n1;
}

Node * Edge::getN2()
{
	return this->n2;
}

int Edge::getN1Index()
{
	return n1->getIndex();
}

int Edge::getN2Index()
{
	return n2->getIndex();
}

Node * Edge::getDifferingNode(Node * n)
{
	if (this->getN1()->equals(n)) {
		return this->getN2();
	}
	else if (this->getN2()->equals(n)) {
		return this->getN1();
	}
	else {
		return NULL;
	}
}



//bool Edge::isConnectedTo(Node * n1)
//{
//	return this->getN1()->equals(n1) || this->getN2()->equals(n1);
//}
//
//Node * Edge::getDifferingNode(Node * n)

bool Edge_compare::operator()(const IElement* e1, const IElement* e2) const
{
	Edge* edge1 = (Edge*)e1;
	Edge* edge2 = (Edge*)e2;
	if (edge1->getN1()->getIndex() != edge2->getN1()->getIndex())
	{
		return edge1->getN1()->getIndex() < edge2->getN1()->getIndex();
	}
	else return  edge1->getN2()->getIndex()<  edge2->getN2()->getIndex();
}

bool Edge_find::operator()(IElement* n1, IElement* n2) const
{
	Edge* edge1 = (Edge*)n1;
	Edge* edge2 = (Edge*)n2;
	return (edge1->getN1()->getIndex() == edge2->getN1()->getIndex()) && (edge1->getN2()->getIndex() == edge2->getN2()->getIndex());

}

bool Edge_less::operator()(Edge * e1, Edge * e2) const
{
	if (e1->getN1()->getIndex() != e2->getN1()->getIndex())
	{
		return e1->getN1()->getIndex() < e2->getN1()->getIndex();
	}
	else return  e1->getN2()->getIndex()<  e2->getN2()->getIndex();
}
