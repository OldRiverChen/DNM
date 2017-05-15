#include "AggregatedValue.h"

double AggregatedValue::getAvg()
{
	return values->at(0);
}

double AggregatedValue::getMin()
{
	return values->at(1);
}

double AggregatedValue::getMax()
{
	return values->at(2);
}

double AggregatedValue::getMedian()
{
	return values->at(3);
}

double AggregatedValue::getVariance()
{
	return values->at(4);
}

double AggregatedValue::getVarianceLow()
{
	return values->at(5);
}

double AggregatedValue::getVarianceUp()
{
	return values->at(6);
}

double AggregatedValue::getConfidenceLow()
{
	return values->at(7);
}

double AggregatedValue::getConfidenceUp()
{
	return values->at(8);
}

vector<double>* AggregatedValue::getValues()
{
	return this->values;
}

void AggregatedValue::write(string dir, string filename)
{
}

AggregatedValue * AggregatedValue::read(string dir, string filename, string name, bool readValues)
{
	return nullptr;
}

AggregatedValue::AggregatedValue(string name):AggregatedData(name)
{
}

AggregatedValue::AggregatedValue(string name, vector<double>* values): AggregatedData(name)
{
	this->values = values;
}
