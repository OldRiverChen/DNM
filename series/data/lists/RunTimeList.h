#ifndef _RUNTIMELIST_H_

#define _RUNTIMELIST_H_

#include <string>
#include <iostream>
#include "SortedList.h"
#include "List.h"
#include "..\RunTime.h"
using namespace std;

class RunTimeList :public List<RunTime>
{
public:
	RunTimeList();
	RunTimeList(int size);
public:
	void write(string dir, string filename);
};

#endif