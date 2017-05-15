#ifndef _DHASHARRAYLIST_H_

#define _DHASHARRAYLIST_H_


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "..\IElement.h"
#include "..\nodes\INodeListDatastructure.h"
#include "..\edges\IEdgeListDatastructure.h"
#include "..\edges\Edge.h"
#include "..\..\util\Rand.h"

using namespace std;
/**
* We use a HashSet internally, and not a HashMap. A HashSet is faster on
* contains() operations, and this is the part that is to be fastened by this
* data structure java 
在C++中，我们有set
Node,Edge 都是IElements的子类
*
*/
class DHashArrayList:public INodeListDatastructure,public IEdgeListDatastructure
{
public:
	vector<IElement*>* lists;
	set<IElement*, Edge_compare>* sets;
	int maxNodeIndex; 
public:
	DHashArrayList();
public:
	void init(int initialSize);
private:
	set<IElement*>::iterator findEdge_set(Edge* e);
	vector<IElement*>::iterator findEdge_vector(Edge* e);
public://实现接口方法
	//IDataStructure
	void reinitializeWithSize(int size);
	bool add(IElement* element);//element用instanceof来判断添加的是Node 或 Edge
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
	IElement* getRandom();
public:
	void show()
	{
		cout << "DArray!!!" << endl;
		cout << "maxNodeIndex=" << maxNodeIndex << endl;
	}


	
};

#endif
