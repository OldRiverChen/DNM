#include "BatchSanitization.h"
#include "..\..\..\graph\nodes\UndirectedNode.h"

vector<Node*>* BatchSanitization::getNodesFromEdge(Edge * e)
{
	//只有无向图
	vector<Node*>* vn = new vector<Node*>();
	UndirectedNode* n1 = ((UndirectedEdge*)e)->getNode1();
	UndirectedNode* n2 = ((UndirectedEdge*)e)->getNode2();
	vn->push_back(n1);
	vn->push_back(n2);
	return vn;
}

BatchSanitizationStats * BatchSanitization::sanitize(Batch * b)//清除b中无效的操作，删除的边中包含删除的顶点（默认是先删除顶点，再删除边）
{
	BatchSanitizationStats* stats = new BatchSanitizationStats();

	set<Node*, Node_less>* removedN = new set<Node*, Node_less>();
	vector<NodeRemoval*>* nodeRemovals = b->getNodeRemovals();
	for (vector<NodeRemoval*>::iterator iter = nodeRemovals->begin(); iter != nodeRemovals->end(); iter++)
	{
		NodeRemoval* nr = *iter;
		Node* n = nr->getNode();
		removedN->insert(n);
	}

	set<Node*, Node_less>* addedN = new set<Node*, Node_less>();
	vector<NodeAddition*>* nodeAdditions = b->getNodeAdditions();
	for (vector<NodeAddition*>::iterator iter = nodeAdditions->begin(); iter != nodeAdditions->end(); iter++)
	{
		NodeAddition* na = *iter;
		Node* n = na->getNode();
		addedN->insert(n);
	}

	set<Edge*, Edge_less>* removedE = new set<Edge*, Edge_less>();
	vector<EdgeRemoval*>* edgeRemovals = b->getEdgeRemovals();
	for (vector<EdgeRemoval*>::iterator iter = edgeRemovals->begin(); iter != edgeRemovals->end(); iter++)
	{
		EdgeRemoval* er = *iter;
		Edge* e = er->getEdge();
		removedE->insert(e);
	}
	/**
	* delete edge removals of nodes which are going to be deleted anyways
	*/
	//若有删除的顶点，且删除的边中包含删除的顶点，那么这个删除边就无效，且应该从batch b 中移除
	set<EdgeRemoval*, EdgeUpdate_less>* edgeRemovalsToDelete = new set<EdgeRemoval*, EdgeUpdate_less>();
	for (vector<EdgeRemoval*>::iterator iter = edgeRemovals->begin(); iter != edgeRemovals->end(); iter++)
	{
		EdgeRemoval* er = *iter;
		Edge* e = er->getEdge();
		vector<Node*>* n = BatchSanitization::getNodesFromEdge(e);
		if ((removedN->find(n->at(0)) != removedN->end()) || (removedN->find(n->at(1)) != removedN->end()))//看removedN是否有删除边中的顶点
		{
			edgeRemovalsToDelete->insert(er);
		}
	}
	//从batch b中移除edgeRemovalsToDelete的这个无效的EdgeRemovel;
	for (set<EdgeRemoval*, EdgeUpdate_less>::iterator iter = edgeRemovalsToDelete->begin(); iter != edgeRemovalsToDelete->end(); iter++)
	{
		EdgeRemoval *er = *iter;
		b->remove(er);
	}
	stats->deletedEdgeRemovals = edgeRemovalsToDelete->size();

	/**
	* delete edge additions of nodes which are going to be deleted anyways
	* (only keep them in case the node is afterwards added again)
	*/
	//若有删除的顶点，且增加的边中包含删除的顶点，那么这个增加边就无效，且应该从batch b 中移除
	set<EdgeAddition*, EdgeUpdate_less>* edgeAdditionsToDelete = new set<EdgeAddition*, EdgeUpdate_less>();
	vector<EdgeAddition*>* edgeAdditions = b->getEdgeAdditions();
	for (vector<EdgeAddition*>::iterator iter = edgeAdditions->begin(); iter != edgeAdditions->end(); iter++)
	{
		EdgeAddition* ea = *iter;
		Edge* e = ea->getEdge();
		vector<Node*>* n = BatchSanitization::getNodesFromEdge(e);
		if ((removedN->find(n->at(0)) != removedN->end()) || (removedN->find(n->at(1)) != removedN->end()))//看removedN是否有增加边中的顶点
		{
			edgeAdditionsToDelete->insert(ea);
		}
	}
	//从batch b中移除edgeAdditionsToDelete的这个无效的EdgeAddition;
	for (set<EdgeAddition*, EdgeUpdate_less>::iterator iter = edgeAdditionsToDelete->begin(); iter != edgeAdditionsToDelete->end(); iter++)
	{
		EdgeAddition *ea = *iter;
		b->remove(ea);
	}
	stats->deletedEdgeAdditions = edgeAdditionsToDelete->size();

	free(nodeRemovals);
	free(nodeAdditions);
	free(edgeRemovals);
	free(edgeAdditions);
	return stats;
}
