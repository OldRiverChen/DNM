#ifndef _LABEL_H_

#define _LABEL_H_

#include <string>
#include <iostream>
#include "..\series\data\lists\ListItem.h"
using namespace std;
/**
* Labels are used to label batches.
*
*/
class Label :public ListItem
{
private:
	string name;
	string type;
	string value;
public:
	Label();
	Label(string name, string type, string value);
	string getType();
	string getValue();
	string toString();
public://实现接口
	string getName();


};

#endif