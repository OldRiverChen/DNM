#ifndef _RANDOMGRAPH_H_

#define _RANDOMGRAPH_H_

#include <string>
#include <vector>
#include "..\..\graph\Graph.h"
#include "..\..\util\Parameter.h"
#include "..\..\util\ParameterList.h"
#include "..\..\util\parameters\IntParameter.h"
#include "..\..\graph\datastructures\GraphDataStructure.h"
#include "..\GraphGenerator.h"
class RandomGraph : public GraphGenerator
{

public:
	RandomGraph(GraphDataStructure* gds, int nodes, int edges);
	void reset();
public:
	 void show();
	 Graph* generate();
};


#endif
