#ifndef _A_NODEUPDATE_H_

#define _A_NODEUPDATE_H_
//一个抽象类
#include <iostream>
#include <string>
#include <vector>
#include "Update.h"
#include "..\..\..\graph\nodes\Node.h"
using namespace std;


class NodeUpdate :public Update
{
public:
	Node* node;
public:
	NodeUpdate(Node* node);
public:
	Node* getNode();
	

};
class NodeUpdate_less
{
public:
	bool operator()(NodeUpdate* n1, NodeUpdate* n2) const;//定义一个仿函数，用于map ,set
};


#endif
