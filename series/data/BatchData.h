#ifndef _BATCHDATA_H_

#define _BATCHDATA_H_

#include <string>
#include <iostream>
#include <map>
#include "lists\ValueList.h"
#include "lists\RunTimeList.h"
#include "lists\MetricDataList.h"
#include "..\..\labels\LabelList.h"
#include "..\..\generators\updates\batch\Batch.h"
#include "..\..\generators\updates\batch\BatchSanitizationStats.h"
#include "IBatch.h"
using namespace std;

class BatchData:public IBatch
{
public:
	long long timestamp;
	ValueList* stats;
	RunTimeList* generalRuntimes;
	RunTimeList* metricRuntimes;
	MetricDataList* metrics;
	LabelList* labels;

	Batch* batch;
	BatchSanitizationStats* sanitizationStats;
public:
	BatchData(long long timestamp, int sizeValues, int sizeGeneralRuntimes, int sizeMetricRuntimes, int sizeMetrics);
	BatchData(long long timestamp, ValueList* values, RunTimeList* generalRuntimes, RunTimeList* metricRuntimes, MetricDataList* metrics);
	BatchData(long long timestamp, ValueList* values, RunTimeList* generalRuntimes, RunTimeList* metricRuntimes, MetricDataList* metrics, LabelList* labels);
	BatchData(Batch* b, BatchSanitizationStats* sanitizationStats,int sizeValues, int sizeGeneralRuntimes, int sizeMetricRuntimes, int sizeMetrics);
public:
	long long getTimestamp();
	ValueList* getValues();
	RunTimeList* getGeneralRuntimes();
	RunTimeList* getMetricRuntimes();
	MetricDataList* getMetrics();
	LabelList* getLabels();
	Batch* getBatch();
	void releaseBatch();
	BatchSanitizationStats* getSanitizationStats();
	/** Writes the batch to the specified location. **/
	void write(string dir);
	/**
	* Writes the batch to the specified location either as a plain batch
	* directory or as a zip file.
	*
	* Example: Input-Dir: "data/scenario.1/series/run.0/batch.0/":
	*
	* No-Zip will write the batch at "data/scenario.1/series/run.0/batch.0/".
	*
	* Zipped-Batch will write the zipped batch
	* "data/scenario.1/series/run.0/batch.0.zip"
	*
	* Zipped-Run will write the batch into the run-zip as
	* "data/scenario.1/series/run.0.zip/batch.0/".
	*
	**/
	void writeIntelligent(string dir);

	/** Returns a clone of the batch-data object. **/
	BatchData* cloneStructure();
};

#endif