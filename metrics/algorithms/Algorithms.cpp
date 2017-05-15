#include "Algorithms.h"
#include "..\..\util\Util.h"

Algorithms::Algorithms(vector<IMetric*>* metrics)
{
	this->metrics = metrics;

	this->recomputation = new vector<IRecomputation*>();
	this->dynamicAlgorithm = new vector<IDynamicAlgorithm*>();

	this->beforeBatch = new vector<IBeforeBatch*>();
	this->beforeUpdateNA = new vector<IBeforeNA*>();
	this->beforeUpdateNR = new vector<IBeforeNR*>();
	this->beforeUpdateEA = new vector<IBeforeEA*>();
	this->beforeUpdateER = new vector<IBeforeER*>();

	this->afterUpdateNA = new vector<IAfterNA*>();
	this->afterUpdateNR = new vector<IAfterNR*>();
	this->afterUpdateEA = new vector<IAfterEA*>();
	this->afterUpdateER = new vector<IAfterER*>();

	this->afterBatch = new vector<IAfterBatch*>();
	for (vector<IMetric*>::iterator iter = this->metrics->begin(); iter != this->metrics->end(); iter++)//为每个metric指定,指定其更新类型
	{
		IMetric* im = *iter;
		string trueInstanceName = im->getTrueInstanceName();
		if (trueInstanceName.compare("DegreeDistributionR") == 0)
		{
			this->recomputation->push_back((IRecomputation*)im);
		}
		else if (trueInstanceName.compare("UndirectedClusteringCoefficientU") == 0)
		{
			this->dynamicAlgorithm->push_back((IDynamicAlgorithm*)im);
			this->beforeUpdateNA->push_back((IBeforeNA*)im);
			this->beforeUpdateNR->push_back((IBeforeNR*)im);
			this->beforeUpdateEA->push_back((IBeforeEA*)im);
			this->afterUpdateER->push_back((IAfterER*)im);
		}
	}

}

