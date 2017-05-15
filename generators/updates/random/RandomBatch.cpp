#include "RandomBatch.h"
#include "..\..\..\util\parameters\IntParameter.h"
#include "..\..\..\util\ParameterList.h"
#include "rand\RandomEdgeAdditions.h"
#include "rand\RandomEdgeRemovals.h"
#include "rand\RandomNodeAdditions.h"
#include "rand\RandomNodeRemovals.h"

int RandomBatch::getNa()
{
	return na;
}

int RandomBatch::getNr()
{
	return nr;
}
int RandomBatch::getEa()
{
	return ea;
}
int RandomBatch::getEr()
{
	return er;
}
void RandomBatch::init()
{
	if (na > 0) 
	{
		this->bgs->push_back(new RandomNodeAdditions(na));
	}
	if (nr > 0)
	{
		this->bgs->push_back(new RandomNodeRemovals(nr));
	}
	if (ea > 0)
	{
		this->bgs->push_back(new RandomEdgeAdditions(ea));
	}
	if (er > 0)
	{
		this->bgs->push_back(new RandomEdgeRemovals(er));
	}
}

RandomBatch::RandomBatch(int na, int nr, int ea, int er):BatchGenerator("RandomBatch", NULL)
{
	Parameter* defaultArray[] = { new IntParameter("NA",na), new IntParameter("NR", nr) ,
	new IntParameter("EA",ea),new IntParameter("ER",er)};//默认参数值
	//通过set注入
	this->setParameters(ParameterList::ArrayToVector(defaultArray, 4));
	this->na = na;
	this->nr = nr;
	this->ea = ea;
	this->er = er;

	bgs = new vector<BatchGenerator*>();
	init();

}

Batch* RandomBatch::generate(Graph* g)
{
	Batch* b = new Batch(g->getGraphDatastructures(),g->getTimestamp(), g->getTimestamp()+1,this->na,this->nr,this->ea,this->er);

	for (vector<BatchGenerator*>::iterator iter = this->bgs->begin(); iter != this->bgs->end();iter++)
	{
		BatchGenerator* bg = *iter;
		b->addAll(bg->generate(g)->getAllUpdates());
	}
	return b;
}

void RandomBatch::reset()
{

}

bool RandomBatch::isFurtherBatchPossible(Graph* g)
{
	for (vector<BatchGenerator*>::iterator iter = this->bgs->begin(); iter != this->bgs->end(); iter++)
	{
		BatchGenerator* bg = *iter;
		if (bg->isFurtherBatchPossible(g)) {
			return true;
		}
	}
	return false;
}

void RandomBatch::show()
{
	cout << "Batch's name:" << this->getNamePlain() << endl;
	if (this->getParameters() != NULL)
	{
		cout << "Batch's parameters: " << endl;
		vector<Parameter*>* params = this->getParameters();
		for (vector<Parameter*>::iterator iter = params->begin(); iter != params->end(); iter++)
		{
			Parameter* p = (*iter);
			cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
		}
	}
	if (this->bgs->size() > 0) {
		cout << "na,nr,ea,er: " << endl;
		for (vector<BatchGenerator*>::iterator iter = this->bgs->begin(); iter != this->bgs->end(); iter++)
		{
			BatchGenerator* bg = (*iter);
			bg->show();
		}
	}
}
