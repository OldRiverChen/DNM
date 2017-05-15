#ifndef _DUMMYUNDIRECTEDEDGE_H_

#define _DUMMYUNDIRECTEDEDGE_H_

#include <string>
#include <algorithm>


#include "IEdgeDummy.h"
#include "UndirectedEdge.h"
using namespace std;
class UndirectedNode;
class DummyUndirectedEdge : public UndirectedEdge, public IEdgeDummy
{
public:
	DummyUndirectedEdge(UndirectedNode* src, UndirectedNode* dst);
public://ÊµÏÖIEdgeDummyµÄsetNodes
	void setNodes(int n1, int n2);

};


#endif