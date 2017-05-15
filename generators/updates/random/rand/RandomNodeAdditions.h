#ifndef _RANDOMNODEADDITIONS_H_

#define _RANDOMNODEADDITIONS_H_

#include <string>
#include <vector>
#include "..\..\BatchGenerator.h"
using namespace std;
class RandomNodeAdditions: public BatchGenerator
{
private:
	int count;
public:
	RandomNodeAdditions(int count);
public://ʵ�ָ��෽��
	Batch* generate(Graph* g);
	void reset();
	bool isFurtherBatchPossible(Graph* g);
	void show();

};

#endif
