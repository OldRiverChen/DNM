#include "BatchData.h"
#include "..\..\util\Log.h"
#include "..\..\io\filesystem\Files.h"
BatchData::BatchData(long long timestamp, int sizeValues, int sizeGeneralRuntimes, int sizeMetricRuntimes, int sizeMetrics)
{
	this->timestamp = timestamp;
	this->stats = new ValueList(sizeValues);
	this->generalRuntimes = new RunTimeList(sizeGeneralRuntimes);
	this->metricRuntimes = new RunTimeList(sizeMetricRuntimes);
	this->metrics = new MetricDataList(sizeMetrics);
	this->labels = new LabelList();
}
BatchData::BatchData(long long timestamp, ValueList* values, RunTimeList* generalRuntimes, RunTimeList* metricRuntimes, MetricDataList* metrics, LabelList* labels)
{
	this->timestamp = timestamp;
	this->stats = values;
	this->generalRuntimes = generalRuntimes;
	this->metricRuntimes = metricRuntimes;
	this->metrics = metrics;
	this->labels = labels;
}
BatchData::BatchData(long long timestamp, ValueList* values, RunTimeList* generalRuntimes, RunTimeList* metricRuntimes, MetricDataList* metrics)
{
	new(this)BatchData(timestamp, values, generalRuntimes, metricRuntimes, metrics,new LabelList());
}
BatchData::BatchData(Batch* b, BatchSanitizationStats* sanitizationStats, int sizeValues, int sizeGeneralRuntimes, int sizeMetricRuntimes, int sizeMetrics)
{
	new (this)BatchData(b->getTo(), sizeValues, sizeGeneralRuntimes, sizeMetricRuntimes, sizeMetrics);
	this->batch = b;
	this->sanitizationStats = sanitizationStats;
}
long long BatchData::getTimestamp()
{
	return this->timestamp;
}
ValueList* BatchData::getValues()
{
	return this->stats;
}
RunTimeList* BatchData::getGeneralRuntimes()
{
	return this->generalRuntimes;
}
RunTimeList* BatchData::getMetricRuntimes()
{
	return this->metricRuntimes;
}
MetricDataList* BatchData::getMetrics()
{
	return this->metrics;
}
LabelList* BatchData::getLabels()
{
	return this->labels;
}
Batch* BatchData::getBatch()
{
	return this->batch;
}
void BatchData::releaseBatch()
{
	if (this->batch != nullptr)
	{
		delete batch;
		batch = nullptr;
	}
}
BatchSanitizationStats* BatchData::getSanitizationStats()
{
	return this->sanitizationStats;
}
/** Writes the batch to the specified location. **/
void BatchData::write(string dir)
{
	Log::debug("writing BatchData for " + to_string(this->timestamp) + " to " + dir);

	string BATCH_STATS = "___stats";
	string stats_FileName = Files::getValuesFilename(BATCH_STATS);
	this->stats->write(dir, stats_FileName);

	string BATCH_GENERAL_RUNTIMES = "___general";
	string generalRuntimes_FileName = Files::getRuntimesFilename(BATCH_GENERAL_RUNTIMES);
	this->generalRuntimes->write(dir, generalRuntimes_FileName);

	string BATCH_METRIC_RUNTIMES = "___metric";
	string metricRuntimes_FileName = Files::getRuntimesFilename(BATCH_METRIC_RUNTIMES);
	this->metricRuntimes->write(dir, metricRuntimes_FileName);

	/*string BATCH_LABELS = "___labels";
	string labels_FileName = Files::getLabelsFilename(BATCH_LABELS);
	this->labels->write(dir, labels_FileName);*/
	this->metrics->write(dir);

}


void BatchData::writeIntelligent(string dir)
{
	string temDir = "";
	// write normal batch
	this->write(dir);
}

BatchData* BatchData::cloneStructure()
{
	ValueList* values = new ValueList(this->stats->size());
	for (map<string, Value*>::iterator iter = this->stats->mp->begin(); iter != this->stats->mp->end(); iter++)
	{
		string name = iter->second->getName();
		values->add(name, new Value(name, 0.0));
	}

	RunTimeList* generalRuntimes = new RunTimeList(this->generalRuntimes->size());
	for (map<string, RunTime*>::iterator iter = this->generalRuntimes->mp->begin(); iter != this->generalRuntimes->mp->end(); iter++)
	{
		string name = iter->second->getName();
		generalRuntimes->add(name, new RunTime(name, 0.0));
	}

	RunTimeList* metricRuntimes = new RunTimeList(this->metricRuntimes->size());
	for (map<string, RunTime*>::iterator iter = this->metricRuntimes->mp->begin(); iter != this->metricRuntimes->mp->end(); iter++)
	{
		string name = iter->second->getName();
		metricRuntimes->add(name, new RunTime(name, 0.0));
	}

	MetricDataList* metrics = new MetricDataList(this->metrics->size());
	for (map<string, MetricData*>::iterator iter = this->metrics->mp->begin(); iter != this->metrics->mp->end(); iter++)
	{
		string MetricData_Name = iter->first;
		MetricData* m = iter->second;

		ValueList* metricValues = new ValueList(m->getValues()->size());
		for (map<string, Value*>::iterator iter = m->getValues()->mp->begin(); iter != m->getValues()->mp->end(); iter++)
		{
			string name = iter->second->getName();
			metricValues->add(name,new Value(name,0.0));
		}

		DistributionList<int, vector<long>>* distributions = new DistributionList<int, vector<long>>(m->getDistributions()->size());
		for (map<string, Distr<int, vector<long>>*>::iterator iter = m->getDistributions()->mp->begin(); iter != m->getDistributions()->mp->end(); iter++)
		{
			string name = iter->second->getName();
			distributions->add(name,new BinnedIntDistr(name));
		}

		NodeValueListList* nvls = new NodeValueListList(m->getNodeValues()->size());
		for (map<string, NodeValueList*>::iterator iter = m->getNodeValues()->mp->begin(); iter != m->getNodeValues()->mp->end(); iter++)
		{
			string name = iter->second->getName();
			nvls->add(name,new NodeValueList(name,0));
		}

		NodeNodeValueListList* nnvls = new NodeNodeValueListList(m->getNodeNodeValues()->size());
		for (map<string, NodeNodeValueList*>::iterator iter = m->getNodeNodeValues()->mp->begin(); iter != m->getNodeNodeValues()->mp->end(); iter++)
		{
			string name = iter->second->getName();
			nnvls->add(name, new NodeNodeValueList(name, 0));
		}

		metrics->add(m->getName(),new MetricData(m->getName(),m->getType(), metricValues, distributions, nvls, nnvls));
	}
	return new BatchData(this->timestamp,values, generalRuntimes, metricRuntimes, metrics);
}
