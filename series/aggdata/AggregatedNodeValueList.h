#ifndef _AGGREGATEDNODEVALUELIST_H_

#define _AGGREGATEDNODEVALUELIST_H_

#include <string>
#include <iostream>
#include <vector>
#include "AggregatedData.h"
using namespace std;

/**
* AggregatedNodeValueList is a class containing the values of an aggregated
* NodeValueList. It contains an array of AggregatedValue objects.
* AggregatedValue object array structure: { x (diff number), avg, min, max,
* median, variance, variance-low, variance-up, confidence-low, confidence-up,
* sort-order } Note: Sort-order fields are for plotting purposes only.

*/
class AggregatedNodeValueList :public AggregatedData
{	
private:
	vector<AggregatedValue*>* values;
	vector<int>* sortIndex;
public:
	AggregatedNodeValueList(string name);
	AggregatedNodeValueList(string name, vector<AggregatedValue*>* values);
public:
	vector<AggregatedValue*>* getValues();
	string getName();
	vector<int>* getSortIndex();
	static AggregatedNodeValueList* read(string dir, string filename, string name, bool readValues);
	void write(string dir,string filename,bool writeSorted);
	void write(string dir, string filename);

};

#endif