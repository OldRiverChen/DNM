#ifndef _I_IDYNAMICLGORITHMS_H_

#define _I_IDYNAMICLGORITHMS_H_

#include <string>
#include <iostream>
#include "..\IMetric.h"
using namespace std;

class IDynamicAlgorithm:public IMetric
{
public:
	virtual bool init()=0;
};

#endif