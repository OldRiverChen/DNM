#ifndef _A_ELEMENT_H_

#define _A_ELEMENT_H_

//һ��������
#include <string>
#include "IElement.h"
using namespace std;

class Element : public IElement
{
public:
	//ʵ����IElement��deepEquals
	bool deepEquals(IElement* other)
	{
		int f = this->asString().compare(other->asString());
		return f==0;
	}
};

#endif