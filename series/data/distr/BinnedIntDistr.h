#ifndef _A_BINNEDINTDISTR_

#define _A_BINNEDINTDISTR_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "BinnedDistr.h"

using namespace std;

class BinnedIntDistr : public BinnedDistr<int>
{
public:
	BinnedIntDistr(string name);
	BinnedIntDistr(string name,int& binSize);
public:
	int getIndex(int& value);
	vector<int>* getBin(int& index);
	string getDistrType();

	/**
	* note that this average is computed with each call of this function. also
	* note that this is NOT the correct and actual average of the values used
	* to fill this distribution because the max value is assumed for each value
	* counted in a bin. hence, this value is an upper bound on the actual
	* value.
	*
	* @return average value of the property reflected by this distribution
	*/
	double computeAverage_();

};



#endif


