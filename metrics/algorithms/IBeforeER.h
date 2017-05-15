#ifndef _I_IBEFOREER_H_

#define _I_IBEFOREER_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\update\EdgeRemoval.h"
using namespace std;

class IBeforeER:public IDynamicAlgorithm
{
public:
	virtual bool applyBeforeUpdate(EdgeRemoval* er)=0;
};

#endif