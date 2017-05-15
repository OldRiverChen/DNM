#include "ValueList.h"
#include "..\..\..\io\Writer.h"

ValueList::ValueList():List()
{
}

ValueList::ValueList(int size):List(size)
{
}

void ValueList::write(string dir, string filename)
{
	Writer *w = Writer::getWriter(dir, filename);
	for (map<string, Value*>::iterator iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		string name = iter->first;
		Value* value = iter->second;
		w->writeln(name + "=" + to_string(value->getValue()));
	}
	w->close();
}
