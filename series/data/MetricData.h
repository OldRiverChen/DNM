#ifndef _METRICDATA_H_

#define _METRICDATA_H_

#include <string>
#include <iostream>
#include "lists\ListItem.h"
#include "lists\ValueList.h"
#include "lists\DistributionList.h"
#include "lists\NodeValueListList.h"
#include "lists\NodeNodeValueListList.h"
#include "Value.h"
using namespace std;

class MetricData:public ListItem
{
public:
	string name;
	string type;
	ValueList* values;
	DistributionList<int, vector<long>>* distributions;
	NodeValueListList* nodevalues;
	NodeNodeValueListList* nodenodevalues;
public:
	MetricData(string name);
	MetricData(string name, string type, int sizeValues, int sizeDistributions, int sizeNodeValueList);
	MetricData(string name, string type, vector<Value*>* values, vector<Distr<int, vector<long>>*>* distributions,
		vector<NodeValueList*>* nodevalues, vector<NodeNodeValueList*>* nodenodevalues);
	MetricData(string name, string type, ValueList*values, DistributionList<int, vector<long>>* distributions, 
		NodeValueListList* nodevalues, NodeNodeValueListList* nodenodevalues);
public:
	string getName();
	string getType();
	ValueList* getValues();
	DistributionList<int, vector<long>>* getDistributions();
	NodeValueListList* getNodeValues();
	NodeNodeValueListList*getNodeNodeValues();
public:
	void write(string dir);
};

#endif