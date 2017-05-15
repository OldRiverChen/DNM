#include "NodeNodeValueListList.h"
#include "..\..\..\io\filesystem\Files.h"

NodeNodeValueListList::NodeNodeValueListList():List()
{
}

NodeNodeValueListList::NodeNodeValueListList(int size):List(size)
{
}

void NodeNodeValueListList::write(string dir)
{
	for (map<string, NodeNodeValueList*>::iterator iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		string name = iter->first;
		NodeNodeValueList* value = iter->second;
		string NodeNodeValueList_Name = value->getName();
		string NodeNodeValueList_Filename = Files::getNodeValueListFilename(NodeNodeValueList_Name);
		value->write(dir, NodeNodeValueList_Filename);
	}
}
