#ifndef _ARRAYUTILS_H_

#define _ARRAYUTILS_H_
#include <string>
#include <iostream> 
#include <vector>
#include <limits>
using namespace std;

class ArrayUtils
{
public:
	const static double Double_NaN;
public:
	static double avgIgnoreNaN(vector<double>* values);
	static vector<string>* split(string& s, string delim);
};

#endif