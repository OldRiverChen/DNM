#ifndef _I_ELEMENT_H_

#define _I_ELEMENT_H_

//һ���ӿ�
#include <string>
using namespace std;
/*
Interface for all types of nodes and edges we might create
*/
class IElement
{
public:
	/**
	* String representation for an element, through which it can be recreated
	* on reading in a dumped graph
	*
	* @return
	*/
	virtual string asString() = 0;
	/**
	* Checks whether two elements are completely equal, mostly defined through
	* equality of their string representations. This goes deeper than the
	* common equality which does not check for equal additional fields like
	* weights
	*
	* @param other
	* @return
	*/
	virtual bool deepEquals(IElement* other)=0;//�����಻�ܶ��ڶ��󣬵������ó�����ඨ��ָ��! IElement other ����
};

#endif
