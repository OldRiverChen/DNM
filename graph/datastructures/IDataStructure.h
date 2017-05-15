#ifndef _I_IDATASTRUCTURE_H_

#define _I_IDATASTRUCTURE_H_

//一个接口
#include <string>
#include "../IElement.h"
using namespace std;
/**
* Interface to define common methods on data structures
*
* @author Nico
*
*/
class IDataStructure
{

	public:
		/**
		* Initialize a data structure with a default size
		*
		* @param dataType
		*            Data type to be stored here
		* @param initialSize
		*            Default list size
		* @param firstTime
		*            Is this called for the first time? Necessary for the profiler,
		*            to distinguish constructor calls and following, where the list
		*            is only re-initialized
		*/
		virtual void init(int initialSize) = 0;

		/**
		* Reinitialize this data structure with a new size
		*
		* @param size
		*/
		virtual void reinitializeWithSize(int size)=0;
		/**
		* Add an element to this data structure
		*
		* @param element
		* @return true, if addition succeeded
		*/
		virtual bool add(IElement* element)=0;
		/**
		* Check whether an element is contained in this data structure
		*
		* @param element
		* @return
		*/
		virtual bool contains(IElement* element) = 0;
		/**
		* Remove an element from this data structure
		*
		* @param element
		* @return true, if removal succeeded
		*/
		virtual bool remove(IElement* element) = 0;
		/**
		* Get the number of elements stored in this data structure
		*
		* @return
		*/
		virtual int size()=0;

	
};

#endif
