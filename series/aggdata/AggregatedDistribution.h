#ifndef _AGGREGATEDDISTRIBUTION_H_

#define _AGGREGATEDDISTRIBUTION_H_

#include <string>
#include <iostream>
#include <vector>
#include "AggregatedData.h"
#include "AggregatedValue.h"
using namespace std;

/**
* AggregatedDistribution is a class containing the values of an aggregated
* Distribution. It contains an array of AggregatedValue objects.
* AggregatedValue object array structure: { x (diff number), avg, min, max,
* median, variance, variance-low, variance-up, confidence-low, confidence-up }
*
*/
class AggregatedDistribution :public AggregatedData
{	
private:
	vector<AggregatedValue*>* values;
public:
	AggregatedDistribution(string name);
	AggregatedDistribution(string name, vector<AggregatedValue*>* values);
public:
	vector<AggregatedValue*>* getValues();
	void write(string dir,string filename);
	static void read(string dir, string filename, bool readValues);
};

#endif