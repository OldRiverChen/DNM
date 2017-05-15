#ifndef _A_NODEADDITION_H_

#define _A_NODEADDITION_H_
//一个抽象类
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Update.h"
#include "NodeUpdate.h"
#include "..\..\..\graph\edges\Edge.h"
#include "..\..\..\graph\Graph.h"
#include "..\..\..\graph\datastructures\GraphDataStructure.h"
#include "..\..\..\graph\nodes\Node.h"
using namespace std;


class NodeAddition:public NodeUpdate
{
public:
	NodeAddition(Node* node);
	NodeAddition(string str, GraphDataStructure* gds);
public://实现父类方法
	bool apply_(Graph* g);
	string getType();
	string asString_();
	string toString_();

	

};

#endif
