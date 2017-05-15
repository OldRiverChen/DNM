#ifndef _I_IRECOMPUTATION_H_

#define _I_IRECOMPUTATION_H_
//一个接口
#include <string>
#include <iostream>
#include "..\IMetric.h"
using namespace std;

class IRecomputation :public IMetric
{
public:
	virtual bool recompute()=0;
};

#endif