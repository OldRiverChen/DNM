#ifndef _I_IAFTERNA_H_

#define _I_IAFTERNA_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\update\NodeAddition.h"

using namespace std;

class IAfterNA :public IDynamicAlgorithm
{
public:
	virtual bool applyAfterUpdate(NodeAddition* na)=0;
};

#endif