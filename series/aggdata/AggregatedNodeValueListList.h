#ifndef _AGGREGATEDNODEVALUELISTLIST_H_

#define _AGGREGATEDNODEVALUELISTLIST_H_

#include <string>
#include <iostream>
#include <vector>
#include "AggregatedNodeValueList.h"
#include "..\data\lists\List.h"
using namespace std;

/**
* An AggregatedValueList object contains a list of AggregatedValue objects.

*/
class AggregatedNodeValueListList :public List<AggregatedNodeValueList>
{	

public:
	AggregatedNodeValueListList();
	AggregatedNodeValueListList(int size);
public:
	void write(string dir);
	static AggregatedNodeValueListList* read(string dir, bool readValues);
};

#endif