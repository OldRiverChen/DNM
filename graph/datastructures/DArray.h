#ifndef _DARRAY_H_

#define _DARRAY_H_


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "stdlib.h"
#include "..\IElement.h"
#include "..\nodes\INodeListDatastructure.h"
#include "..\edges\IEdgeListDatastructure.h"

using namespace std;
/**
Data structure to store IElements in an array ��c++ ����ʵ��
Node,Edge ����IElements������
*
*/
class DArray:public INodeListDatastructure,public IEdgeListDatastructure
{
public:
	IElement** lists;//һ������ָ��
	int count;//��ǰ�Ѿ��е�Ԫ�أ����ǿյ�,�൱��vector��size()
	int maxNodeIndex; 
public:
	DArray();
	int length;//�൱��java .length���ǳ�ʼ��(new)��ֵ
public:
	void init(int initialSize);


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
	IElement* getRandom();

	//IEdgeListDatastructure
	bool add(Edge* element);
	bool contains(Edge* element);
	bool remove(Edge* element);
	Edge* get(int n1, int n2);
	Edge* get(Edge* element);
public:
	void show()
	{
		cout << "DArray!!!" << endl;
		cout << "count="<< count << endl;
		cout << "maxNodeIndex=" << maxNodeIndex << endl;
	}

	
};

#endif
