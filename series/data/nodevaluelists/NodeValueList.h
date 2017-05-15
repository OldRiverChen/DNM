#ifndef _NODEVALUELIST_H_

#define _NODEVALUELIST_H_

#include <string>
#include <iostream>
#include "..\Data.h"
#include "..\..\..\util\Log.h"
#include "..\..\..\io\Writer.h"
using namespace std;
/**
* A NodeValueList is an object containing an array with 1 value for each node.
* The node index is used as the index for the array. If a node is removed from
* the graph, his former value is replaced by a Double.NaN. When inserting new
* nodevalues with out-of-bound indeces, the array is expanded accordingly.
*
*/
class NodeValueList:public Data
{
public:
	vector<double>* values;
	static double emptyValue;
public:
	NodeValueList(string name, int size);
	NodeValueList(string name, vector<double>* values);
	NodeValueList(string name, vector<long>* values);
public:
	vector<double>* getValues();
	void setValue(int index,double value);
	// IO methods
	/**
	*
	* @param dir
	*            String which contains the path / directory the NodeValueList
	*            will be written to.
	*
	* @param filename
	*            String representing the desired filename for the
	*            NodeValueList.
	*/
	void write(string dir, string filename);



};

#endif