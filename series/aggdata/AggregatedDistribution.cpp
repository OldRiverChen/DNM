#include "AggregatedDistribution.h"

AggregatedDistribution::AggregatedDistribution(string name):AggregatedData(name)
{
}

AggregatedDistribution::AggregatedDistribution(string name, vector<AggregatedValue*>* values): AggregatedData(name)
{
	this->values = values;
}

vector<AggregatedValue*>* AggregatedDistribution::getValues()
{
	return this->values;
}

void AggregatedDistribution::write(string dir, string filename)
{
}

void AggregatedDistribution::read(string dir, string filename, bool readValues)
{
}
