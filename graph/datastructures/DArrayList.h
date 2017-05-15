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
Data structure to store IElements in an arrayList��c++�����vector
Node,Edge ����IElements������
*
*/
class DArrayList:public INodeListDatastructure,public IEdgeListDatastructure
{
public:
	vector<IElement*>* lists;//һ������
	int maxNodeIndex; 
public:
	DArrayList();
public:
	void init(int initialSize);
private:
	vector<IElement*>::iterator findNode(Node* n);
	vector<IElement*>::iterator findEdge_vector(Edge* e);

public://ʵ�ֽӿڷ���
	//IDataStructure
	void reinitializeWithSize(int size);
	bool add(IElement* element);//element��instanceof���ж���ӵ���Node �� Edge,������ǵ������溯��
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
	Edge* getEdge(int index);//�����±�Ϊindex�ı�
	IElement* getRandom();
public:
	void show()
	{
		cout << "DArray!!!" << endl;
		cout << "maxNodeIndex=" << maxNodeIndex << endl;
	}

	
};

#endif
