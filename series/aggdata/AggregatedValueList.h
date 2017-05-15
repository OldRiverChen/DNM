#ifndef _AGGREGATEDVALUELIST_H_

#define _AGGREGATEDVALUELIST_H_

#include <string>
#include <iostream>
#include <vector>
#include "AggregatedValue.h"
#include "..\data\lists\List.h"
using namespace std;

/**
* An AggregatedValueList object contains a list of AggregatedValue objects.

*/
class AggregatedValueList :public List<AggregatedValue>
{	

public:
	AggregatedValueList();
	AggregatedValueList(int size);
public:
	void write(string dir,string filename);
	static AggregatedValueList* read(string dir, string filename, bool readValues);
};

#endif