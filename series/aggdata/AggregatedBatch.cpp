#include "AggregatedBatch.h"
#include "AggregatedValueList.h"
#include "AggregatedRunTimeList.h"
#include "AggregatedMetricList.h"

AggregatedBatch::AggregatedBatch(long long timestamp)
{
	this->timestamp = timestamp;
	this->stats = new AggregatedValueList();
	this->generalRuntimes = new AggregatedRunTimeList();
	this->metricRuntimes = new AggregatedRunTimeList();
	this->metrics = new AggregatedMetricList();
}

long long AggregatedBatch::getTimestamp()
{
	return this->timestamp;
}
