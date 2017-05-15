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
Data structure to store IElements in an array ：c++ 数组实现
Node,Edge 都是IElements的子类
*
*/
class DArray:public INodeListDatastructure,public IEdgeListDatastructure
{
public:
	IElement** lists;//一个二级指针
	int count;//当前已经有的元素，不是空的,相当于vector的size()
	int maxNodeIndex; 
public:
	DArray();
	int length;//相当于java .length，是初始化(new)的值
public:
	void init(int initialSize);


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
