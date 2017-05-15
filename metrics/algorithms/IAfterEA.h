#ifndef _I_IAFTEREA_H_

#define _I_IAFTEREA_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\update\EdgeAddition.h"

using namespace std;

class IAfterEA :public IDynamicAlgorithm
{
public:
	virtual bool applyAfterUpdate(EdgeAddition* ea)=0;
};

#endif