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
��C++�У�������set
Node,Edge ����IElements������
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
public://ʵ�ֽӿڷ���
	//IDataStructure
	void reinitializeWithSize(int size);
	bool add(IElement* element);//element��instanceof���ж���ӵ���Node �� Edge
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
