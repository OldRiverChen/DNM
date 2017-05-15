#ifndef _A_BATCHGENERATOR_H_

#define _A_BATCHGENERATOR_H_

//一个抽象类
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include "..\..\util\ParameterList.h"
#include "..\..\graph\Graph.h"
#include "..\..\util\BigInteger.h"
#include "batch\Batch.h"
using namespace std;
class BatchGenerator: public ParameterList
{

public:
	BatchGenerator(string name, vector<Parameter*> *parameters):ParameterList(name, parameters)
	{
	}
public:
	virtual void show() 
	{

	}
	virtual Batch* generate(Graph* g)
	{
		return NULL;
	}
	virtual void reset()
	{

	}
	virtual bool isFurtherBatchPossible(Graph* g)
	{
		return false;
	}
};

#endif
