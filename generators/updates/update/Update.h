#ifndef _A_UPDATE_H_

#define _A_UPDATE_H_
//һ��������
#include <iostream>
#include <string>
#include <vector>
#include "..\..\..\graph\Graph.h"
using namespace std;

enum UpdateType {
	NA, NR, EA, ER
};
class Update
{
public:
	const static string TypeDelimiter;
	const static string EdgeSeparator;
public:
	bool apply(Graph* g);
	string asString();
	string toString();
public:
	virtual bool apply_(Graph* g) = 0;
	virtual string asString_()=0;
	virtual string toString_()=0;
	virtual string getType()=0;
public:
	static string UpdateTypeToString(UpdateType ut);

};

#endif
