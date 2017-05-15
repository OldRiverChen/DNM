#include "SeriesData.h"
#include "..\..\io\filesystem\Dir.h"
string SeriesData::getDir()
{
	return this->dir;
}
string SeriesData::getName()
{
	return this->name;
}
vector<RunData*>* SeriesData::getRuns()
{
	return this->runs;
}
AggregatedSeries* SeriesData::getAggregation()
{
	return this->aggregation;
}
SeriesData* SeriesData::read(string dir, string name, bool readAggregation, bool readValues)
{
	vector<string>* runs = Dir::getRuns(dir);

	vector<RunData*>* runList = new vector<RunData*>();//³¤¶ÈÎªruns.size();
	runList->reserve(runs->size());

	return NULL;
}