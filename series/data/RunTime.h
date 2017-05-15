#ifndef _RUNTIME_H_

#define _RUNTIME_H_

#include <string>
#include <iostream>
#include "lists\ListItem.h"
using namespace std;
/**
* Data is the super-class for all provided data-structures.
*
*/
class RunTime:public ListItem
{
private:
	string name;
	double runtime;
public:
	RunTime(string name, double runtime);
public:
	string toString();
	double getRuntime();
	double getSec();
	double getMilliSec();
	double getNanoSec();
public://实现接口
	string getName();


};

#endif