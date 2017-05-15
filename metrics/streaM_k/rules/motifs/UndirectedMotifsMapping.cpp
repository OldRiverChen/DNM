#include "UndirectedMotifsMapping.h"
const string UndirectedMotifsMapping::nodesPre = "nodes: ";
const string UndirectedMotifsMapping::maxKeyPre = "maxKey: ";
const string UndirectedMotifsMapping::motifsPre = "motifs: ";
const string UndirectedMotifsMapping::sep = " ";

int UndirectedMotifsMapping::getNodes()
{
	return this->nodes;
}

vector<int>* UndirectedMotifsMapping::getMapping()
{
	return this->mapping;
}

int UndirectedMotifsMapping::getMotifsCount()
{
	return this->motifs;
}

int UndirectedMotifsMapping::getAmsCount()
{
	int counter = 0;
	for (vector<int>::iterator iter = this->mapping->begin(); iter != this->mapping->end(); iter++)
	{
		int key = *iter;
		if (key > 0)
			counter++;
	}
	return counter;
}

int UndirectedMotifsMapping::getMotif(int key)
{

	return this->mapping->at(key);
}

vector<int>* UndirectedMotifsMapping::getRepresentatives()
{
	vector<int>* reps = new vector<int>(); 
	int m_value = this->mapping->at(this->mapping->size() - 1);
	reps->resize(m_value + 1);//Ïàµ±ÓÚnew int[mapping[mapping.length - 1] + 1];
	for (int i = 0; i < this->mapping->size(); i++)
	{
		if (reps->at(mapping->at[i]) == 0)
		{
			reps->at(mapping->at[i]) = i;
		}
	}
	return reps;
}

UndirectedMotifsMapping::UndirectedMotifsMapping(int nodes, int motifs, vector<int>* mapping)
{
	this->nodes = nodes;
	this->motifs = motifs;
	this->mapping = mapping;
}
