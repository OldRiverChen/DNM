#ifndef _A_NODE_H_

#define _A_NODE_H_

//一个抽象类
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include "..\Element.h"
#include "..\..\util\MathHelper.h"
#include "..\..\util\Util.h"

using namespace std;

class Edge;
class GraphDataStructure;

class Node : public Element
{
protected:
	int index;
public:
	Node(int index, GraphDataStructure* gds)
	{
		this->index = index;
		this->init(gds);
	}
	Node(string str, GraphDataStructure* gds)
	{
		this->index = MathHelper::parseInt(str);
		this->init(gds);
	}
	bool operator==(Node* other)//重载了==
	{
		int f = this->asString().compare(other->asString());
		return f == 0;
	}
public:
	string asString();//实现接口IElement的方法
	bool equals(IElement* obj);
	bool hasEdge(Node* n1, Node* n2);
	bool hasEdge(int n1, int n2);
public:
	int getIndex();
	void setIndex(int index);
	virtual void init(GraphDataStructure* gds)
	{
	}
	virtual bool addEdge(Edge* e)
	{
		return false;
	}
	virtual int getDegree()
	{
		return -1;
	}
	virtual bool hasEdge_(Edge*e)
	{
		return false;
	}
	
	virtual bool removeEdge(Edge* e)
	{
		return false;
	}


};
class Node_find :public binary_function< IElement*, IElement*, bool >//定义一个仿函数，用于find_if函数
{
public:
	bool operator()(IElement* n1, IElement* n2) const
	{
		return n1->deepEquals(n2);
	}

};
class Node_less
{
public:
	bool operator()(Node* n1, Node* n2) const//定义一个仿函数，用于map find
	{
		return n1->getIndex() < n2->getIndex();
	}
};
#endif

//public:
//	virtual void init(GraphDataStructure* gds);
//	virtual bool hasEdge(Edge* e);
//	virtual bool addEdge(Edge* e);
//	virtual bool removeEdge(Edge* e);
//	virtual int getDegree();
//	virtual void print();
//	virtual vector<Element*> getEdges();

//public:
//	virtual string toString()
//	{
//		return to_string(this->index);
//	}
//	virtual int hashCode()
//	{
//		return this->index;
//	}
//	virtual bool equals(Node* o)
//	{
//		return o != NULL && instanceof<Node>(o) && (((Node *)o)->getIndex()) == this->index;
//	}
//	virtual int compareTo(Element* o)
//	{
//		if (!instanceof<Node>(o))
//		{
//			cout << "ClassCastException: not instanceof Node" << endl;
//			exit(0);
//		}
//		return this->index - ((Node *)o)->getIndex();
//	}

//public:
//	virtual void switchDataStructure()//应该不用实现
//	{
//
//	}
//public:
//	static int getIndex(string str)
//	{
//		return stringToNum<int>(str);
//	}
//