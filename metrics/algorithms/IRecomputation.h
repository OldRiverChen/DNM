#ifndef _I_IRECOMPUTATION_H_

#define _I_IRECOMPUTATION_H_
//һ���ӿ�
#include <string>
#include <iostream>
#include "..\IMetric.h"
using namespace std;

class IRecomputation :public IMetric
{
public:
	virtual bool recompute()=0;
};

#endif