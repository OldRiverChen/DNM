#ifndef _LONGLIST_H_

#define _LONGLIST_H_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class LongList
{
public:
	vector<long>* values;
public:
	LongList();
	LongList(vector<long>* values);
	LongList(int length);
public:
	int size();
	vector<long>* getValues();
	long sum();
	long getValue(int index);
	void setValue(int index, long value);
	long div(int index, long value);
	long mult(int index, long value);
	long add(int index,long count);
	long sub(int index, long count);
	long incr(int index);
	long decr(int index);
};

#endif