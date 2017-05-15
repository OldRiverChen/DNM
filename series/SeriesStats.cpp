#include "SeriesStats.h"

const string SeriesStats::nodes="nodes";
const string SeriesStats::edges="edges";


const string SeriesStats::nodesToAdd="nodesToAdd";
const string SeriesStats::addedNodes="addedNodes";
const string SeriesStats::nodesToRemove="nodesToRemove";
const string SeriesStats::removedNodes="removedNodes";

const string SeriesStats::edgesToAdd="edgesToAdd";
const string SeriesStats::addedEdges="addedEdges";
const string SeriesStats::edgesToRemove="edgesToRemove";
const string SeriesStats::removedEdges="removedEdges";

const string SeriesStats::deletedNodeAdditions="deletedNodeAdditions";
const string SeriesStats::deletedEdgeAdditions="deletedEdgeAdditions";
const string SeriesStats::deletedNodeRemovals="deletedNodeRemovals";
const string SeriesStats::deletedEdgeRemovals="deletedEdgeRemovals";

const string SeriesStats::randomSeed="randomSeed";

const string SeriesStats::memory="memory";

const string SeriesStats::totalRuntime="total";
const string SeriesStats::metricsRuntime="metrics";
const string SeriesStats::graphGenerationRuntime="graphGeneration";
const string SeriesStats::batchGenerationRuntime="batchGeneration";
const string SeriesStats::graphUpdateRuntime="graphUpdate";
const string SeriesStats::hotswapRuntime="hotswap";
const string SeriesStats::recommendationRuntime="recommendation";
const string SeriesStats::profilerRuntime="profiler";
const string SeriesStats::sumRuntime="sum";
const string SeriesStats::overheadRuntime="overhead";

const vector<string>* SeriesStats::statisticsToPlot = new vector<string>{SeriesStats::memory,SeriesStats::nodes,SeriesStats::edges};

const vector<string>* SeriesStats::generalRuntimesToPlot = new vector<string>{ SeriesStats::batchGenerationRuntime,SeriesStats::graphUpdateRuntime};

const vector<string>* SeriesStats::generalRuntimesOfCombinedPlot = new vector<string>{
	SeriesStats::totalRuntime,SeriesStats::metricsRuntime,SeriesStats::batchGenerationRuntime,
	SeriesStats::sumRuntime,SeriesStats::graphUpdateRuntime,SeriesStats::hotswapRuntime,SeriesStats::profilerRuntime,
	SeriesStats::overheadRuntime
};