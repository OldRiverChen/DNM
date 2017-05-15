#ifndef _ALGORITHMS_H_

#define _ALGORITHMS_H_

#include <string>
#include <iostream>
#include "..\Metric.h"
#include "IRecomputation.h"
#include "IDynamicAlgorithm.h"
#include "IBeforeBatch.h"
#include "IBeforeNA.h"
#include "IBeforeNR.h"
#include "IBeforeEA.h"
#include "IBeforeER.h"

#include "IAfterNA.h"
#include "IAfterNR.h"
#include "IAfterEA.h"
#include "IAfterER.h"
#include "IAfterBatch.h"
using namespace std;

class Algorithms
{
public:
	vector<IMetric*>* metrics;

	vector<IRecomputation*>* recomputation;
	vector<IDynamicAlgorithm*>* dynamicAlgorithm;

	vector<IBeforeBatch*>* beforeBatch;

	vector<IBeforeNA*>* beforeUpdateNA;
	vector<IBeforeNR*>* beforeUpdateNR;
	vector<IBeforeEA*>* beforeUpdateEA;
	vector<IBeforeER*>* beforeUpdateER;

	vector<IAfterNA*>* afterUpdateNA;
	vector<IAfterNR*>* afterUpdateNR;
	vector<IAfterEA*>* afterUpdateEA;
	vector<IAfterER*>* afterUpdateER;

	vector<IAfterBatch*>* afterBatch;


public:
	Algorithms(vector<IMetric*>* metrics);
private:
	vector<IMetric*>* get(string className);
	
};

#endif