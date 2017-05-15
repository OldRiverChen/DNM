#ifndef _LABELLIST_H_

#define _LABELLIST_H_

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "Label.h"

using namespace std;
class LabelList
{
protected:
	map<string, Label*>* mp;
public:
	LabelList();
	LabelList(int size);//size√ª”√
	vector<string>* getName();
	vector<Label*>* getList();
	int size();
	Label* get(string name,string type);
	void add(Label* item);




};

#endif