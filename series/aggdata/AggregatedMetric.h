#ifndef _AGGREGATEDMETRIC_H_

#define _AGGREGATEDMETRIC_H_

#include <string>
#include <iostream>
#include "..\data\lists\ListItem.h"
#include "AggregatedValueList.h"
#include "AggregatedDistributionList.h"
#include "AggregatedNodeValueListList.h"
#include "AggregatedBatch.h"
using namespace std;

/**
* An AggregatedMetric contains aggregated values of a metric.
*
*/
class AggregatedMetric :public ListItem
{	
private:
	string name;
	AggregatedValueList* values;
	AggregatedDistributionList* distributions;
	AggregatedNodeValueListList* nodevalues;
public:
	AggregatedMetric(string name);
	AggregatedMetric(string name, int sizeValues, int sizeDistributions, int sizeNodeValueList);
	AggregatedMetric(string name, AggregatedValueList* values, AggregatedDistributionList* distributions, AggregatedNodeValueListList* nodevalues);
public:
	string getName();
	AggregatedValueList* getValues();
	AggregatedDistributionList* getDistributions();
	AggregatedNodeValueListList* getNodeValues();
	void write(string dir);
	static AggregatedMetric* read(string dir, string name, BatchReadMode batchReadMode);
};

#endif