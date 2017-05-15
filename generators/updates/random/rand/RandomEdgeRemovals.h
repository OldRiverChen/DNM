#ifndef _RANDOMEDGEREMOVALS_H_

#define _RANDOMEDGEREMOVALS_H_

#include <string>
#include <vector>
#include "..\..\BatchGenerator.h"
using namespace std;
class RandomEdgeRemovals: public BatchGenerator
{
private:
	int count;
public:
	RandomEdgeRemovals(int count);
public://实现父类方法
	Batch* generate(Graph * g);
	void reset();
	bool isFurtherBatchPossible(Graph* g);
	void show();

};

#endif
