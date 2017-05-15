#ifndef _GROUPINGV1_H_

#define _GROUPINGV1_H_

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "..\..\..\graph\Graph.h"
#include "..\..\..\graph\edges\Edge.h"
#include "..\..\..\graph\nodes\Node.h"
#include "Grouping.h"
using namespace std;

class GroupingV1
{
protected://实现父类的函数
	/*
	* 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
	*/
	set<string>* getGroups3(Edge* e);
	set<string>* getGroups4(Edge* e);
	/*
	* 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
	*/

	set<string>* getGroups5(Edge* e);
protected:
	static void add4(set<string> set, Node* l, Node* r);
};

#endif