#ifndef _DISTRIBUTIONLIST_H_

#define _DISTRIBUTIONLIST_H_

#include <string>
#include <iostream>
#include "SortedList.h"
#include "List.h"
#include "..\distr\Distr.h"
#include "..\..\..\io\filesystem\Files.h"
#include "..\distr\BinnedIntDistr.h"
using namespace std;
template<class T, class V>
class DistributionList :public List<Distr<T,V>>
{
public:
	DistributionList();
	DistributionList(int size);
public:
	void write(string dir);
	DistributionList* read(string dir, bool readValues);
};


#endif

template<class T, class V>
DistributionList<T, V>::DistributionList():List()
{
}

template<class T, class V>
DistributionList<T, V>::DistributionList(int size) : List(size)
{
}

template<class T, class V>
void DistributionList<T, V>::write(string dir)
{
	for (map<string, Distr<T, V>*>::iterator iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		string name = iter->first;
		Distr<T, V>* d = iter->second;
		string distrType = d->getDistrType();
		string distrName = d->getName();
		string filename = Files::getDistributionFilename(distrName, distrType);
		if (distrType.compare("BINNED_INT") == 0) {
			((BinnedIntDistr*)d)->write(dir,filename);
		}
	}
}
template<class T, class V>
DistributionList<T,V>* DistributionList<T, V>::read(string dir, bool readValues)
{
	DistributionList<T,V>* list = NULL;
	return list;
}