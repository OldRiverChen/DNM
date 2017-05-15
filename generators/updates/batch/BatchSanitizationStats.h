#ifndef _BATCHSANITIZATIONSTATS_H_

#define _BATCHSANITIZATIONSTATS_H_

#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BatchSanitizationStats
{
public:
	int deletedNodeAdditions;
	int deletedNodeRemovals;
	int deletedEdgeAdditions;
	int deletedEdgeRemovals;
public:
	BatchSanitizationStats();
	BatchSanitizationStats(int deletedNodeAdditions, int deletedNodeRemovals,
		int deletedEdgeAdditions, int deletedEdgeRemovals);
public:
	int getDeletedNodeAdditions();
	int getDeletedNodeRemovals();
	int getDeletedEdgeAdditions();
	int getDeletedEdgeRemovals();
	int getTotal();
	string toString();

};

#endif
