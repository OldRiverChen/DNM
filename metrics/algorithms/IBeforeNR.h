#ifndef _I_IBEFORENR_H_

#define _I_IBEFORENR_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\update\NodeRemoval.h"
using namespace std;

class IBeforeNR	:public IDynamicAlgorithm
{
public:
	virtual bool applyBeforeUpdate(NodeRemoval*nr)=0;
};

#endif