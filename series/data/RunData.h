#ifndef _RUNDATA_H_

#define _RUNDATA_H_

#include <string>
#include <iostream>
#include "lists\BatchDataList.h"
using namespace std;

class RunData
{
private:
	int run;
	BatchDataList* batches;
public:
	RunData(int run) {
		this->run = run;
		this->batches = new BatchDataList();
	}
	RunData(int run, int size) {
		this->run = run;
		this->batches = new BatchDataList(size);
	}
	RunData(int run, vector<BatchData*>* batches);
public:
	int getRun();
	BatchDataList* getBatches();
};

#endif