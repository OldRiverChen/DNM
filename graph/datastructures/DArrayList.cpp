#include <algorithm> 
#include <functional>
#include "DArrayList.h"
#include "..\..\util\Util.h"
#include "..\nodes\Node.h"
#include "..\nodes\UndirectedNode.h"
#include "..\edges\Edge.h"
#include "..\edges\UndirectedEdge.h"

DArrayList::DArrayList()
{
	lists = new vector<IElement*>();
	maxNodeIndex = -1;
}

void DArrayList::init(int initialSize)
{
	if (initialSize < 1)
		initialSize = 1;
	lists = new vector<IElement*>();
	lists->reserve(initialSize);//分配capacity,而不是改变size()值
	maxNodeIndex = -1;
}


vector<IElement*>::iterator DArrayList::findNode(Node* n)
{
	vector<IElement*>::iterator iter = find_if(this->lists->begin(), this->lists->end(), bind2nd(Node_find(), n));//用find_if
	//for (iter = this->lists->begin(); iter != this->lists->end(); iter++)
	//{
	//	if ((*iter)->deepEquals(n))
	//	{
	//		cout << (*iter)->asString() << endl;
	//		break;
	//	}
	//}
	return iter;
}

vector<IElement*>::iterator DArrayList::findEdge_vector(Edge * e)
{
	vector<IElement*>::iterator it = find_if(this->lists->begin(), this->lists->end(), bind2nd(Edge_find(), e));
	return it;
}



//IDataStructure
void DArrayList::reinitializeWithSize(int size)
{
}

bool DArrayList::add(IElement * element)
{
	if (this->contains(element))
		return false;
	if (instanceof<Node>(element))
		return this->add((Node*)element);
	else if (instanceof<Edge>(element))
		return this->add((Edge*)element);
	else {
		cout <<"Can't add element of type !!"<< endl;
		exit(0);
		return false;
	}
		
}

bool DArrayList::contains(IElement * element)
{
	if (instanceof<Node>(element))
		return this->contains((Node*)element);
	else if (instanceof<Edge>(element))
		return this->contains((Edge*)element);
	else {
		cout << "Can't contains element of type !!" << endl;
		exit(0);
		return false;
	}

}

bool DArrayList::remove(IElement * element)
{
	return false;
}

int DArrayList::size()
{
	return lists->size();
}



//INodeListDatastructure

bool DArrayList::add(Node * element)
{
	if (!instanceof<Node>(element))
		return false;
	if (this->contains(element))
		return false;
	this->lists->push_back(element);
	this->maxNodeIndex = max(this->maxNodeIndex, element->getIndex());//更新maxNodeIndex值
	return true;
}
bool DArrayList::contains(Node* element)
{
	vector<IElement*>::iterator iter = findNode(element);
	if (iter != this->lists->end())
		return true;
	else return false;
}

bool DArrayList::remove(Node * element)
{
	if (!instanceof<Node>(element))
		return false;
	vector<IElement*>::iterator iter = findNode(element);
	if(iter ==this->lists->end())//不包含该element
		return false;
	else {
		this->lists->erase(iter);
		//更新maxNodeIndex值
		if (this->maxNodeIndex == element->getIndex())
		{
			int max_v = -1;
			for (vector<IElement*>::iterator iter = this->lists->begin(); iter != this->lists->end(); iter++)
			{
				max_v = max(((Node*)(*iter))->getIndex(), max_v);
			}
			this->maxNodeIndex = max_v;
		}
		return true;
	}
}
int DArrayList::getMaxNodeIndex()
{
	return this->maxNodeIndex;
}

Node * DArrayList::get(int index)
{
	return NULL;
}




//IEdgeListDatastructure

bool DArrayList::add(Edge * element)
{
	if (!instanceof<Edge>(element))
		return false;
	if (this->contains(element))
		return false;
	this->lists->push_back(element);
	return true;
}
bool DArrayList::contains(Edge * element)
{
	vector<IElement*>::iterator it = this->findEdge_vector(element);
	if (it != this->lists->end())
		return true;
	else return false;
}

bool DArrayList::remove(Edge * element)
{
	if (!instanceof<Edge>(element))
		return false;
	vector<IElement*>::iterator it = this->findEdge_vector(element);//无需再次调用contains来判断是非包含element，不然会调用两次findEdge_vector
	if (it == this->lists->end())//表示无该边
		return false;
	this->lists->erase(it);
	return true;
}

Edge * DArrayList::get(int n1, int n2)
{
	for (vector<IElement*>::iterator iter = this->lists->begin(); iter != this->lists->end(); iter++)
	{
		IElement* ie = *iter;
		if (ie == NULL)
			continue;
		Edge* e = (Edge*)ie;
		if (e->getN1Index() == n1&&e->getN2Index() == n2)
			return e;
	}
	return NULL;
}

Edge * DArrayList::get(Edge * element)
{
	return this->get(element->getN1Index(), element->getN2Index());
}

Edge * DArrayList::getEdge(int index)
{
	if(index>=this->size())
		return nullptr;
	else return (Edge*)this->lists->at(index);
}

IElement * DArrayList::getRandom()
{
	if (this->size() <= 0)
		return NULL;
	int index = Rand::nextInt(this->size());
	while (this->lists->at(index) == NULL)
	{
		index = Rand::nextInt(this->size());
	}
	return this->lists->at(index);
}
