#ifndef _A_BINNEDDISTR_

#define _A_BINNEDDISTR_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Distr.h"
#include "..\..\..\io\Writer.h"
using namespace std;

template<class T>
class BinnedDistr:public Distr<T,vector<long> >
{
public:
	long denominator;
public:
	BinnedDistr(string name, T& binSize, vector<long>* values, long denominator);
	BinnedDistr(string name, T& binSize);

public:
	long getDenominator();
public:
	/**
	*
	* @param value
	*            value that should be mapped to an index for storing its
	*            occurrences in an array
	* @return the index this value is mapped to
	*/
	virtual int getIndex(T& value);
	virtual vector<T>* getBin(int& index);
public:
	/**
	* increases the occurrences for the given value by 1. in addition, the
	* denominator is increased by 1.
	*
	* @param value
	*            value to increase the number of occurrences for
	* @return number of occurrences after the increase
	*/
	long incr(T& value);
	/**
	* increases the occurrences for the given value by the specified count. in
	* addition, the denominator is increased by the same value
	*
	* @param value
	*            value to increase the number of occurrences for
	* @param count
	*            amount to increase by
	* @return number of occurrences after the increase
	*/
	long incr(T& value, int count);
	/**
	* decreases the occurrences for the given value by 1. in addition, the
	* denominator is decreased by 1.
	*
	* @param value
	*            value to decrease the number of occurrences for
	* @return number of occurrences after the decrease
	*/
	long decr(T& value);
	/**
	* decreases the occurrences for the given value by the specified count. in
	* addition, the denominator is decreased by the same value
	*
	* @param value
	*            value to decrease the number of occurrences for
	* @param count
	*            amount to decrease by
	* @return number of occurrences after the decrease
	*/
	long decr(T& value, int count);

	/**
	* note that this average is computed with each call of this function.
	*
	* @return average value of the property reflected by this distribution
	*/
	virtual double computeAverage();
	/**
	*
	* @return minimum index with a non-zero value (-1 in case no non-zero entry
	*         exists)
	*/
	int getMinNonZeroIndex();

	/**
	*
	* @return maximum index with a non-zero value (-1 in case no non-zero entry
	*         exists)
	*/
	int getMaxNonZeroIndex();

	void write(string dir, string filename);


};

template<class T>
BinnedDistr<T>::BinnedDistr(string name, T& binSize, vector<long>* values, long denominator) :Distr(name, binSize, values)
{
	this->denominator = denominator;
}

template<class T>
BinnedDistr<T>::BinnedDistr(string name, T& binSize):Distr(name, binSize, new vector<long>())
{
	this->denominator = 0;
}

template<class T>
long BinnedDistr<T>::getDenominator()
{
	return this->denominator;
}

template<class T>
int BinnedDistr<T>::getIndex(T & value)
{
	return -1;
}

template<class T>
vector<T>* BinnedDistr<T>::getBin(int& index)
{
	return NULL;
}

template<class T>
long BinnedDistr<T>::incr(T&value)
{
	return this->incr(value, 1);
}

template<class T>
long BinnedDistr<T>::incr(T &value, int count)
{
	int index = this->getIndex(value);
	if (index >= this->values->size()) {
		for (int i = this->values->size(); i < index + 1;i++)
			this->values->push_back(0);
	}
	this->values->at(index) += count;
	this->denominator += count;
	return this->values->at(index);
}

template<class T>
long BinnedDistr<T>::decr(T& value)
{
	return this->decr(value, 1);
}

template<class T>
long BinnedDistr<T>::decr(T& value, int count)
{
	int index = this->getIndex(value);
	this->values->at(index) -= count;
	this->denominator -= count;
	return this->values->at(index);
}

template<class T>
double BinnedDistr<T>::computeAverage()
{
	long sum = 0;
	for (int i = 1; i < this->values->size(); i++)
	{
		sum += i*this->values->at(i);
	}
	return (double)sum / (double) this->denominator;
}

template<class T>
int BinnedDistr<T>::getMinNonZeroIndex()
{
	for (int i = 0; i < this->values->size(); i++)
	{
		if (this->values->at(i) != 0)
			return i;
	}

	return -1;
}

template<class T>
int BinnedDistr<T>::getMaxNonZeroIndex()
{
	for (int i = this->values->size()-1; i>=0; i--)
	{
		if (this->values->at(i) != 0)
			return i;
	}

	return -1;
}

template<class T>
void BinnedDistr<T>::write(string dir, string filename)
{
	Writer *w = Writer::getWriter(dir, filename);
	w->writeln(to_string(this->denominator));
	w->writeln(to_string(this->binSize));
	if (this->values->size() > 0) {
		for (int i = 0; i < this->values->size(); i++)
		{
			string DISTRIBUTION_DELIMITER = "\t";
			w->writeln(to_string(i) + DISTRIBUTION_DELIMITER + to_string((int)this->values->at(i)));
		}
	}
	w->close();
}



#endif


