#ifndef _A_UNDIRECTEDCLUSTERINGCOEFFICIENT_H_

#define _A_UNDIRECTEDCLUSTERINGCOEFFICIENT_H_

//一个抽象类
#include <string>
#include <iostream>
#include "ClusteringCoefficient.h"
#include "..\..\util\ArrayUtils.h"
using namespace std;

class UndirectedClusteringCoefficient : public ClusteringCoefficient
{
public:
	UndirectedClusteringCoefficient(string name);
public:
	bool compute();
	bool computeUndirected();
	void update(int index);
	void update();
protected:
	void removeTriangle(Node* origin);
	void updateNode(int index);
	void removePotentials(Node* origin, int count);
	void addTriangle(Node* origin);
	void addPotentials(Node* origin, int count);

};

#endif