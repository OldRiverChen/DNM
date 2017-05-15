#ifndef _NODEVALUELISTLIST_H_

#define _NODEVALUELISTLIST_H_

#include <string>
#include <iostream>
#include "List.h"
#include "..\nodevaluelists\NodeValueList.h"
using namespace std;

/**
* An NodeValueListList lists NodeValueList objects.
*
*/

class NodeValueListList :public List<NodeValueList>
{
public:
	NodeValueListList();
	NodeValueListList(int size);
public:
	void write(string dir);
};

#endif