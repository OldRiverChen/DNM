#include "ParameterList.h"
#include <string>
#include <vector>
#include "Parameter.h"
#include <iostream>
#include "Util.h"
#include "parameters\DoubleParameter.h"
#include "parameters\IntParameter.h"
#include "parameters\LongParameter.h"
#include "parameters\StringParameter.h"

ParameterList::ParameterList(string name)
{
	this->name = name;
	this->parameters = new vector<Parameter*>();//返回一个空vector 
}

ParameterList::ParameterList(string name, vector<Parameter*>* parameters)
{
	this->name = name;
	if (parameters != NULL)
		this->parameters = parameters;
	else
	{
		this->parameters = new vector<Parameter*>();//返回一个空vector 
	}
		
}

ParameterList::ParameterList(string name, vector<Parameter*>* p1, vector<Parameter*>* p2)
{
	this->name = name;
	this->parameters = Parameter::combine(p1, p2);
}

string ParameterList::getName()
{
	string buffer(this->name);
	if (parameters->size() > 0)
	{
		for (vector<Parameter*>::iterator iter = parameters->begin(); iter != parameters->end(); iter++)
			buffer.append("-" + (*iter)->getValue());
	}
	return buffer;
}

string ParameterList::getDescription()
{	
	string buff(this->name);
	if (parameters->size() > 0)
	{
		for (vector<Parameter*>::iterator iter = parameters->begin(); iter != parameters->end(); iter++)
			buff.append(" " + (*iter)->getName() + "=" + (*iter)->getValue());
	}

	return buff;
}

string ParameterList::getNamePlain()
{
	return this->name;
}

vector<Parameter*>* ParameterList::getParameters()
{
	return this->parameters;
}

void ParameterList::setParameters(vector<Parameter*>* parameters)
{
	this->parameters = parameters;
}

string ParameterList::combineNames(vector<ParameterList>* pls)//将一列ParameterList里面的name合并
{
	string buff("COMB");
	for (vector<ParameterList>::iterator iter = pls->begin(); iter != pls->end(); iter++)
		buff.append("_" + iter->getNamePlain());
	return buff;
}

vector<Parameter*>* ParameterList::combineParameters(vector<ParameterList>* pls)//将一列ParameterList里面的parameters合并
{
	vector<Parameter*>* vp = new vector<Parameter*>();
	for (vector<ParameterList>::iterator iter = pls->begin(); iter != pls->end(); iter++)
	{
		vp->insert(vp->end(), iter->getParameters()->begin(), iter->getParameters()->end());
	}
	return vp;
}

vector<Parameter*> ParameterList::parse(vector<Parameter*>* parameters, vector<string> *values)//根据parameters数组各个element的type，其赋值values
{
	if (parameters->size() != values->size()) 
	{
		cout << "parameters and values do not have the same length" << endl;
		exit(1);
	}
	vector<Parameter*> vp(parameters->size());//初始化一个长度为parameters->size()的vector
	int i = 0;
	for (vector<Parameter*>::iterator iter = parameters->begin(); iter != parameters->end(); iter++)
	{
		if (instanceof<DoubleParameter>(*iter)) 
		{
			vp[i] = new DoubleParameter((*iter)->getName(),stringToNum<double>(values->at(i)));
		}
		else if (instanceof<IntParameter>(*iter))
		{
			vp[i] = new IntParameter((*iter)->getName(), stringToNum<int>(values->at(i)));
		}
		else if (instanceof<LongParameter>(*iter))
		{
			vp[i] = new LongParameter((*iter)->getName(), stringToNum<long>(values->at(i)));
		}
		else if (instanceof<StringParameter>(*iter))
		{
			vp[i] = new StringParameter((*iter)->getName(), values->at(i));
		}
		else
		{
			cout << "unknown parameter type" << endl;
			exit(1);
		}
		i++;
	}
	return vp;
}
vector<Parameter*>* ParameterList::ArrayToVector(Parameter* array[], int len)//将一列Parameter*数组合并成一个vector<Parameter*>
{
	vector<Parameter*>* vp = new vector<Parameter*>();
	for (vector<ParameterList>::size_type i = 0; i < len; i++)
		vp->push_back(array[i]);
	return vp;
}