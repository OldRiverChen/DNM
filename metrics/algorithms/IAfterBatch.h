#ifndef _I_IAFTERBATCH_H_

#define _I_IAFTERBATCH_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\batch\Batch.h"
using namespace std;

class IAfterBatch :public IDynamicAlgorithm
{
public:
	virtual bool applyAfterBatch(Batch* b)=0;
};

#endif