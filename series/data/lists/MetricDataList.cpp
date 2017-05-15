#include "MetricDataList.h"
#include "..\..\..\io\filesystem\Dir.h"

MetricDataList::MetricDataList():List()
{
}

MetricDataList::MetricDataList(int size):List(size)
{
}

void MetricDataList::write(string dir)
{
	for (map<string, MetricData*>::iterator iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		string name = iter->first;
		MetricData* metricData = iter->second;
		string suffix("");
		if (metricData->getType().compare("exact") == 0)
		{
			string SUFFIX_METRIC_EXACT = ".exact";
			suffix = SUFFIX_METRIC_EXACT;
		}
		string metricData_Name = metricData->getName();
		string metricData_Dir = Dir::getMetricDataDir(dir, metricData_Name + suffix);
		metricData->write(metricData_Dir);
	}
}
