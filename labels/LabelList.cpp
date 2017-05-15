#include "LabelList.h"

LabelList::LabelList()
{
	this->mp = new map<string, Label*>();
}

LabelList::LabelList(int size)
{
	this->mp = new map<string, Label*>();
}

vector<string>* LabelList::getName()
{
	vector<string>* names = new vector<string>();//µü´úmap
	for (map<string, Label*>::iterator iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		names->push_back(iter->first);
	}
	return names;
}

vector<Label*>* LabelList::getList()
{
	vector<Label*>* list = new vector<Label*>();
	for (map<string, Label*>::iterator iter = this->mp->begin(); iter != this->mp->end(); iter++)
	{
		list->push_back(iter->second);
	}
	return list;
}

int LabelList::size()
{
	return mp->size();
}

Label* LabelList::get(string name, string type)
{
	string key = name + " ~~ " + type;
	return mp->at(key);
}

void LabelList::add(Label * item)
{
	string key = item->getName() + " ~~ " + item->getType();
	this->mp->insert(pair<string, Label*>(key, item));
}
