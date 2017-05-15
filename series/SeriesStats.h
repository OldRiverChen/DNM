#ifndef _SERIESSTATS_H_

#define _SERIESSTATS_H_
#include <string>
#include <iostream> 
#include <vector>
using namespace std;
class SeriesStats
{
public:
	static const string nodes;
	static const string edges;


	static const string nodesToAdd;
	static const string addedNodes;
	static const string nodesToRemove;
	static const string removedNodes;

	static const string edgesToAdd;
	static const string addedEdges;
	static const string edgesToRemove;
	static const string removedEdges;

	static const string deletedNodeAdditions;
	static const string deletedEdgeAdditions;
	static const string deletedNodeRemovals;
	static const string deletedEdgeRemovals;

	static const string randomSeed;

	static const string memory;

	static const string totalRuntime;
	static const string metricsRuntime;
	static const string graphGenerationRuntime;
	static const string batchGenerationRuntime;
	static const string graphUpdateRuntime;
	static const string hotswapRuntime;
	static const string recommendationRuntime;
	static const string profilerRuntime;
	static const string sumRuntime;
	static const string overheadRuntime;

	static const vector<string>* statisticsToPlot;

	static const vector<string>* generalRuntimesToPlot;

	static const vector<string>* generalRuntimesOfCombinedPlot;


};

#endif