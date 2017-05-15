#ifndef _I_IBEFOREEA_H_

#define _I_IBEFOREEA_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\update\EdgeAddition.h"
using namespace std;

class IBeforeEA:public IDynamicAlgorithm
{
public:
	virtual bool applyBeforeUpdate(EdgeAddition* ea)=0;
};

#endif