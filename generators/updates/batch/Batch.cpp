#include "Batch.h"

Batch::Batch(GraphDataStructure * gds, long long from, long long to)
{
	new(this)Batch(gds, from, to, 0, 0, 0, 0);
}

Batch::Batch(GraphDataStructure * gds, long long from, long long to, int nodeAdditions, int nodeRemovals, int edgeAdditions, int edgeRemovals)
{
	this->gds = gds;
	this->from = from;
	this->to = to;
	this->nodeAdditions = new map<Node*, NodeAddition*,Node_less>();
	this->nodeRemovals = new map<Node*, NodeRemoval*,Node_less>();
	this->edgeAdditions = new map<Edge*, EdgeAddition*,Edge_less>();
	this->edgeRemovals = new map < Edge*, EdgeRemoval*,Edge_less>();
	this->all = new vector<Update*>();//装map里面的value值，
}

bool Batch::addAll(vector<Update*>* all)
{
	boolean success = true;

	for (vector<Update*>::iterator iter = all->begin(); iter != all->end(); iter++)
	{
		Update* u = *iter;
		success &= this->add(u);
	}
	return success;
}

bool Batch::add(Update * u)
{
	if (instanceof<NodeAddition>(u))
		return this->add((NodeAddition*)u);
	else if(instanceof<NodeRemoval>(u))
		return this->add((NodeRemoval*)u);
	else if (instanceof<EdgeAddition>(u))
		return this->add((EdgeAddition*)u);
	else if (instanceof<EdgeRemoval>(u))
		return this->add((EdgeRemoval*)u);
	return false;
}

bool Batch::add(NodeAddition * na)
{
	pair< std::map< Node*, NodeAddition*, Node_less>::iterator, bool > ret = this->nodeAdditions->insert(pair<Node*, NodeAddition*>(na->getNode(),na));
	if (ret.second)//表示插入成功
		return true;
	else return false;

}

bool Batch::add(NodeRemoval * nr)
{
	pair< std::map< Node*, NodeRemoval*, Node_less>::iterator, bool > ret = this->nodeRemovals->insert(pair<Node*, NodeRemoval*>(nr->getNode(), nr));
	if (ret.second)//表示插入成功
		return true;
	else return false;
}

bool Batch::add(EdgeAddition * ea)
{
	pair< std::map<Edge*, EdgeAddition*, Edge_less>::iterator, bool > ret = this->edgeAdditions->insert(pair<Edge*, EdgeAddition*>(ea->getEdge(),ea));
	if (ret.second)
		return true;
	else return false;
}

bool Batch::add(EdgeRemoval * er)
{
	pair< std::map<Edge*, EdgeRemoval*, Edge_less>::iterator, bool > ret = this->edgeRemovals->insert(pair<Edge*, EdgeRemoval*>(er->getEdge(), er));
	if (ret.second)
		return true;
	else return false;
}

bool Batch::remove(Update * u)
{
	if (instanceof<NodeAddition>(u))
		return this->remove((NodeAddition*)u);
	else if (instanceof<NodeRemoval>(u))
		return this->remove((NodeRemoval*)u);
	else if (instanceof<EdgeAddition>(u))
		return this->remove((EdgeAddition*)u);
	else if (instanceof<EdgeRemoval>(u))
		return this->remove((EdgeRemoval*)u);
	return false;
}

bool Batch::remove(NodeAddition * na)
{
	int r = this->nodeAdditions->erase(na->getNode());
	if (r == 1)//表示删除成功
		return true;
	else 
		return false;
}

bool Batch::remove(NodeRemoval * nr)
{
	int r = this->nodeRemovals->erase(nr->getNode());
	if (r == 1)//表示删除成功
		return true;
	else
		return false;
}

bool Batch::remove(EdgeAddition * ea)
{
	int r = this->edgeAdditions->erase(ea->getEdge());
	if (r == 1)//表示删除成功
		return true;
	else
		return false;
}

bool Batch::remove(EdgeRemoval * er)
{
	int r = this->edgeRemovals->erase(er->getEdge());
	if (r == 1)//表示删除成功
		return true;
	else
		return false;
}

int Batch::getNodeAdditionsCount()
{
	return this->nodeAdditions->size();
}

int Batch::getNodeRemovalsCount()
{
	return this->nodeRemovals->size();
}

int Batch::getEdgeAdditionsCount()
{
	return this->edgeAdditions->size();
}

int Batch::getEdgeRemovalsCount()
{
	return this->edgeRemovals->size();
}

int Batch::getSize()
{
	return this->nodeAdditions->size()+this->nodeRemovals->size()+
		this->edgeAdditions->size()+this->edgeRemovals->size();
}

long long Batch::getTo()
{
	return this->to;
}

void Batch::setTo()
{
	this->to = to;
}

vector<Update*>* Batch::getAllUpdates()
{
	//contact this.nodeAdditions.values(), this.nodeRemovals.values(),this.edgeAdditions.values(),this.edgeRemovals.values()
	for (map<Node*, NodeAddition*>::iterator iter = this->nodeAdditions->begin(); iter != this->nodeAdditions->end(); iter++)
	{
		Update* u = iter->second;
		this->all->push_back(u);
	}
	for (map<Node*, NodeRemoval*>::iterator iter = this->nodeRemovals->begin(); iter != this->nodeRemovals->end(); iter++)
	{
		Update* u = iter->second;
		this->all->push_back(u);
	}
	for (map<Edge*, EdgeAddition*>::iterator iter = this->edgeAdditions->begin(); iter != this->edgeAdditions->end(); iter++)
	{
		Update* u = iter->second;
		this->all->push_back(u);
	}
	for (map<Edge*, EdgeRemoval*>::iterator iter = this->edgeRemovals->begin(); iter != this->edgeRemovals->end(); iter++)
	{
		Update* u = iter->second;
		this->all->push_back(u);
	}
	return this->all;;
}

vector<NodeAddition*>* Batch::getNodeAdditions()
{
	vector<NodeAddition*>* vna = new vector<NodeAddition*>();

	for (map<Node*, NodeAddition*>::iterator iter = this->nodeAdditions->begin(); iter != this->nodeAdditions->end(); iter++)
	{
		NodeAddition* na = iter->second;
		vna->push_back(na);
	}

	return vna;
}

vector<NodeRemoval*>* Batch::getNodeRemovals()
{
	vector<NodeRemoval*>* vnr = new vector<NodeRemoval*>();
	for (map<Node*, NodeRemoval*>::iterator iter = this->nodeRemovals->begin(); iter != this->nodeRemovals->end(); iter++)
	{
		NodeRemoval* nr = iter->second;
		vnr->push_back(nr);
	}
	return vnr;
}

vector<EdgeAddition*>* Batch::getEdgeAdditions()
{
	vector<EdgeAddition*>* vea = new vector<EdgeAddition*>();
	for (map<Edge*, EdgeAddition*>::iterator iter = this->edgeAdditions->begin(); iter != this->edgeAdditions->end(); iter++)
	{
		EdgeAddition* ea = iter->second;
		vea->push_back(ea);
	}
	return vea;
}

vector<EdgeRemoval*>* Batch::getEdgeRemovals()
{
	vector<EdgeRemoval*>* ver = new vector<EdgeRemoval*>();
	for (map<Edge*, EdgeRemoval*>::iterator iter = this->edgeRemovals->begin(); iter != this->edgeRemovals->end(); iter++)
	{
		EdgeRemoval* er = iter->second;
		ver->push_back(er);
	}
	return ver;
}



string Batch::toString()
{
	return "B " + to_string(this->from) + " -> " + to_string(this->to) + "("
		+ to_string(this->getNodeAdditionsCount()) + ","
		+ to_string(this->getNodeRemovalsCount()) + "/"
		+ to_string(this->getEdgeAdditionsCount()) + ","
		+ to_string(this->getEdgeRemovalsCount()) + ")";
}

