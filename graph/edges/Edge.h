#ifndef _A_EDGE_H_

#define _A_EDGE_H_

//一个抽象方法
#include <string>
#include <vector>
#include <cmath>
#include "..\Element.h"
class Node;
class Edge :public Element
{
protected:
	Node* n1;
	Node* n2;
protected:
	void init(Node* n1, Node* n2);
public:
	Node* getN1();
	Node* getN2();
public:
	/**
	* Register this edge at both aligning nodes
	*
	* @return success of addition
	*/
	virtual bool connectToNodes()
	{
		return false;
	}
	virtual int getN1Index();

	virtual int getN2Index();

	/**
	*
	* @param n
	*            node to get the differing one connected by this edge
	* @return null of the given node is not one of the two nodes connected by
	*         this edge; otherwise, the connected node different from this one
	*         is returned
	*/
	Node* getDifferingNode(Node* n);

	/**
	* Remove this edge from both aligning nodes
	*
	* @return success of removal
	*/
	virtual bool disconnectFromNodes() = 0;


};

class Edge_compare
{
public:
	bool operator() (const IElement* e1, const IElement* e2)const;
};

class Edge_find :public binary_function< IElement*, IElement*, bool >//定义一个仿函数，用于find_if函数
{
public:
	bool operator()(IElement* n1, IElement* n2) const;

};
class Edge_less
{
public:
	bool operator()(Edge* e1, Edge* e2) const;//定义一个仿函数，用于map set
};
#endif


//
//	int getN1Index()
//	{
//		return this->n1->getIndex();
//	}
//
//	int getN2Index()
//	{
//		return this->n2->getIndex();
//	}
//
//	int hashCode()
//	{
//		return getHashcode(n1->getIndex(), n2->getIndex());
//	}
//
//public:
//	static int getHashcode(Node* n1, Node* n2) {
//		return getHashcode(n1->getIndex(), n2->getIndex());
//	}
//
//	static int getHashcode(int n1Index, int n2Index)
//	{
//		return n1Index * (int)pow(2, 16) + n2Index;
//	}
//
//
//	
//
//	/**
//	* Remove this edge from both aligning nodes
//	*
//	* @return success of removal
//	*/
//	//virtual bool disconnectFromNodes() = 0;
//
//public:
//	/**
//	* checks if this edge connects both given nodes
//	*
//	* @param n1
//	* @param n2
//	* @return true, if this edges connects the two given nodes; false otherwise
//	*/
//	virtual bool isConnectedTo(Node* n1, Node* n2)
//	{
//		return (this->getN1()->equals(n1) && this->getN2()->equals(n2)) || (this->getN1()->equals(n2) && this->getN2()->equals(n1));
//	}
//	/**
//	* checks if this edge connects both given nodes
//	*
//	* @param n1
//	* @param n2
//	* @return true, if this edges connects the two given nodes; false otherwise
//	*/
//	virtual bool isConnectedTo(int n1, int n2)
//	{
//		return (this->getN1Index() == n1 && this->getN2Index() == n2) || (this->getN1Index() == n2 && this->getN2Index() == n1);
//	}
//	/**
//	* checks if thus edges connects the given node to another node
//	*
//	* @param n1
//	* @return true, if this edge connect the giben node; false oterhwise
//	*/
//	virtual bool isConnectedTo(Node* n1)
//	{
//		return this->getN1()->equals(n1) || this->getN2()->equals(n1);
//	}
//
//	/**
//	* Returns a simple string that is necessary for the hash table
//	*/
//	virtual string getHashString()
//	{
//		return to_string(this->hashCode());
//	}
//
//	/**
//	* Call this method to get the opposite end of an edge
//	*
//	* @param n
//	*            "Entry" node of this edge
//	* @return "Exit" node of this edge
//	*/
//	/**
//	*
//	* @param n
//	*            node to get the differing one connected by this edge
//	* @return null of the given node is not one of the two nodes connected by
//	*         this edge; otherwise, the connected node different from this one
//	*         is returned
//	*/
//	virtual Node* getDifferingNode(Node* n)
//	{
//		if (this->getN1()->equals(n))
//		{
//			return this->getN2();
//		}
//		else if (this->getN2()->equals(n))
//		{
//			return this->getN1();
//		}
//		else return NULL;
//	}
//


