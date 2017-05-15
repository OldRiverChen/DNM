#ifndef _A_EDGEREMOVAL_H_

#define _A_EDGEREMOVAL_H_
//һ��������
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Update.h"
#include "EdgeUpdate.h"
#include "..\..\..\graph\edges\Edge.h"
#include "..\..\..\graph\Graph.h"
#include "..\..\..\graph\datastructures\GraphDataStructure.h"
#include "..\..\..\graph\nodes\Node.h"
using namespace std;


class EdgeRemoval:public EdgeUpdate
{
public:
	EdgeRemoval(Edge* edge);
	EdgeRemoval(string str, GraphDataStructure* gds,Graph* g,map<int,Node*>* addedNodes);
public://ʵ�ָ��෽��
	bool apply_(Graph* g);
	string getType();
	string asString_();
	string toString_();

	

};

#endif
