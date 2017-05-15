#ifndef _I_IBEFORENA_H_

#define _I_IBEFORENA_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\update\NodeAddition.h"
using namespace std;

class IBeforeNA :public IDynamicAlgorithm
{
public:
	virtual bool applyBeforeUpdate(NodeAddition* na)=0;
};

#endif