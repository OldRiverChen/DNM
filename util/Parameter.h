#ifndef _A_PARAMEMTER_H_

#define _A_PARAMEMTER_H_


//在java中是一个抽象类
#include <string>
#include <vector>
#include "Util.h"
using namespace std;

class Parameter
{
private:
	string name;

public:
	virtual string getValue() = 0;
public:
	Parameter()
	{
		this->name = "";
	}
	Parameter(string name) 
	{
		this->name = name;
	}
	string getName()
	{
		return this->name;
	}
	string toString()
	{
		return this->getName() + "="+ this->getValue();
	}

	static vector<Parameter*>* combine(vector<Parameter*> *vp1, vector<Parameter*> *vp2) //Parameter是一个抽象类不能实例化，只能存指针
	{

		if (vp1 != NULL && vp2 != NULL && !(*vp1).empty() && !(*vp2).empty())
		{
			int n1 = (*vp1).size();
			int n2 = (*vp2).size();
			vector<Parameter*>* vp = new vector<Parameter*>();
			
			(*vp).insert((*vp).end(), (*vp1).begin(), (*vp1).end());
			(*vp).insert((*vp).end(), (*vp2).begin(), (*vp2).end());
			return vp;
		}
		if (vp1!=NULL && !(*vp1).empty())
			return vp1;
		if (vp2!=NULL && !(*vp2).empty())
			return vp2;
		return new vector<Parameter*>();//返回一个空vector

	}


};

#endif

