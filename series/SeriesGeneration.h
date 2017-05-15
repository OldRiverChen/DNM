#ifndef _SERIESGENERATION_H_

#define _SERIESGENERATION_H_

#include <string>
#include <iostream>
#include "..\generators\GraphGenerator.h"
#include "..\metrics\Metric.h"
#include "..\generators\updates\BatchGenerator.h"
#include "data\RunData.h"
#include "..\metrics\algorithms\Algorithms.h"
#include "..\generators\updates\batch\Batch.h"

class SeriesData;
class Series;
using namespace std;

class SeriesGeneration
{
private:
	static BatchData* computeInitialData(Series *series, Algorithms* algorithms);
	static BatchData* computeInitialMetrics(Series *series, BatchData* initialData, Algorithms* algorithms);
	static bool compareMetrics(Series* series);
	static BatchData* computeNextBatch(Series *series, Algorithms* algorithms);
	static int applyNRs(Series* series, Algorithms* algorithms, vector<NodeRemoval*>* updates);
	static int applyERs(Series* series, Algorithms* algorithms, vector<EdgeRemoval*>* updates);
	static int applyNAs(Series* series, Algorithms* algorithms, vector<NodeAddition*>* updates);
	static int applyEAs(Series* series, Algorithms* algorithms, vector<EdgeAddition*>* updates);
public:
	/**
	* Generates a SeriesData object for a given series.
	*
	* @param series
	*            Series for which the SeriesData object will be generated
	* @param runs
	*            Amount of runs to be generated
	* @param batches
	*            Amount of badges to be generated
	* @param compare
	*            Flag that decides whether metrics will be automatically
	*            compared or not
	* @param aggregate
	*            Flag that decides whether data will be aggregated or not
	* @param write
	*            Flag that decides whether data will be written on the
	*            filesystem or not
	* @param batchGenerationTime
	*            Long variable representing the artificial generation-time for
	*            each batch. Used to simulate a live system.
	* @return RunDataList object containing the generated runs
	*/
	static SeriesData* generate(Series* series, int runs, int batches, bool compare, bool aggregate, bool write, long batchGenerationTime);
	/**
	* Generates one run of a given series
	*
	* @param series
	*            Series for which the runs will be generated
	* @param run
	*            Index of the generated run
	* @param batches
	*            Amount of batches that will be generated
	* @param compare
	*            Flag that decides whether metrics will be automatically
	*            compared or not
	* @param write
	*            Flag that decides whether data will be written on the
	*            filesystem or not
	* @param batchGenerationTime
	*            Long variable representing the artificial generation-time for
	*            each batch. Used to simulate a live system.
	* @return RunData object representing the generated run
	*/
	static RunData* generateRun(Series* series, int run, int batches, bool compare, bool write, long batchGenerationTime);

	static BatchData* generateInitialData(Series* series, Algorithms* algorithms);

	static BatchData* generateNextBatch(Series* series,Algorithms* algorithms);

};



#endif