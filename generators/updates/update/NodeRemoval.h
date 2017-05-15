#ifndef _A_NODEREMOVAL_H_

#define _A_NODEREMOVAL_H_
//һ��������
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


class NodeRemoval:public NodeUpdate
{
public:
	NodeRemoval(Node* node);
	NodeRemoval(string str, Graph* g);
public://ʵ�ָ��෽��
	bool apply_(Graph* g);
	string getType();
	string asString_();
	string toString_();

	

};


#endif
