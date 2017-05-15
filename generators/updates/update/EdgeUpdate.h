#ifndef _A_EDGEUPDATE_H_

#define _A_EDGEUPDATE_H_
//一个抽象类
#include <iostream>
#include <string>
#include <vector>
#include "Update.h"
#include "..\..\..\graph\edges\Edge.h"
using namespace std;


class EdgeUpdate:public Update
{
public:
	Edge* edge;
public:
	EdgeUpdate(Edge* edge);
public:
	Edge* getEdge();
	

};
class EdgeUpdate_less
{
public:
	bool operator()(EdgeUpdate* e1, EdgeUpdate* e2) const;//定义一个仿函数，用于map set
};

#endif
