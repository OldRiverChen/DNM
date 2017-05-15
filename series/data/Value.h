#ifndef _VALUE_H_

#define _VALUE_H_

#include <string>
#include <iostream>
#include "Data.h"
#include "..\..\util\Log.h"
using namespace std;
class Value :public Data
{
private:
	double value;
public:
	Value(string name,double value);
	Value(string name, double values[]);
	string toString();
	double getValue();




};

#endif