#ifndef _I_IBEFOREBATCH_H_

#define _I_IBEFOREBATCH_H_

#include <string>
#include <iostream>
#include "IDynamicAlgorithm.h"
#include "..\..\generators\updates\batch\Batch.h"
using namespace std;

class IBeforeBatch :public IDynamicAlgorithm
{
public:
	virtual bool applyBeforeBatch(Batch* b)=0;
};

#endif