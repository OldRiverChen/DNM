#ifndef _AGGREGATEDBATCH_H_

#define _AGGREGATEDBATCH_H_

#include <string>
#include <iostream>
#include "..\data\IBatch.h"

using namespace std;

/**
* An AggregatedBatch contains aggregated values of a batch.
*

*/
class AggregatedValueList;
class AggregatedRunTimeList;
class AggregatedMetricList;
enum BatchReadMode
{
	readAllValues, readOnlySingleValues, readOnlyDistAndNvl, readNoValues, readOnlyLabels
};

class AggregatedBatch:public IBatch
{	
private:
	long long timestamp;
	AggregatedValueList* stats;
	AggregatedRunTimeList* generalRuntimes;
	AggregatedRunTimeList* metricRuntimes;
	AggregatedMetricList* metrics;
public:
	AggregatedBatch(long long timestamp);
public:
	long long getTimestamp();
};

#endif