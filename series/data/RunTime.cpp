#include "RunTime.h"
RunTime::RunTime(string name, double runtime)
{
	this->name = name;
	this->runtime = runtime;
}
string RunTime::toString()
{
	return "runtime(" + this->name + "): " + to_string(this->getMilliSec()) + " msec";
}

double RunTime::getRuntime()
{
	return this->runtime;
}
double RunTime::getSec()
{
	return this->getMilliSec() / 1000.0;
}
double RunTime::getMilliSec()
{
	return this->getNanoSec() / 1000.0 / 1000.0;
}
double RunTime::getNanoSec()
{
	return this->runtime;
}

string RunTime::getName()
{
	return this->name;
}