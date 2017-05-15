#ifndef _AGGREGATEDDISTRIBUTIONLIST_H_

#define _AGGREGATEDDISTRIBUTIONLIST_H_

#include <string>
#include <iostream>
#include <vector>
#include "AggregatedDistribution.h"
#include "..\data\lists\List.h"
using namespace std;

/**
* An AggregatedValueList object contains a list of AggregatedValue objects.

*/
class AggregatedDistributionList :public List<AggregatedDistribution>
{	

public:
	AggregatedDistributionList();
	AggregatedDistributionList(int size);
public:
	void write(string dir);
	static AggregatedDistributionList* read(string dir, bool readValues);
};

#endif