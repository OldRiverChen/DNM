#include "LongList.h"
#include <limits>
LongList::LongList()
{
	this->values = new vector<long>();
}

LongList::LongList(vector<long>* values)
{
	this->values = values;
}

LongList::LongList(int length)
{
	new(this)LongList();
	this->values->resize(length);
}

int LongList::size()
{
	return this->values->size();
}

vector<long>* LongList::getValues()
{
	return this->values;
}

long LongList::sum()
{
	long sum = 0;
	for (auto iter = values->begin(); iter != values->end(); iter++)
		sum += (*iter);
	return sum;
}

long LongList::getValue(int index)
{
	long rs = (numeric_limits<long>::min)();
	if(index>=this->size()|| index<0)
		return rs;//返回long 的最小值;
	else {
		rs = this->values->at(index);
		return rs;
	}
}

void LongList::setValue(int index, long value)
{
	if (index >= this->values->size())
	{
		for (int i = this->values->size(); i < index + 1; i++)
			this->values->push_back(0);
	}
	this->values->at(index) = value;
}

long LongList::div(int index, long value)
{
	if (index >= this->values->size())
	{
		for (int i = this->values->size(); i < index + 1; i++)
			this->values->push_back(0);
	}
	this->values->at(index) /= value;
	return this->values->at(index);
}

long LongList::mult(int index, long value)
{
	if (index >= this->values->size())
	{
		for (int i = this->values->size(); i < index + 1; i++)
			this->values->push_back(0);
	}
	this->values->at(index) *= value;
	return this->values->at(index);
}

long LongList::add(int index, long count)
{
	if (index >= this->values->size())
	{
		for (int i = this->values->size(); i < index + 1; i++)
			this->values->push_back(0);
	}
	this->values->at(index) += count;
	return this->values->at(index);
}

long LongList::sub(int index, long count)
{
	return this->add(index,-count);
}

long LongList::incr(int index)
{
	return this->add(index,1);
}

long LongList::decr(int index)
{
	return this->sub(index,1);
}
