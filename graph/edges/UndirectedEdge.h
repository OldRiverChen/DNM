#ifndef _UNDIRECTEDEDGE_H_

#define _UNDIRECTEDEDGE_H_

#include <string>
#include "Edge.h"

class UndirectedNode;
using namespace std;
class UndirectedEdge : public Edge
{
public:
	static const string separator;
public:
	UndirectedEdge(UndirectedNode* node1, UndirectedNode* node2);
public:
	string asString();
	UndirectedNode* getNode1();
	UndirectedNode* getNode2();
private:
	void init_(UndirectedNode* node1, UndirectedNode* node2);

public://实现父类的方法
	bool connectToNodes();
	int getN1Index();
	int getN2Index();
	bool disconnectFromNodes();


};


#endif