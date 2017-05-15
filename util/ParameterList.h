#ifndef _PARAMEMTERLIST_H_

#define _PARAMEMTERLIST_H_


//在java中是一个抽象类
#include <string>
#include <vector>
#include "Parameter.h"
using namespace std;

class ParameterList
{
private:
	string name;
	vector<Parameter*> *parameters; //Parameter是一个抽象类不能实例化，只能存指针
public:
	ParameterList(string name);
	ParameterList(string name, vector<Parameter*>* parameters);

	ParameterList(string name, vector<Parameter*>* p1, vector<Parameter*>* p2);

public:
	string getName();
	string getDescription();
	string getNamePlain();
	vector<Parameter*>* getParameters();
	void setParameters(vector<Parameter*>* parameters);

public:
	static string combineNames(vector<ParameterList>* pls);//将一列ParameterList里面的name合并
	static vector<Parameter*>* combineParameters(vector<ParameterList>* pls);//将一列ParameterList里面的parameters合并
	static vector<Parameter*> parse(vector<Parameter*>* parameters, vector<string> *values);
	static vector<Parameter*>* ArrayToVector(Parameter* array[], int len);//将一列Parameter*数组合并成一个vector<Parameter*>

};

#endif


