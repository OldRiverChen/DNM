#ifndef _DATA_H_

#define _DATA_H_

#include <string>
#include <iostream>
#include "lists\ListItem.h"
using namespace std;
/**
* Data is the super-class for all provided data-structures.
*
*/
class Data:public ListItem
{
private:
	string name;
public:
	Data();
	Data(string name);
	static bool equals();
public://实现接口
	string getName();


};

#endif