#include "AggregatedMetric.h"

AggregatedMetric::AggregatedMetric(string name)
{
	this->name = name;
	this->values = new AggregatedValueList();
	this->distributions = new AggregatedDistributionList();
	this->nodevalues = new AggregatedNodeValueListList();
}

AggregatedMetric::AggregatedMetric(string name, int sizeValues, int sizeDistributions, int sizeNodeValueList)
{
	this->name = name;
	this->values = new AggregatedValueList(sizeValues);
	this->distributions = new AggregatedDistributionList(sizeDistributions);
	this->nodevalues = new AggregatedNodeValueListList(sizeNodeValueList);
}

AggregatedMetric::AggregatedMetric(string name, AggregatedValueList * values, AggregatedDistributionList * distributions, AggregatedNodeValueListList * nodevalues)
{
	this->name = name;
	this->values = values;
	this->distributions = distributions;
	this->nodevalues = nodevalues;
}

string AggregatedMetric::getName()
{
	return this->name;
}

AggregatedValueList * AggregatedMetric::getValues()
{
	return values;
}

AggregatedDistributionList * AggregatedMetric::getDistributions()
{
	return distributions;
}

AggregatedNodeValueListList * AggregatedMetric::getNodeValues()
{
	return nodevalues;
}

void AggregatedMetric::write(string dir)
{
}

AggregatedMetric * AggregatedMetric::read(string dir, string name, BatchReadMode batchReadMode)
{
	return nullptr;
}
