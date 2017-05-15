#include "GDS.h"
#include "GraphDataStructure.h"
#include "..\edges\Edge.h"
#include "..\nodes\Node.h"
#include "..\nodes\UndirectedNode.h"
#include "..\edges\UndirectedEdge.h"

GraphDataStructure* GDS::undirected()
{
	UndirectedNode* uNode1 = new UndirectedNode(1,NULL);
	UndirectedNode* uNode2 = new UndirectedNode(2, NULL);
	UndirectedNode* uNode3 = new UndirectedNode(3, NULL);

	UndirectedEdge* uEdge1 = new UndirectedEdge(uNode2, uNode3);

	//cout << uNode1->asString() << endl;
	//cout << uEdge1->asString() << endl;


	return GDS::gds(uNode1, uEdge1);
}

GraphDataStructure* GDS::gds(Node* node,Edge* edge)
{
	return new GraphDataStructure(node,edge);
}


