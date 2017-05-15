#ifndef _PARAMEMTERLIST_H_

#define _PARAMEMTERLIST_H_


//��java����һ��������
#include <string>
#include <vector>
#include "Parameter.h"
using namespace std;

class ParameterList
{
private:
	string name;
	vector<Parameter*> *parameters; //Parameter��һ�������಻��ʵ������ֻ�ܴ�ָ��
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
	static string combineNames(vector<ParameterList>* pls);//��һ��ParameterList�����name�ϲ�
	static vector<Parameter*>* combineParameters(vector<ParameterList>* pls);//��һ��ParameterList�����parameters�ϲ�
	static vector<Parameter*> parse(vector<Parameter*>* parameters, vector<string> *values);
	static vector<Parameter*>* ArrayToVector(Parameter* array[], int len);//��һ��Parameter*����ϲ���һ��vector<Parameter*>

};

#endif


