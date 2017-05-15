#include "GroupingV1.h"
#include "..\..\..\graph\nodes\UndirectedNode.h"
#include"..\..\..\graph\datastructures\DArrayList.h"

set<string>* GroupingV1::getGroups3(Edge * e)
{
	set<string>* set_rs = new set<string>();
	Node* n1 = e->getN1();
	IEdgeListDatastructure* n1_Edges = ((UndirectedNode*)n1)->getEdges();//��ȡe��һ���˵�n1���ڽӱ߼�
	DArrayList* dal_n1_Edges = (DArrayList*)n1_Edges;//����ת
	for (int j = 0; j < dal_n1_Edges->size(); j++)
	{
		UndirectedEdge* e_1 = (UndirectedEdge*)dal_n1_Edges->getEdge(j);
		Node* n1_o = e_1->getDifferingNode(n1);
		set_rs->insert(n1_o->getIndex()+"");
	}
	Node* n2 = e->getN2();
	IEdgeListDatastructure* n2_Edges = ((UndirectedNode*)n2)->getEdges();//��ȡe����һ���˵�n2���ڽӱ߼�
	DArrayList* dal_n2_Edges = (DArrayList*)n2_Edges;//����ת
	for (int j = 0; j < dal_n2_Edges->size(); j++)
	{
		UndirectedEdge* e_2 = (UndirectedEdge*)dal_n2_Edges->getEdge(j);
		Node* n2_o = e_2->getDifferingNode(n2);
		set_rs->insert(n2_o->getIndex() + "");
	}
	return set_rs;
}

set<string>* GroupingV1::getGroups4(Edge * e)
{
	set<string>* set_rs = new set<string>();
	Node* l = e->getN1();
	Node* r = e->getN2();

	return set_rs;
}

set<string>* GroupingV1::getGroups5(Edge * e)
{
	return nullptr;
}

void GroupingV1::add4(set<string> set, Node * l, Node * r)
{
	// L1, L1

}
