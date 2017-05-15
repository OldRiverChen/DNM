#ifndef _A_DISTR_

#define _A_DISTR_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "..\Data.h"
using namespace std;

enum DistrType
{
	BINNED_DOUBLE, BINNED_INT, BINNED_LONG, QUALITY_DOUBLE, QUALITY_INT, QUALITY_LONG
};

template<class T,class V>
class Distr :public Data
{
public:
	T binSize;
	V* values;
public:
	Distr(string name,T& binSize,V* values);
public:
	T getBinSize();
	V* getValues();
public:
	static string getDistrTypeString(DistrType type);
public:
	/**
	* outputs the contents stored in this distribution
	*/
	virtual void print();
	/**
	* writes the contents of the distribution to the specified file in the
	* specified directory.
	*
	* @param dir
	*            directory where to store the output
	* @param filename
	*            file where to write the data to
	* @throws IOException
	*/
	virtual void write(string dir, string filename);

	virtual string getDistrType();



};

template<class T, class V>
Distr<T, V>::Distr(string name, T& binSize, V * values) :Data(name)
{
	this->binSize = binSize;
	this->values = values;
}

template<class T, class V>
T  Distr<T, V>::getBinSize()
{
	return binSize;
}

template<class T, class V>
V * Distr<T, V>::getValues()
{
	return values;
}


template<class T, class V>
string Distr<T, V>::getDistrTypeString(DistrType type)
{
	string rs("");
	switch (type)
	{
	case BINNED_DOUBLE:
		rs = "BINNED_DOUBLE";
		break;
	case BINNED_INT:
		rs = "BINNED_INT";
		break;
	case BINNED_LONG:
		rs = "BINNED_LONG";
		break;
	case QUALITY_DOUBLE:
		rs = "QUALITY_DOUBLE";
		break;
	case QUALITY_INT:
		rs = "QUALITY_INT";
		break;
	case QUALITY_LONG:
		rs = "QUALITY_LONG";
		break;
	}
	return rs;
}

template<class T, class V>
void Distr<T, V>::print()
{
}

template<class T, class V>
void Distr<T, V>::write(string dir, string filename)
{

}

template<class T, class V>
string Distr<T, V>::getDistrType()
{
	return string("");
}



#endif

