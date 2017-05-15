#ifndef _STREAM_K_H_

#define _STREAM_K_H_

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "..\..\graph\Graph.h"
#include "..\..\graph\edges\Edge.h"
#include "..\..\graph\nodes\Node.h"
#include "..\Metric.h"
#include "grouping\Grouping.h"
#include "..\algorithms\IDynamicAlgorithm.h"
#include "..\algorithms\IBeforeEA.h"
#include "..\algorithms\IAfterER.h"
#include "..\..\series\data\distr\BinnedIntDistr.h"
using namespace std;

class StreaM_k:public Metric,public IDynamicAlgorithm,public IBeforeEA,public IAfterER
{
protected:
	int nodes;
	Grouping* grouping;

	BinnedIntDistr* motifs;
};

#endif