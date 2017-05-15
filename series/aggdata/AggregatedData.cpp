#include "AggregatedData.h"
#include "AggregatedValue.h"
AggregatedData::AggregatedData()
{
}

AggregatedData::AggregatedData(string name)
{
	this->name = name;
}

string AggregatedData::getName()
{
	return this->name;
}

void AggregatedData::write(vector<AggregatedValue*> inputData, string dir, string filename)
{

}
