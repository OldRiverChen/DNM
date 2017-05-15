#ifndef _AGGREGATEDMETRICLIST_H_

#define _AGGREGATEDMETRICLIST_H_

#include <string>
#include <iostream>
#include <vector>
#include "..\data\lists\List.h"
#include "AggregatedMetric.h"
using namespace std;

/**
* An AggregatedMetricList is a list containing AggregatedMetric objects.
*
*/
class AggregatedMetricList :public List<AggregatedMetric>
{	
public:
	AggregatedMetricList();
	AggregatedMetricList(int size);
public:
	void write(string dir);
	static AggregatedMetricList* read(string dir, BatchReadMode batchReadMode);
};

#endif