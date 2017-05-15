#ifndef _DOUBLEPARAMEMTER_H_

#define _DOUBLEPARAMEMTER_H_


#include <string>
#include <vector>
#include "../Parameter.h"
using namespace std;

class DoubleParameter: public Parameter
{
private:
	double value;

public:
	string getValue()
	{
		return to_string(value);
	}
public:
	DoubleParameter(string name,double value):Parameter(name)
	{
		this->value = value;
	}
	
	double returnDoubleValue() 
	{
		return this->value;
	}



};

#endif

