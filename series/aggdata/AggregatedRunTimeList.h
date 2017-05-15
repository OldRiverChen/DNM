#ifndef _AGGREGATEDRUNTIMELIST_H_

#define _AGGREGATEDRUNTIMELIST_H_

#include <string>
#include <iostream>
#include <vector>
#include "AggregatedValue.h"
#include "..\data\lists\List.h"
using namespace std;

/**
* An AggregatedValueList object contains a list of AggregatedValue objects.

*/
class AggregatedRunTimeList :public List<AggregatedValue>
{	
private:
	string name;
public:
	AggregatedRunTimeList();
	AggregatedRunTimeList(int size);
	AggregatedRunTimeList(string name);
	AggregatedRunTimeList(string name,int size);
public:
	string getName();
	void write(string dir,string filename);
	static AggregatedRunTimeList* read(string dir, string filename, bool readValues);
};

#endif