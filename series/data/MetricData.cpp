#include "MetricData.h"
#include "..\..\io\filesystem\Files.h"

MetricData::MetricData(string name)
{
	this->name = name;
	this->values = new ValueList();
	this->distributions = new DistributionList<int, vector<long>>();
	this->nodevalues = new NodeValueListList();
	this->nodenodevalues = new NodeNodeValueListList();
}
MetricData::MetricData(string name, string type, int sizeValues, int sizeDistributions, int sizeNodeValueList)
{
	this->name = name;
	this->type = type;
	this->values = new ValueList(sizeValues);
	this->distributions = new DistributionList<int,vector<long>>(sizeDistributions);
	this->nodevalues = new NodeValueListList(sizeNodeValueList);
	this->nodenodevalues = new NodeNodeValueListList();

}
MetricData::MetricData(string name, string type, vector<Value*>* values, vector<Distr<int, vector<long>>*>* distributions,
	vector<NodeValueList*>* nodevalues, vector<NodeNodeValueList*>* nodenodevalues)
{
	new(this)MetricData(name, type, values->size(), distributions->size(), nodevalues->size());
	for (vector<Value*>::iterator iter = values->begin(); iter != values->end(); iter++)
	{
		Value* v = *iter;
		this->values->add(v->getName(), v);
	}
	for (vector<Distr<int, vector<long>>*>::iterator iter = distributions->begin(); iter != distributions->end(); iter++)
	{
		Distr<int, vector<long>>* d = *iter;
		this->distributions->add(d->getName(), d);
	}
	for (vector<NodeValueList*>::iterator iter = nodevalues->begin(); iter != nodevalues->end(); iter++)
	{
		NodeValueList* n = *iter;
		this->nodevalues->add(n->getName(), n);
	}
	for (vector<NodeNodeValueList*>::iterator iter = nodenodevalues->begin(); iter != nodenodevalues->end(); iter++)
	{
		NodeNodeValueList* nnvl = *iter;
		this->nodenodevalues->add(nnvl->getName(), nnvl);
	}

}
MetricData::MetricData(string name, string type, ValueList*values, DistributionList<int, vector<long>>* distributions,
	NodeValueListList* nodevalues, NodeNodeValueListList* nodenodevalues)
{
	this->name = name;
	this->type = type;
	this->values = values;
	this->distributions = distributions;
	this->nodevalues = nodevalues;
	this->nodenodevalues = nodenodevalues;
}

string MetricData::getName()
{
	return name;
}
string MetricData::getType()
{
	return type;
}
ValueList* MetricData::getValues()
{
	return this->values;
}
DistributionList<int, vector<long>>* MetricData::getDistributions()
{
	return this->distributions;
}
NodeValueListList* MetricData::getNodeValues()
{
	return this->nodevalues;
}
NodeNodeValueListList*MetricData::getNodeNodeValues()
{
	return this->nodenodevalues;
}

void MetricData::write(string dir)
{
	bool GENERATION_WRITE_VALUES = true;
	if (GENERATION_WRITE_VALUES)
	{
		if (this->values->size() > 0) {
			string METRIC_DATA_VALUES = "values";
			string values_Filename = Files::getValuesFilename(METRIC_DATA_VALUES);
			this->values->write(dir, values_Filename);
		}
	}
	bool GENERATION_WRITE_DISTRIBUTONS = true;
	if (GENERATION_WRITE_DISTRIBUTONS)
	{
		this->distributions->write(dir);
	}
	bool GENERATION_WRITE_NVL = true;
	if (GENERATION_WRITE_NVL)
	{
		this->nodevalues->write(dir);
	}
	bool GENERATION_WRITE_NNVL = true;
	if (GENERATION_WRITE_NNVL)
	{
		this->nodenodevalues->write(dir);
	}
}