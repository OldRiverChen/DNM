#ifndef _DARRAYLIST_H_

#define _DARRAYLIST_H_


#include <iostream>
#include <string>
#include <vector>
#include "..\IElement.h"
#include "..\nodes\INodeListDatastructure.h"
#include "..\edges\IEdgeListDatastructure.h"
#include "..\..\util\Rand.h"

using namespace std;
/**
Data structure to store IElements in an arrayList：c++里面的vector
Node,Edge 都是IElements的子类
*
*/
class DArrayList:public INodeListDatastructure,public IEdgeListDatastructure
{
public:
	vector<IElement*>* lists;//一个数组
	int maxNodeIndex; 
public:
	DArrayList();
public:
	void init(int initialSize);
private:
	vector<IElement*>::iterator findNode(Node* n);
	vector<IElement*>::iterator findEdge_vector(Edge* e);

public://实现接口方法
	//IDataStructure
	void reinitializeWithSize(int size);
	bool add(IElement* element);//element用instanceof来判断添加的是Node 或 Edge,具体的是调用下面函数
	bool contains(IElement* element);
	bool remove(IElement* element);
	int size();

	//INodeListDatastructure
	bool add(Node* element);
	bool contains(Node* element);
	bool remove(Node* element);
	int getMaxNodeIndex();
	Node* get(int index);

	//IEdgeListDatastructure
	bool add(Edge* element);
	bool contains(Edge* element);
	bool remove(Edge* element);
	Edge* get(int n1, int n2);
	Edge* get(Edge* element);
	Edge* getEdge(int index);//访问下标为index的边
	IElement* getRandom();
public:
	void show()
	{
		cout << "DArray!!!" << endl;
		cout << "maxNodeIndex=" << maxNodeIndex << endl;
	}

	
};

#endif
