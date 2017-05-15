#include "RunData.h"
RunData::RunData(int run, vector<BatchData*>* batches)
{
	this->run = run;
	this->batches = new BatchDataList(batches->size());
	for (vector<BatchData*>::iterator iter = batches->begin(); iter != batches->end(); iter++)
	{
		BatchData* batch = *iter;
		this->batches->add(batch);
	}
}


int RunData::getRun()
{
	return this->run;
}

BatchDataList* RunData::getBatches()
{
	return this->batches;
}