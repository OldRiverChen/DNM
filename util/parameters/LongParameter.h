#ifndef _LONGPARAMEMTER_H_

#define _LONGPARAMEMTER_H_


#include <string>
#include <vector>
#include "../Parameter.h"
using namespace std;

class LongParameter : public Parameter
{
private:
	long value;

public:
	string getValue()
	{
		return to_string(this->value);
	}
public:
	LongParameter(string name, long value) :Parameter(name)
	{
		this->value = value;
	}

	long getLongValue()
	{
		return this->value;
	}



};

#endif

