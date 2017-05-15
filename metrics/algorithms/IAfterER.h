#ifndef _I_IAFTERER_H_

#define _I_IAFTERER_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\update\EdgeRemoval.h"

using namespace std;

class IAfterER :public IDynamicAlgorithm
{
public:
	virtual bool applyAfterUpdate(EdgeRemoval* er)=0;
};

#endif