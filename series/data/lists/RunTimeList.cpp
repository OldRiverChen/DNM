#include "RunTimeList.h"
#include "..\..\..\io\Writer.h"

RunTimeList::RunTimeList():List()
{
}

RunTimeList::RunTimeList(int size): List(size)
{
}

void RunTimeList::write(string dir, string filename)
{
	Writer *w = Writer::getWriter(dir, filename);
	for (map<string, RunTime*>::iterator iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		string name = iter->first;
		RunTime* value = iter->second;
		w->writeln(name + "=" + to_string(value->getRuntime()));
	}
	w->close();
}
