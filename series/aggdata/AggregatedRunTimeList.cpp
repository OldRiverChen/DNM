#include "AggregatedRunTimeList.h"

AggregatedRunTimeList::AggregatedRunTimeList():List()
{
}

AggregatedRunTimeList::AggregatedRunTimeList(int size):List(size)
{
}

AggregatedRunTimeList::AggregatedRunTimeList(string name):List()
{
	this->name = name;
}

AggregatedRunTimeList::AggregatedRunTimeList(string name, int size):List(size)
{
	this->name = name;
}

string AggregatedRunTimeList::getName()
{
	return this->name;
}

void AggregatedRunTimeList::write(string dir, string filename)
{
}

AggregatedRunTimeList * AggregatedRunTimeList::read(string dir, string filename, bool readValues)
{
	return nullptr;
}
