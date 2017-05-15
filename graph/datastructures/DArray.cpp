#include "DArray.h"
#include "..\..\util\Util.h"
#include "..\nodes\Node.h"
#include "..\nodes\UndirectedNode.h"
#include "..\edges\Edge.h"
#include "..\edges\UndirectedEdge.h"
#include "..\..\util\Rand.h"

DArray::DArray()
{
	lists = NULL;
	maxNodeIndex = -1;
	count = 0;
	length = 0;
}

void DArray::init(int initialSize)
{
	if (initialSize < 1)
		initialSize = 1;
	lists = (IElement**)malloc(sizeof(IElement*)*initialSize);
	memset(lists, 0, sizeof(IElement*)*initialSize);//清空为0
	length = initialSize;
	maxNodeIndex = -1;
	count = 0;

}




//IDataStructure
void DArray::reinitializeWithSize(int size)
{
}

bool DArray::add(IElement * element)
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

bool DArray::contains(IElement * element)
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

bool DArray::remove(IElement * element)
{
	return false;
}

int DArray::size()
{
	return this->count;
}



//INodeListDatastructure

bool DArray::add(Node * element)//必须连续添加
{
	if (!instanceof<Node>(element))
		return false;
	if (this->contains(element))
		return false;
	if (this->lists == NULL&&this->length == 0)
	{
		this->lists= (IElement**)malloc(sizeof(IElement*)*(element->getIndex() + 1));
		memset(lists, 0, sizeof(IElement*)*(element->getIndex() + 1));
		this->length = element->getIndex() + 1;
	}
	while (element->getIndex() >= this->length)
	{
		IElement** newLists = (IElement**)malloc(sizeof(IElement*)*(this->length + 1));
		memset(newLists, 0, sizeof(IElement*)*(this->length + 1));
		memcpy(newLists, this->lists, this->length);//第一层copy
		//第二层copy
		for (int i = 0; i < this->length; i++)
		{
			newLists[i] = this->lists[i];
			//newLists[i] = (Node*)malloc(sizeof(Node) * 1);
			//memcpy(newLists[i],this->lists[i],sizeof(Node)*1);
		}
		if (this->lists != NULL)
		{
			free(this->lists);//释放原来的空间
			this->lists = NULL;
		}
		this->length = this->length + 1;
		this->lists = newLists;
	}
	if (this->lists[element->getIndex()] != NULL)//说明该位置上已经有元素了
		return false;
	this->lists[element->getIndex()] = element;
	this->count++;
	if (element->getIndex() > this->maxNodeIndex)
	{
		this->maxNodeIndex = element->getIndex();
	}
	return true;
}
bool DArray::contains(Node* element)
{
	return this->length>element->getIndex() && this->lists[element->getIndex()] != NULL;//NULL == 0;必须连续添加
}

bool DArray::remove(Node * element)
{
	if (!instanceof<Node>(element))
		return false;
	if (this->length <= element->getIndex())
	{
		return false;
	}
	if (this->lists[element->getIndex()] == NULL)
	{
		return false;
	}
	this->lists[element->getIndex()] = NULL;
	this->count--;
	//更新maxNodeIndex
	if (element->getIndex() == this->maxNodeIndex)
	{
		for (int i = this->maxNodeIndex; i >= 0; i--)
		{
			if (this->lists[i] != NULL)
			{
				this->maxNodeIndex = ((Node*)this->lists[i])->getIndex();
				break;
			}
			if (i == 0 && this->maxNodeIndex == element->getIndex())
			{
				this->maxNodeIndex = -1;
			}
		}
	}
	if (this->lists[this->length - 1] != NULL)
	{
		return true;
	}
	if (this->maxNodeIndex >= this->length / 2) {
		return true;
	}
	IElement** nodesNew = (IElement**)malloc(sizeof(IElement*)*(this->maxNodeIndex + 1));
	memset(nodesNew, 0, sizeof(IElement*)*(this->maxNodeIndex + 1));
	memcpy(nodesNew, this->lists, this->maxNodeIndex + 1);//第一层copy
	//第二层copy
	for (int i = 0; i < this->maxNodeIndex + 1; i++)
	{
		nodesNew[i] = this->lists[i];
		//newLists[i] = (Node*)malloc(sizeof(Node) * 1);
		//memcpy(newLists[i],this->lists[i],sizeof(Node)*1);
	}
	if (this->lists != NULL)
	{
		free(this->lists);//释放原来的空间
		this->lists = NULL;
	}
	this->length = this->maxNodeIndex + 1;
	this->lists = nodesNew;
	return false;
}
int DArray::getMaxNodeIndex()
{
	return this->maxNodeIndex;
}

Node * DArray::get(int index)
{
	if (index >= this->length)
	{
		cout <<"DArray:index out of range in get()"<<endl;
		exit(1);
	}
	return (Node*)this->lists[index];
}

IElement* DArray::getRandom()
{
	if (this->size() == 0)
		return NULL;
	int index = Rand::nextInt(this->length);
	while (this->lists[index] == NULL) 
	{
		index = Rand::nextInt(this->length);
	}
	return this->lists[index];

}


//IEdgeListDatastructure

bool DArray::add(Edge * element)
{
	return false;
}
bool DArray::contains(Edge * element)
{
	return false;
}

bool DArray::remove(Edge * element)
{
	return false;
}

Edge * DArray::get(int n1, int n2)
{
	return NULL;
}

Edge * DArray::get(Edge * element)
{
	return NULL;
}
