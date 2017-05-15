#ifndef _NODENODEVALUELISTLIST_H_

#define _NODENODEVALUELISTLIST_H_

#include <string>
#include <iostream>
#include "List.h"
#include "..\nodevaluelists\\NodeNodeValueList.h"
using namespace std;

/**
* An NodeValueListList lists NodeValueList objects.
*
*/

class NodeNodeValueListList :public List<NodeNodeValueList>
{
public:
	NodeNodeValueListList();
	NodeNodeValueListList(int size);
public:
	void write(string dir);
};

#endif