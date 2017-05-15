#ifndef _I_IAFTERNR_H_

#define _I_IAFTERNR_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\update\NodeRemoval.h"

using namespace std;

class IAfterNR :public IDynamicAlgorithm
{
public:
	virtual bool applyAfterUpdate(NodeRemoval* nr)=0;
};

#endif