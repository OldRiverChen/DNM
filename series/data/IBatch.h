#ifndef _I_IBATCH_H_

#define _I_IBATCH_H_
//一个接口
#include <string>
#include <iostream>
using namespace std;
/**
* Interface for BatchData and AggregatedBatch.
*
*/
class IBatch
{
public:
	virtual long long getTimestamp()=0;
	virtual bool contains(string domain, string value)
	{
		return false;
	}


};

#endif