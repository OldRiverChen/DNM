#include <string>
#include <vector>
#include <iostream>
#include "..\Element.h"
#include "..\edges\Edge.h"
#include "..\datastructures\GraphDataStructure.h"
#include "..\..\util\MathHelper.h"
#include "..\..\util\Util.h"
#include "Node.h"

using namespace std;
string Node::asString()
{
	return to_string(this->index);
}

bool Node::equals(IElement * obj)
{
	return obj!=NULL && instanceof<Node>(obj) && ((Node*)obj)->getIndex()==this->index;
}

bool Node::hasEdge(Node * n1, Node * n2)
{
	Edge* e = GraphDataStructure::getCurrent()->getDummyEdge(n1, n2);
	return hasEdge_(e);
}

bool Node::hasEdge(int n1, int n2)
{
	Edge* e = GraphDataStructure::getCurrent()->getDummyEdge(n1, n2);
	return hasEdge_(e);
}

int Node::getIndex()
{
	return this->index;
}

void Node::setIndex(int index)
{
	this->index = index;
}

//void Node::init(GraphDataStructure * gds)
//{
//}
//
//bool Node::hasEdge(Edge * e)
//{
//	return false;
//}
//
//bool Node::addEdge(Edge * e)
//{
//	return false;
//}
//
//bool Node::removeEdge(Edge * e)
//{
//	return false;
//}
//
//int Node::getDegree()
//{
//	return 0;
//}
//
//void Node::print()
//{
//}
//
//vector<Element*> Node::getEdges()
//{
//	return vector<Element*>();
//}