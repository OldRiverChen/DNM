#include "NodeValueListList.h"
#include "..\..\..\io\filesystem\Files.h"

NodeValueListList::NodeValueListList():List()
{
}

NodeValueListList::NodeValueListList(int size) : List(size)
{
}

void NodeValueListList::write(string dir)
{
	for (map<string, NodeValueList*>::iterator iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		string name = iter->first;
		NodeValueList* value = iter->second;
		string NodeValueList_Name = value->getName();
		string NodeValueList_Filename = Files::getNodeValueListFilename(NodeValueList_Name);
		value->write(dir,NodeValueList_Filename);
	}
}
