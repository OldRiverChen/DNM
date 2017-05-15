#include "UndirectedEdge.h"
#include "..\nodes\UndirectedNode.h"

UndirectedEdge::UndirectedEdge(UndirectedNode * node1, UndirectedNode * node2)
{
	this->init_(node1, node2);
}

string UndirectedEdge::asString()
{
	return to_string(this->getN1()->getIndex())+ UndirectedEdge::separator +to_string(this->getN2()->getIndex());
}

UndirectedNode * UndirectedEdge::getNode1()
{
	return (UndirectedNode*)this->getN1();
}

UndirectedNode * UndirectedEdge::getNode2()
{
	return (UndirectedNode*)this->getN2();
}

void UndirectedEdge::init_(UndirectedNode * node1, UndirectedNode * node2)
{
	if (node1->getIndex() > node2->getIndex())
	{
		this->init(node2, node1);
	}
	else {
		this->init(node1, node2);
	}
}

bool UndirectedEdge::connectToNodes()
{
	bool add1 = this->getNode1()->addEdge(this);
	bool add2= this->getNode2()->addEdge(this);
	return add1&&add2;
}

int UndirectedEdge::getN1Index()
{
	return getNode1()->getIndex();
}

int UndirectedEdge::getN2Index()
{
	return getNode2()->getIndex();
}

bool UndirectedEdge::disconnectFromNodes()
{
	bool rm1 = this->getNode1()->removeEdge(this);
	bool rm2 = this->getNode2()->removeEdge(this);
	return rm1&&rm2;
}

const string UndirectedEdge::separator = "<->";//初始化静态常变量