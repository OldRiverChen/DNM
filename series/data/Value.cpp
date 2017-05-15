#include "Value.h"
Value::Value(string name, double value) :Data(name)
{
	this->value = value;
}

Value::Value(string name, double value[])
{
	Log::warn("Value object initialized with to much arguments");
}

string Value::toString()
{
	return "value(" + this->getName() + ")=" + to_string(this->value);
}

double Value::getValue()
{
	return this->value;
}
