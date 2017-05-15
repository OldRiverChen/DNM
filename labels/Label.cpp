#include "Label.h"

Label::Label()
{
	new (this)Label(name,NULL,NULL);
}

Label::Label(string name, string type, string value)
{
	this->name = name;
	this->type = type;
	this->value = value;
}

string Label::getType()
{
	return this->type;
}

string Label::getValue()
{
	return this->value;
}

string Label::toString()
{
	return  this->name + " ~~ " + this->type
		+ " ~~ " + this->value;;
}

string Label::getName()
{
	return this->name;
}
