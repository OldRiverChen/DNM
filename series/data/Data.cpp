#include "Data.h"
Data::Data()
{}

Data::Data(string name)
{
	this->name = name;
}

bool Data::equals()
{
	return false;
}

string Data::getName()
{
	return this->name;
}

