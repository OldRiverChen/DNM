#include "BatchSanitizationStats.h"

BatchSanitizationStats::BatchSanitizationStats()
{
	this->deletedNodeAdditions = 0;
	this->deletedNodeRemovals = 0;
	this->deletedEdgeAdditions = 0;
	this->deletedEdgeRemovals = 0;
}

BatchSanitizationStats::BatchSanitizationStats(int deletedNodeAdditions, int deletedNodeRemovals, int deletedEdgeAdditions, int deletedEdgeRemovals)
{
	this->deletedNodeAdditions = deletedNodeAdditions;
	this->deletedNodeRemovals = deletedNodeRemovals;
	this->deletedEdgeAdditions = deletedEdgeAdditions;
	this->deletedEdgeRemovals = deletedEdgeRemovals;
}

int BatchSanitizationStats::getDeletedNodeAdditions()
{
	return this->deletedNodeAdditions;
}

int BatchSanitizationStats::getDeletedNodeRemovals()
{
	return this->deletedNodeRemovals;
}

int BatchSanitizationStats::getDeletedEdgeAdditions()
{
	return this->deletedEdgeAdditions;
}

int BatchSanitizationStats::getDeletedEdgeRemovals()
{
	return this->deletedEdgeRemovals;
}

int BatchSanitizationStats::getTotal()
{
	return this->deletedNodeAdditions+this->deletedNodeRemovals+this->deletedEdgeAdditions+this->deletedEdgeRemovals;
}

string BatchSanitizationStats::toString()
{
	return to_string(this->getTotal()) + "  updates deleted ("
		+ to_string(this->deletedNodeAdditions) + ","+to_string(this->deletedNodeRemovals)+"/"
		+ to_string(this->deletedEdgeAdditions) + "," + to_string(this->deletedEdgeRemovals) + ")";
}
