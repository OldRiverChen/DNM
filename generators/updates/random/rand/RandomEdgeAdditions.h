#ifndef _RANDOMEDGEADDITIONS_H_

#define _RANDOMEDGEADDITIONS_H_

#include <string>
#include <vector>
#include "..\..\BatchGenerator.h"
using namespace std;
class RandomEdgeAdditions: public BatchGenerator
{
private:
	int count;
public:
	RandomEdgeAdditions(int count);
public://ʵ�ָ���ķ���
	Batch* generate(Graph* g);
	bool isFurtherBatchPossible(Graph* g);
	void show();

};

#endif
