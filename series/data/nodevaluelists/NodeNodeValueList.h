#ifndef _NODENODEVALUELIST_H_

#define _NODENODEVALUELIST_H_

#include <string>
#include <iostream>
#include "..\Data.h"
#include "..\..\..\util\Log.h"
#include "..\..\..\io\Writer.h"
using namespace std;
/**
* A NodeNodeValueList is an object that represents a n*n matrix for n nodes.
* Each node n is identified by its index and possesses n double values, one for
* each node. If a node is removed from the graph, his former values are
* replaced by Double.NaN's. When inserting new nodevalues with out-of-bound
* indices, the array's are expanded accordingly. Note: The field of doubles
* used to store the data will always have the same amount of rows and columns.
* The use of truncate allows to free unused index-space.
*
*/
class NodeNodeValueList:public Data
{
public:
	vector<vector<double>*>* values;//ถþฮฌสýื้
	static double emptyValue;
public:
	NodeNodeValueList(string name, int size);
	NodeNodeValueList(string name, vector<vector<double>*>* values);
public:
	vector<vector<double>*>* getValue();
	void write(string dir,string filename);




};

#endif