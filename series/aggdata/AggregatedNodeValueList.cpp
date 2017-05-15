#include "AggregatedNodeValueList.h"

AggregatedNodeValueList::AggregatedNodeValueList(string name):AggregatedData(name)
{
}

AggregatedNodeValueList::AggregatedNodeValueList(string name, vector<AggregatedValue*>* values):AggregatedData(name)
{
	this->values = values;
}

vector<AggregatedValue*>* AggregatedNodeValueList::getValues()
{
	return this->values;
}

string AggregatedNodeValueList::getName()
{
	return AggregatedData::getName();
}

vector<int>* AggregatedNodeValueList::getSortIndex()
{
	return this->sortIndex;
}

AggregatedNodeValueList * AggregatedNodeValueList::read(string dir, string filename, string name, bool readValues)
{
	return nullptr;
}

void AggregatedNodeValueList::write(string dir, string filename, bool writeSorted)
{
}

void AggregatedNodeValueList::write(string dir, string filename)
{
}
