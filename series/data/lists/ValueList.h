#ifndef _VALUELIST_H_

#define _VALUELIST_H_

#include <string>
#include <iostream>
#include "SortedList.h"
#include "List.h"
#include "..\Value.h"
using namespace std;

class ValueList :public List<Value>
{
public:
	ValueList();
	ValueList(int size);
public:
	void write(string dir, string filename);
};

#endif