#ifndef _BATCHDATALIST_H_

#define _BATCHDATALIST_H_

#include <string>
#include <iostream>
#include "SortedList.h"
#include "..\BatchData.h"
using namespace std;

class BatchDataList:public SortedList<BatchData>
{
public:
	BatchDataList():SortedList()
	{}
	BatchDataList(int size) :SortedList(size)
	{}
public:
	void write(string dir);
};

#endif