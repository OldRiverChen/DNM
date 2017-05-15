#include "BinnedIntDistr.h"

BinnedIntDistr::BinnedIntDistr(string name):BinnedDistr(name,(*new int(1)))
{

}

BinnedIntDistr::BinnedIntDistr(string name, int& binSize): BinnedDistr(name, binSize)
{
}

int BinnedIntDistr::getIndex(int & value)
{
	int r = (value) % (this->binSize);

	return ((value - r) / (this->binSize) + (r == 0 ? 0 : 1));
}

vector<int>* BinnedIntDistr::getBin(int& index)
{
	vector<int>* vi = new vector<int>();
	if (index = 0)
	{
		
		vi->push_back(0);
		vi->push_back(0);

	}
	else 
	{
		vi->push_back((index - 1) * (binSize));
		vi->push_back(index * (binSize));
	}
	return vi;;
}

string BinnedIntDistr::getDistrType()
{

	return this->getDistrTypeString(BINNED_INT);
}

double BinnedIntDistr::computeAverage_()
{
	return this->computeAverage() * (this->binSize);
}