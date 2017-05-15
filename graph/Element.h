#ifndef _A_ELEMENT_H_

#define _A_ELEMENT_H_

//一个抽象类
#include <string>
#include "IElement.h"
using namespace std;

class Element : public IElement
{
public:
	//实现了IElement的deepEquals
	bool deepEquals(IElement* other)
	{
		int f = this->asString().compare(other->asString());
		return f==0;
	}
};

#endif