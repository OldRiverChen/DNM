#ifndef _A_GROUPING_H_

#define _A_GROUPING_H_

//一个抽象类
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "..\..\..\graph\Graph.h"
#include "..\..\..\graph\edges\Edge.h"
#include "..\..\..\graph\nodes\Node.h"
using namespace std;

class Grouping
{
public:
	vector<int>* getKeys(Graph* g, Node* n1, Node* n2, string group);
protected:
	string getKey(Graph* g, Node* n1, Node* n2, string group);
protected:
	virtual set<string>* getGroups3(Edge* e);
	virtual set<string>* getGroups4(Edge* e);
	virtual set<string>* getGroups5(Edge* e);
};

#endif