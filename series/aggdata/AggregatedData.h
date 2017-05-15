#ifndef _AGGREGATEDDATA_H_

#define _AGGREGATEDDATA_H_

#include <string>
#include <iostream>
#include "..\data\lists\ListItem.h"
using namespace std;

/**
* AggregatedData is the super-class for all provided aggregation
* data-structures.
*
*/
class AggregatedValue;
class AggregatedData:public ListItem
{	
private:
	string name;
public:
	AggregatedData();
	AggregatedData(string name);
public:
	string getName();

	static void write(vector<AggregatedValue*> inputData, string dir, string	filename);
};

#endif