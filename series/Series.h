#ifndef _SERIES_H_

#define _SERIES_H_

#include <string>
#include <iostream>
#include "..\graph\Graph.h"
#include "..\generators\GraphGenerator.h"
#include "..\metrics\Metric.h"
#include "..\generators\updates\BatchGenerator.h"
class SeriesData;
class SeriesGeneration;
using namespace std;

enum RandomSeedType {
	Timestamp, Fixed
};

enum RandomSeedReset {
	Eachbatch, Eachrun, Eachseries,Never
};
class Series
{
private:
	GraphGenerator* graphGenerator;
	BatchGenerator* batchGenerator;
	vector<IMetric*>* metrics;
	string dir;
	Graph* graph;
	string name;
	RandomSeedType randomSeedType = defaultRandomSeedType;
	RandomSeedReset randomSeedReset = defaultRandomSeedReset;
	long long seed = defaultSeed;

public:
	Series(GraphGenerator* gg, BatchGenerator* bg, vector<IMetric*>* metrics, string dir, string name);
public:
	SeriesData* generate(int runs, int batches);
	SeriesData* generate(int runs, int batches, bool compare, bool aggregate, bool write, long batchGenerationTime);
	GraphGenerator* getGraphGenerator();
	BatchGenerator* getBatchGenerator();
	string getDir();
	string getName();
	Graph* getGraph();
	void setGraph(Graph* graph);
	vector<IMetric*>* getMetrics();
	RandomSeedType getRandomSeedType();
	void setRandomSeedType(RandomSeedType randSeedType);
	RandomSeedReset getRandomSeedReset();
	void setRandomSeedReset(RandomSeedReset randSeedReset);
	long long getSeed();
	void setSeed(long long seed);
	void resetRand();
public:
	static RandomSeedType defaultRandomSeedType;
	static RandomSeedReset defaultRandomSeedReset;
	static long defaultSeed;
	static string RandomSeedTypeTOString(RandomSeedType randomSeedType);
	static string RandomSeedResetTypeTOString(RandomSeedReset randSeedReset);
	
};

#endif