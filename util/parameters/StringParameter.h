#ifndef _STRINGPARAMEMTER_H_

#define _STRINGPARAMEMTER_H_


#include <string>
#include <vector>
#include "../Parameter.h"
using namespace std;

class StringParameter : public Parameter
{
private:
	string value;

public:
	string getValue()
	{
		return this->value;
	}
public:
	StringParameter(string name, string value) :Parameter(name)
	{
		this->value = value;
	}

	string getStringValue()
	{
		return this->value;
	}



};

#endif

