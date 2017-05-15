#ifndef _GDS_H_

#define _GDS_H_

#include <string>
#include "IDataStructure.h"
#include "GraphDataStructure.h"
#include "..\nodes\Node.h"
#include "..\edges\Edge.h"

using namespace std;
/**
* Interface to define common methods on data structures
*
* @author Nico
*
*/
class GDS
{
public:
	static IDataStructure* nodes;
	static IDataStructure* edges;
	static IDataStructure* local;
public:
	static GraphDataStructure* undirected();
public:
	static GraphDataStructure* gds(Node* node, Edge* edge);
	
};

#endif
