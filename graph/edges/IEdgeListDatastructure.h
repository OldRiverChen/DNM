#ifndef _I_IEDGELISTDATASTRUCTURE_H_

#define _I_IEDGELISTDATASTRUCTURE_H_

//一个接口
#include "../datastructures/IDataStructure.h"
using namespace std;
class Edge;
class IEdgeListDatastructure:public IDataStructure
{

	public:
		/**
		* Add an edge to this data structure
		*
		* @param element
		* @return true, if addition succeeded
		*/
		virtual bool add(Edge* element) = 0;

		/**
		* Check whether an edge is contained in this data structure
		*
		* @param element
		* @return
		*/
		virtual bool contains(Edge* element)=0;
		/**
		* Remove an edge from this data structure
		*
		* @param element
		* @return true, if removal succeeded
		*/
		virtual bool remove(Edge* element)=0;


		/**
		* Retrieve an edge from this data structure (use case: we know source and
		* destination node, but want to get additional data too like weights,
		* flows,...)
		*
		* @param int n1, n2
		* @return
		*/
		virtual Edge* get(int n1, int n2)=0;

		/**
		* Retrieve an edge from this data structure (use case: we know source and
		* destination node, but want to get additional data too like weights,
		* flows,...)
		*
		* @param element
		* @return
		*/
		virtual Edge* get(Edge* element)=0;

		virtual void show() = 0;

		virtual IElement* getRandom() = 0;
	
};

#endif
