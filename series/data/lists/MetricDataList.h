#ifndef _METRICDATALIST_H_

#define _METRICDATALIST_H_

#include <string>
#include <iostream>
#include "List.h"
#include "..\MetricData.h"
using namespace std;

class MetricDataList :public List<MetricData>
{
public:
	MetricDataList();
	MetricDataList(int size);
public:
	void write(string dir);
};

#endif