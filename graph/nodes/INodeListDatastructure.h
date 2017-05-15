#ifndef _I_INODELISTDATASTRUCTURE_H_

#define _I_INODELISTDATASTRUCTURE_H_

//一个接口
class Node;
#include "../datastructures/IDataStructure.h"
using namespace std;
class INodeListDatastructure :public IDataStructure
{

	public:
		/**
		* Add a node to this data structure
		*
		* @param element
		* @return true, if addition succeeded
		*/
		virtual bool add(Node* element) = 0;

		/**
		* Check whether a node is contained in this data structure
		*
		* @param element
		* @return
		*/
		virtual bool contains(Node* element)=0;
		/**
		* Remove a node from this data structure
		*
		* @param element
		* @return true, if removal succeeded
		*/
		virtual bool remove(Node* element)=0;
		/**
		* Retrieve the highest node index within this data structure
		*
		* @return
		*/
		virtual int getMaxNodeIndex() = 0;

		/**
		* Retrieve a node from the data structure by its index
		*
		* @param index
		* @return
		*/
		virtual Node* get(int index) = 0;

		virtual void show()=0;

		//java版本 IReadable的,写成虚函数，子类想重写就重写。
		virtual IElement* getRandom()
		{
			return NULL;
		}
	
};

#endif
