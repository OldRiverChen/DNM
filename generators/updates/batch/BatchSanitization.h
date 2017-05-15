#ifndef _BATCHSANITIZATION_H_

#define _BATCHSANITIZATION_H_

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include "BatchSanitizationStats.h"
#include "Batch.h"
using namespace std;
/**
* performs a sanitization of the updates stored in this batch, i.e., (1)
* deleted all edge removals that point to a node which is removed anyways
* (2) delete all edge additions that point to a node that is removed but
* not added again (3) delete all edge weights for edges that are removed
* but not added again (4) delete all node weights for nodes that are
* removed but not added again
*
* @return
*/
class BatchSanitization
{
public:
	static vector<Node*>* getNodesFromEdge(Edge* e);
public:
	static BatchSanitizationStats* sanitize(Batch* batch);

};

#endif
