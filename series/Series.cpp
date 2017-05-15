#include "Series.h"
#include "data\SeriesData.h"
#include "SeriesGeneration.h"
#include "..\util\Rand.h"

RandomSeedReset Series::defaultRandomSeedReset = Eachrun;
RandomSeedType Series::defaultRandomSeedType = Timestamp;
long Series::defaultSeed = 0;

Series::Series(GraphGenerator * gg, BatchGenerator * bg, vector<IMetric*>* metrics, string dir, string name)
{
	this->graphGenerator = gg;
	this->batchGenerator = bg;
	this->metrics = metrics;
	this->dir = dir;
	this->name = name;
}

SeriesData* Series::generate(int runs, int batches)
{
	return this->generate(runs, batches, true, true, true, 0);
}

SeriesData* Series::generate(int runs, int batches, bool compare, bool aggregate, bool write, long batchGenerationTime)
{
	return SeriesGeneration::generate(this,runs,batches,compare,aggregate,write,batchGenerationTime);
}
GraphGenerator* Series::getGraphGenerator()
{
	return this->graphGenerator;
}
BatchGenerator* Series::getBatchGenerator()
{
	return this->batchGenerator;
}
string Series::getDir()
{
	return this->dir;
}
string Series::getName()
{
	return this->name;
}
Graph* Series::getGraph()
{
	return this->graph;
}
void Series::setGraph(Graph* graph)
{
	this->graph = graph;
}
vector<IMetric*>* Series::getMetrics()
{
	return this->metrics;
}
RandomSeedType Series::getRandomSeedType()
{
	return this->randomSeedType;
}
void Series::setRandomSeedType(RandomSeedType randSeedType)
{
	this->randomSeedType = randSeedType;
}
RandomSeedReset Series::getRandomSeedReset()
{
	return this->randomSeedReset;
}
void Series::setRandomSeedReset(RandomSeedReset randSeedReset)
{
	this->randomSeedReset = randSeedReset;
}
long long Series::getSeed()
{
	return this->seed;
}
void Series::setSeed(long long seed)
{
	this->seed = seed;
}
string Series::RandomSeedTypeTOString(RandomSeedType randomSeedType)
{
	string rs("");
	switch (randomSeedType)
	{
	case Timestamp:
		rs = "timestamp";
		break;
	case Fixed:
		rs = "fixed";
		break;
	}
	return rs;
}

string Series::RandomSeedResetTypeTOString(RandomSeedReset randSeedReset)
{
	string rs("");
	switch (randSeedReset)
	{
	case Eachbatch:
		rs = "eachbatch";
		break;
	case Eachrun:
		rs = "eachrun";
		break;
	case Eachseries:
		rs = "eachseries";
		break;
	case Never:
		rs = "never";
		break;
	}
	return rs;
}

void Series::resetRand()
{
	if (this->randomSeedType == Timestamp)
		this->seed = LogSystemTime::_getTime();
	Rand::init(this->seed);
	Log::debug("resetting random seed to " + to_string(this->seed) + " ("
		+ RandomSeedResetTypeTOString(this->randomSeedReset) + "/" + RandomSeedTypeTOString(this->randomSeedType) + ")");
}