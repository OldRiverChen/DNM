#ifndef _A_SORTEDLIST_

#define _A_SORTEDLIST_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class SortedList
{
public:
	vector<T*> *list;
public:
	SortedList();
	SortedList(int size);
public:
	vector<T*>* getList();
	T* get(int index);
	void add(T* item);
	int size();
	virtual void write(string dir);

};

template<class T>
SortedList<T>::SortedList()
{
	this->list = new vector<T*>();
}

template<class T>
SortedList<T>::SortedList(int size)
{
	this->list = new vector<T*>();
	this->list->reserve(size);//分配capacity，而不是改变size
}

template<class T>
vector<T*>* SortedList<T>::getList()
{
	return this->list;
}

template<class T>
T * SortedList<T>::get(int index)
{
	return this->list->at(index);
}

template<class T>
void SortedList<T>::add(T * item)
{
	this->list->push_back(item);
}

template<class T>
int SortedList<T>::size()
{
	return this->list->size();
}

template<class T>
void SortedList<T>::write(string dir)
{

}


#endif

