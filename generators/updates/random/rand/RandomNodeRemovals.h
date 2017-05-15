#ifndef _RANDOMNODEREMOVALS_H_

#define _RANDOMNODEREMOVALS_H_

#include <string>
#include <vector>
#include "..\..\BatchGenerator.h"
using namespace std;
class RandomNodeRemovals: public BatchGenerator
{
private:
	int count;
public:
	RandomNodeRemovals(int count);
public://ʵ�ָ��෽��
	Batch* generate(Graph* g);
	void reset();
	bool isFurtherBatchPossible(Graph* g);
	void show();

};

#endif
