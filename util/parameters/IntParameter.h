#ifndef _INTPARAMEMTER_H_

#define _INTPARAMEMTER_H_


#include <string>
#include <vector>
#include "../Parameter.h"
using namespace std;

class IntParameter : public Parameter
{
private:
	int value;

public:
	string getValue()
	{
		return to_string(this->value);
	}
public:
	IntParameter(string name, int value) :Parameter(name)
	{
		this->value = value;
	}

	int getIntValue()
	{
		return this->value;
	}



};

#endif

