#ifndef _SERIESDATA_H_

#define _SERIESDATA_H_

#include <string>
#include <iostream>
#include "RunData.h"
#include "..\aggdata\AggregatedSeries.h"

using namespace std;

class SeriesData
{
private:
	string dir;
	string name;
	vector<RunData*>* runs;
	AggregatedSeries* aggregation;
public:
	string getDir();
	string getName();
	vector<RunData*>* getRuns();
	AggregatedSeries* getAggregation();
public:
	static SeriesData* read(string dir,string name,bool readAggregation,bool readValues);
};

#endif