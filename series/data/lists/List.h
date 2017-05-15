#ifndef _A_LIST_

#define _A_LIST_

#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<class T>
class List
{
public:
	map<string, T*> *mp;
public:
	List();
	List(int size);
public:
	vector<string>* getName();
	vector<T*>* getList();
	T* get(string name);
	void add(string name,T* item);
	int size();

};





template<class T>
List<T>::List()
{
	mp = new map<string, T*>();
}

template<class T>
List<T>::List(int size)//其实无意义，map不预分配内存
{
	mp = new map<string, T*>();
}

template<class T>
vector<string>* List<T>::getName()
{
	vector<string>* names = new vector<string>();//迭代map
	for (auto iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		names->push_back(iter->first);
	}

	return names;
}

template<class T>
vector<T*>* List<T>::getList()
{
	vector<T*>* list = new vector<T*>();
	for (auto iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		list->push_back(iter->second);
	}
	return list;
}

template<class T>
T * List<T>::get(string name)
{

	return this->mp->at(name);
}

template<class T>
void List<T>::add(string name,T * item)
{
	this->mp->insert(pair<string, T*>(name, item));
}

template<class T>
int List<T>::size()
{
	return this->mp->size();
}

#endif