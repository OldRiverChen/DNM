#include "Grouping.h"
#include <bitset>
#include "..\..\..\util\ArrayUtils.h"
#include "..\..\..\util\Util.h"
vector<int>* Grouping::getKeys(Graph * g, Node * n1, Node * n2, string group)
{
	string strKey0 = '0' + this->getKey(g, n1, n2, group);
	string strKey1 = '1' + this->getKey(g, n1, n2, group);
	bitset<32> b1(strKey0);
	bitset<32> b2(strKey1);

	return new vector<int>{b1.to_ulong,b2.to_ulong};
}

string Grouping::getKey(Graph * g, Node * n1, Node * n2, string group)
{
	vector<string>* temp = ArrayUtils::split(group, ";");
	vector<Node*> *nodes = new vector<Node*>();
	nodes->reserve(temp->size()+2);
	nodes->push_back(n1);//相当于nodes[0]=n1
	nodes->push_back(n2);//相当于nodes[1]=n2
	for (int i = 0; i < temp->size(); i++)
	{
		nodes->push_back(g->getNode(stringToNum<int>(temp->at(i))));//相当于nodes[i+2]=g.getNode(Integer.parseInt(temp[i]));
	}
	string key = "";
	for (int i = 0; i < nodes->size(); i++) {
		for (int j = i + 1; j < nodes->size(); j++) {
			if ((i == 0 && j == 1)) {
				continue;
			}
			if (g->containsEdge(nodes->at(i), nodes->at(j))) {
				key += '1';
			}
			else {
				key += '0';
			}
		}
	}
	return key;
}

set<string>* Grouping::getGroups3(Edge * e)
{
	return nullptr;
}

set<string>* Grouping::getGroups4(Edge * e)
{
	return nullptr;
}

set<string>* Grouping::getGroups5(Edge * e)
{
	return nullptr;
}

