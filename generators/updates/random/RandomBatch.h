#ifndef _RANDOMBATCH_H_

#define _RANDOMBATCH_H_

#include <string>
#include <iostream>
#include <vector>
#include "..\BatchGenerator.h"
using namespace std;
class RandomBatch: public BatchGenerator
{
private:
	int na = 0;//node add
	int nr = 0;//node remove
	int ea = 0;//edge add
	int er = 0;//edge remove
	vector<BatchGenerator* >*bgs;
private:
	void init();
public:
	RandomBatch(int na,int nr,int ea,int er);
public:
	int getNa();
	int getNr();
	int getEa();
	int getEr();

public://实现父类方法
	Batch* generate(Graph* g);
	void reset();
	bool isFurtherBatchPossible(Graph* g);
	void show();
	

};

#endif
