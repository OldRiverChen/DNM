#ifndef _AGGREGATEDVALUE_H_

#define _AGGREGATEDVALUE_H_

#include <string>
#include <iostream>
#include <vector>
#include "AggregatedData.h"
using namespace std;

/**
* An AggregatedValue object contains aggregated values.
*
*/
class AggregatedValue:public AggregatedData
{	
private:
	vector<double>* values;
	// AggregatedValue array structure: { avg, min, max, median, variance,
	// variance-low, variance-up, confidence-low, confidence-up }
public:
	double getAvg();
	double getMin();
	double getMax();
	double getMedian();
	double getVariance();
	double getVarianceLow();
	double getVarianceUp();
	double getConfidenceLow();
	double getConfidenceUp();
	vector<double>* getValues();
	void write(string dir, string filename);
	static AggregatedValue* read(string dir, string filename, string name, bool readValues);
public:
	AggregatedValue(string name);
	AggregatedValue(string name, vector<double>*values);

};

#endif