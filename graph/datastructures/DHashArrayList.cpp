#include "DHashArrayList.h"
#include <algorithm> 
#include <functional>
#include "..\..\util\Util.h"

DHashArrayList::DHashArrayList()
{
	lists = new vector<IElement*>();
	sets = new set<IElement*,Edge_compare>();
	
	maxNodeIndex = -1;
}

void DHashArrayList::init(int initialSize)
{
	if (initialSize < 1)
		initialSize = 1;
	lists = new vector<IElement*>();
	sets = new set<IElement*, Edge_compare>();
	lists->reserve(initialSize);//分配capacity,而不是改变size()值

	maxNodeIndex = -1;
}
set<IElement*>::iterator DHashArrayList::findEdge_set(Edge * e)
{
	set<IElement*, Edge_compare>::iterator it;
	it = this->sets->find(e);
	return it;
}
vector<IElement*>::iterator DHashArrayList::findEdge_vector(Edge * e)
{
	vector<IElement*>::iterator it = find_if(this->lists->begin(), this->lists->end(), bind2nd(Edge_find(), e));
	return it;
}
//IDataStructure
void DHashArrayList::reinitializeWithSize(int size)
{
}

bool DHashArrayList::add(IElement * element)
{
	return false;
}

bool DHashArrayList::contains(IElement * element)
{
	return false;
}

bool DHashArrayList::remove(IElement * element)
{
	return false;
}

int DHashArrayList::size()
{
	return lists->size();
}



//INodeListDatastructure
bool DHashArrayList::add(Node * element)
{
	return false;
}
bool DHashArrayList::contains(Node * element)
{
	return false;
}

bool DHashArrayList::remove(Node * element)
{
	return false;
}
int DHashArrayList::getMaxNodeIndex()
{
	return 0;
}

Node * DHashArrayList::get(int index)
{
	return NULL;
}



//IEdgeListDatastructure
bool DHashArrayList::add(Edge * element)
{
	if (!instanceof<Edge>(element))
		return false;
	if (this->contains(element))
		return false;
	this->sets->insert(element);
	this->lists->push_back(element);
	return true;
}
bool DHashArrayList::contains(Edge * element)
{
	//set<IElement*, Edge_compare>::iterator it = this->findEdge(element);
	vector<IElement*>::iterator it = this->findEdge_vector(element);
	if(it!=this->lists->end())
		return true;
	else return false;
}

bool DHashArrayList::remove(Edge * element)
{
	if (!instanceof<Edge>(element))
		return false;
	vector<IElement*>::iterator it = this->findEdge_vector(element);//无需再次调用contains来判断是非包含element，不然会调用两次findEdge_vector
	if (it == this->lists->end())//表示无该边
		return false;
	this->sets->erase(element);
	this->lists->erase(it);
	return true;
}
Edge * DHashArrayList::get(int n1, int n2)
{
	for (vector<IElement*>::iterator iter = this->lists->begin(); iter != this->lists->end(); iter++)
	{
		IElement* eU = *iter;
		if (eU == nullptr)
			continue;
		Edge* e = (Edge*)eU;
		if (e->getN1Index() == n1 && e->getN2Index() == n2)
			return e;
	}
	return nullptr;
}

Edge * DHashArrayList::get(Edge * element)
{
	
	return get(element->getN1Index(),element->getN2Index());
}

IElement * DHashArrayList::getRandom()
{
	if (this->size() <= 0)
		return NULL;
	int index = Rand::nextInt(this->size());
	while (this->lists->at(index) == NULL)
	{
		index = Rand::nextInt(this->size());
	}
	return this->lists->at(index);
}
