#include <iostream>
#include <limits>
#include "util\Util.h"
#include <vector>
#include <string>
#include <sstream>
#include <bitset>
#include "util\Parameter.h"
#include "util\ParameterList.h"
#include "util\parameters\DoubleParameter.h"
#include "util\parameters\IntParameter.h"
#include "util\parameters\LongParameter.h"
#include "util\parameters\StringParameter.h"
#include "generators\GraphGenerator.h"
#include "generators\model\RandomGraph.h"
#include "graph\nodes\Node.h"
#include "graph\datastructures\GDS.h"
#include "generators\updates\BatchGenerator.h"
#include "generators\updates\random\RandomBatch.h"
#include "metrics\Metric.h"
#include "metrics\IMetric.h"
#include "metrics\degree\DegreeDistributionR.h"
#include "metrics\clustering\UndirectedClusteringCoefficientU.h"
#include "series\Series.h"
#include "util\Log.h"
#include "series\data\SeriesData.h"
#include "series\data\lists\SortedList.h"
#include "series\data\lists\BatchDataList.h"
#include "graph\datastructures\DArray.h"
#include "graph\datastructures\DArrayList.h"
#include "graph\datastructures\DHashArrayList.h"
#include "graph\nodes\UndirectedNode.h"
#include "graph\edges\UndirectedEdge.h"
#include "series\data\distr\BinnedIntDistr.h"
#include "util\BigInteger.h"
using namespace std;







void testConvert() {
	string s = to_string(11.11);
	cout << s << endl;
	string s1("112");
	string s2("112.22");
	cout << stringToNum<int>(s1) << endl;
	cout << stringToNum<double>(s2) << endl;

}

class A{
public:
	virtual ~A() {}
	virtual void foo() { std::cout << "A\n"; }
};

class B : public A {
public:
	//virtual void foo() { std::cout << "B\n"; }
};

class C {
public:
	//virtual ~C() {}
	virtual void foo() { std::cout << "C\n"; }
};
void test_instanceof()
{
	A a;
	B b;
	C c;

	A *ptr1 = &a;
	A *ptr2 = &b;
	C *ptr3 = &c;



	//ptr1->foo();
	//ptr2->foo();
	//ptr3->foo();
	std::cout << "\n";

	std::cout << "ptr1 is a A: " << instanceof<A>(ptr1) << "\n";
	std::cout << "ptr2 is a A: " << instanceof<A>(ptr2) << "\n";
	std::cout << "ptr3 is a A: " << instanceof<A>(ptr3) << "\n";
	std::cout << "\n";

	std::cout << "ptr1 is a B: " << instanceof<B>(ptr1) << "\n";
	std::cout << "ptr2 is a B: " << instanceof<B>(ptr2) << "\n";
	std::cout << "ptr3 is a B: " << instanceof<B>(ptr3) << "\n";
	std::cout << "\n";

	std::cout << "ptr1 is a C: " << instanceof<C>(ptr1) << "\n";
	std::cout << "ptr2 is a C: " << instanceof<C>(ptr2) << "\n";
	std::cout << "ptr3 is a C: " << instanceof<C>(ptr3) << "\n";
	Node* n1 = new Node(1, NULL);
	Node* n2 = new UndirectedNode(2, NULL);
	std::cout << "n2 is a Node: " << instanceof<Node>(n2) << "\n";
	std::cout << "n2 is a UndirectedNode: " << instanceof<UndirectedNode>(n2) << "\n";
}


void test_vector()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	for (vector<int>::size_type i = 0; i != v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	vector<int>* pv1 = &v1;
	for (vector<int>::size_type i = 0; i != pv1->size(); ++i)
		cout << (*pv1)[i] << " ";
	cout << endl;
	for (vector<int>::size_type i = 0; i != pv1->size(); ++i)
		cout << pv1->at(i) << " ";
	cout << endl;
	cout << v1.size() << endl;
	v1.resize(6);
	cout << v1.size() << endl;
	for (vector<int>::size_type i = 0; i != v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << (v1[5] == 0) << endl;
	cout << (v1.at(5) == 0) << endl;
	cout << "-------------------------------------------" << endl;
	vector<C*>* vc = new vector<C*>();
	cout << vc->size() << endl;
	for (vector<C*>::iterator iter = vc->begin(); iter != vc->end(); iter++)
	{
		cout << (*iter) << endl;
	}
	cout << "-------------------------------------------" << endl;
	vc->resize(4);
	cout << vc->size() << endl;

	vc->at(1) = new C();
	vc->resize(3);
	cout << "-------------------------------------------" << endl;
	for (vector<C*>::iterator iter = vc->begin(); iter != vc->end(); iter++)
	{
		cout <<*iter <<","<<(*iter==NULL )<< endl;
	}
	cout << true<<endl;
}

void testParamter_ParamterList() {
	Parameter *p1 = new DoubleParameter("double",11.11);
	Parameter *p2 = new IntParameter("int",22);
	Parameter *p3 = new LongParameter("long",33L);
	Parameter *p4 = new StringParameter("string","string");
	vector<Parameter*> vp1;
	vector<Parameter*> vp2;
	vector<Parameter*>* vpb;
	vp1.push_back(p1);
	vp1.push_back(p2);
	vp2.push_back(p3);
	vp2.push_back(p4);
	vpb = Parameter::combine(&vp1, &vp2);


	cout << "size of *vpb:" << (*vpb).size() << endl;
	for (vector<Parameter*>::iterator iter = vpb->begin(); iter != vpb->end(); iter++)
	{
		Parameter* p = (*iter);
		cout << p->getName() <<","<<p->getValue()<<","<<p->toString()<< endl;
	}
	ParameterList * pl1 = new ParameterList("pl1", &vp1);
	ParameterList * pl2 = new ParameterList("pl2", &vp2, &vp1);

	cout <<"pl1:" << endl;
	cout << "pl1 of getName:" << pl1->getName()<< endl;
	cout << "pl1 of getDescription:" << pl1->getDescription() << endl;
	cout << "pl1 of getNamePlain:" << pl1->getNamePlain() << endl;
	cout << "pl1 of getParameters:"<<endl;
	for (vector<Parameter*>::iterator iter = pl1->getParameters()->begin(); iter != pl1->getParameters()->end(); iter++)
	{
		Parameter* p = (*iter);
		cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
	}

	cout << "pl2:" << endl;
	cout << "pl2 of getName:" << pl2->getName() << endl;
	cout << "pl2 of getDescription:" << pl2->getDescription() << endl;
	cout << "pl2 of getNamePlain:" << pl2->getNamePlain() << endl;
	cout << "pl2 of getParameters:" << endl;
	for (vector<Parameter*>::iterator iter = pl2->getParameters()->begin(); iter != pl2->getParameters()->end(); iter++)
	{
		Parameter* p = (*iter);
		cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
	}

	cout << "ParameterList static method:" << endl;

	vector<ParameterList> pls;
	pls.push_back(*pl1);
	pls.push_back(*pl2);
	cout << "combineNames:" << ParameterList::combineNames(&pls) << endl;

	vector<Parameter*>* vp3 = ParameterList::combineParameters(&pls);

	cout << "combineParameters:" << endl;
	for (vector<Parameter*>::iterator iter = vp3->begin(); iter != vp3->end(); iter++)
	{
		Parameter* p = (*iter);
		cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
	}

	cout << "parse:------------------------------" << endl;
	vector<string> s;
	s.push_back("5");
	s.push_back("6");
	s.push_back("7");
	s.push_back("s4");
	vector<Parameter*> new_vp = ParameterList::parse(vpb, &s);
	for (vector<Parameter*>::iterator iter = new_vp.begin(); iter != new_vp.end(); iter++)
	{
		Parameter* p = (*iter);
		cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
	}
	



}

void testMathHelper()
{
	string s("123");
	for (int i = 0; i < s.size(); i++)
	{
		int x = s.at(i) - '0';
		string s1(x + "asasa");
		cout << to_string(x)+"asasas" << endl;
	}
}

void testGraphGenerator() {
	GraphGenerator* rg = new RandomGraph(GDS::undirected(), 5, 5);
	rg->show();
}

void testGraph()
{
	Node* n1 = new Node(1, NULL);
	IElement* ie = new UndirectedNode(10,NULL);
	Node* n2 = (Node*)ie;
	cout << n2->getIndex() << endl;
	//cout << "n1's asString:" << n1->asString() << endl;
}

void testGDS()
{
	GDS *gds = new GDS();
	gds->undirected();
}
void testParameterList_ArrayToVector()
{
	Parameter* array[] = { new IntParameter("N", 5), new IntParameter("E", 5) };
	vector<Parameter*>* vp = ParameterList::ArrayToVector(array, 2);
	for (vector<Parameter*>::iterator iter = vp->begin(); iter != vp->end(); iter++)
	{
		Parameter* p = (*iter);
		cout << p->getName() << "," << p->getValue() << "," << p->toString() << endl;
	}
}
void testBatchGenerator()
{
	BatchGenerator *bg = new RandomBatch(1,2,3,4);
	bg->show();
}
void testMetric()
{
	Metric* m1[] = {new DegreeDistributionR(),new UndirectedClusteringCoefficientU()};
	m1[0]->show();
	m1[1]->show();
}
void testDNA_1()
{
	GraphGenerator* gg1 = new RandomGraph(GDS::undirected(), 5, 5);
	BatchGenerator *bg1 = new RandomBatch(0, 0, 2, 1);
	Metric* m11[] = { new DegreeDistributionR(),new UndirectedClusteringCoefficientU() };
	


	vector<IMetric*> m1(m11, m11+ getArrayLen(m11));
	//cout << "len(m11)=" << getArrayLen(m11) << endl;
	//m1[0]->show();
	//m1[1]->show();
	string seriesDir = "data/";
	Series* s = new Series(gg1, bg1, &m1, seriesDir, "series");
	SeriesData *sd = s->generate(2, 2);
	cout << LogSystemTime::_getTime() << endl;
}
void testLog()
{
	cout << Log::errorPrefix<<endl;
	cout << Log::debugPrefix << endl;
	cout << Log::infoPrefix << endl;
	cout << Log::warningPrefix<< endl;
	cout << Log::enumToString(Error) << endl;
	cout << Log::getLogLevel() << endl;
	Log::error("asasas");
	Log::setLogLevel(Debug);
	Log::debug("ddddad");
	Log::infoSep();
	Log::warn("assssssssss");
}

class MyInt
{
public:
	int i;
};
void testSortedList()
{
	//SortedList<MyInt*> *sl = new SortedList<MyInt*>(5);
	//cout << sl->size() << endl;
	BatchDataList* bd = new BatchDataList(5);
	cout << bd->size() << endl;
}
void testDArray()
{
	DArray *da = new DArray();
	da->init(2);
	da->add(new Node(0, NULL));

	da->add(new Node(1, NULL));

	da->add(new Node(2, NULL));
	da->add(new Node(3, NULL));
	da->add(new Node(4, NULL));
	da->add(new Node(0, NULL));
	da->add(new Node(2, NULL));
	cout << "length=" << da->length << endl;
	cout << "size=" << da->size() << endl;
	cout << "maxNodeIndex=" << da->getMaxNodeIndex() << endl;
	for (int i = 0; i < da->length; i++)
	{
		cout << da->lists[i]->asString() << " ";
	}
	cout << endl;

	da->remove(new Node(2, NULL));
	da->remove(new Node(11, NULL));
	da->remove(new Node(4, NULL));
	da->add(new Node(5, NULL));
	da->add(new Node(6, NULL));
	cout << "-----------------------------" << endl;
	for (int i = 0; i < da->length; i++)
	{
		if(da->lists[i] !=NULL)
			cout << da->lists[i]->asString() << " ";
		else cout << "NULL" << " ";
	}
	cout << endl;
	cout << "length=" << da->length << endl;
	cout << "size=" << da->size() << endl;
	cout << "maxNodeIndex=" << da->getMaxNodeIndex() << endl;

	da->remove(new Node(3, NULL));
	cout << "-----------------------------" << endl;
	for (int i = 0; i < da->length; i++)
	{
		if (da->lists[i] != NULL)
			cout << da->lists[i]->asString() << " ";
		else cout << "NULL" << " ";
	}
	cout << endl;
	cout << "length=" << da->length << endl;
	cout << "size=" << da->size() << endl;
	cout << "maxNodeIndex=" << da->getMaxNodeIndex() << endl;

	da->add(new Node(2, NULL));
	da->add(new Node(3, NULL));
	cout << "-----------------------------" << endl;
	for (int i = 0; i < da->length; i++)
	{
		if (da->lists[i] != NULL)
			cout << da->lists[i]->asString() << " ";
		else cout << "NULL" << " ";
	}
	cout << endl;
	cout << "length=" << da->length << endl;
	cout << "size=" << da->size() << endl;
	cout << "maxNodeIndex=" << da->getMaxNodeIndex() << endl;


	da->remove(new Node(5, NULL));
	da->remove(new Node(6, NULL));
	da->remove(new Node(3, NULL));
	cout << "-----------------------------" << endl;
	for (int i = 0; i < da->length; i++)
	{
		if (da->lists[i] != NULL)
			cout << da->lists[i]->asString() << " ";
		else cout << "NULL" << " ";
	}
	cout << endl;
	cout << "length=" << da->length << endl;
	cout << "size=" << da->size() << endl;
	cout << "maxNodeIndex=" << da->getMaxNodeIndex() << endl;
	//DHashArrayList *dhal = new DHashArrayList();
	//dhal->show();
}

void testDArrayList()
{
	DArrayList *da = new DArrayList();
	//da->init(2);
	da->add(new Node(0, NULL));

	da->add(new Node(1, NULL));

	da->add(new Node(2, NULL));
	da->add(new Node(3, NULL));
	da->add(new Node(4, NULL));
	da->add(new Node(0, NULL));
	da->add(new Node(2, NULL));
	//da->lists[0] = new Node(0,NULL);
	//da->lists[1] = new Node(1, NULL);
	//cout << (da->lists[5]==NULL)<< endl;
	//da->show();
	cout << "size=" << da->size() << endl;
	cout << "maxNodeIndex=" << da->getMaxNodeIndex() << endl;
	for (int i = 0; i < da->size(); i++)
	{
		cout << da->lists->at(i)->asString() << " ";
	}
	cout << endl;
	cout << "-----------------------------" << endl;
	da->remove(new Node(3, NULL));
	da->remove(new Node(21, NULL));
	da->add(new Node(3, NULL));
	for (int i = 0; i < da->size(); i++)
	{
		cout << da->lists->at(i)->asString() << " ";
	}
	cout << "size=" << da->size() << endl;
	cout << "maxNodeIndex=" << da->getMaxNodeIndex() << endl;

	cout<<da->contains(new Node(3, NULL))<<endl;
	cout << da->contains(new Node(22, NULL)) << endl;
	//DHashArrayList *dhal = new DHashArrayList();
	//dhal->show();
}
void testDHashArray()
{
	DHashArrayList* dhal = new DHashArrayList();
	Edge* e1 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));
	Edge* e2 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(3, nullptr));
	Edge* e3 = new UndirectedEdge(new UndirectedNode(2, nullptr), new UndirectedNode(3, nullptr));

	Edge* e4 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));
	Edge* e5 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(3, nullptr));
	Edge* e6 = new UndirectedEdge(new UndirectedNode(2, nullptr), new UndirectedNode(3, nullptr));

	Edge* e7 = new UndirectedEdge(new UndirectedNode(3, nullptr), new UndirectedNode(3, nullptr));
	cout << "add:"<<dhal->add(e3) << endl;
	cout << "add:" << dhal->add(e2) << endl;
	cout << "add:" << dhal->add(e1) << endl;

	cout << "add:" << dhal->add(e4) << endl;
	cout << "add:" << dhal->add(e5) << endl;
	cout << "add:" << dhal->add(e6) << endl;

	for (vector<IElement*>::iterator iter = dhal->lists->begin(); iter != dhal->lists->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << "(" << e->getN1()->getIndex() << "," << e->getN2()->getIndex() << ")" << ",";
	}
	cout << endl;
	for (vector<IElement*>::iterator iter = dhal->lists->begin(); iter != dhal->lists->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString()<< ",";
	}
	cout << endl;
	for (set<IElement*>::iterator iter = dhal->sets->begin(); iter != dhal->sets->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
	cout << endl;
	cout <<"-----------------------" <<endl;
	cout << dhal->contains(e3) << endl;
	cout << dhal->contains(e7) << endl;
	cout << "add:" << dhal->add(e7) << endl;
	cout << "-----------------------" << endl;
	for (vector<IElement*>::iterator iter = dhal->lists->begin(); iter != dhal->lists->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
	cout << endl;
	for (set<IElement*>::iterator iter = dhal->sets->begin(); iter != dhal->sets->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
	cout << endl;
	cout<<"删除:"<<dhal->remove(new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(3, nullptr)))<<endl;
	cout << "删除:" << dhal->remove(new UndirectedEdge(new UndirectedNode(13, nullptr), new UndirectedNode(3, nullptr))) << endl;
	cout << endl;
	cout << "-----------------------" << endl;
	for (vector<IElement*>::iterator iter = dhal->lists->begin(); iter != dhal->lists->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
	cout << endl;
	for (set<IElement*>::iterator iter = dhal->sets->begin(); iter != dhal->sets->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
}
void testDArrayList_Edge()
{
	DArrayList *da = new DArrayList();

	Edge* e1 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));
	Edge* e2 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(3, nullptr));
	Edge* e3 = new UndirectedEdge(new UndirectedNode(2, nullptr), new UndirectedNode(3, nullptr));

	Edge* e4 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));
	Edge* e5 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(3, nullptr));
	Edge* e6 = new UndirectedEdge(new UndirectedNode(2, nullptr), new UndirectedNode(3, nullptr));

	Edge* e7 = new UndirectedEdge(new UndirectedNode(3, nullptr), new UndirectedNode(3, nullptr));


	cout << "add:" << da->add(e3) << endl;
	cout << "add:" << da->add(e2) << endl;
	cout << "add:" << da->add(e1) << endl;
	cout << "add:" << da->add(e4) << endl;
	cout << "add:" << da->add(e5) << endl;
	cout << "add:" << da->add(e6) << endl;
	cout << "add:" << da->add(e7) << endl;
	for (vector<IElement*>::iterator iter = da->lists->begin(); iter != da->lists->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
	cout << endl;
	cout << "size=" << da->size() << endl;
	cout << endl;
	cout << "-----------------------" << endl;
	cout << "remove:" << da->remove(e5) << endl;
	cout << "remove:" << da->remove(new UndirectedEdge(new UndirectedNode(13, nullptr), new UndirectedNode(3, nullptr))) << endl;
	for (vector<IElement*>::iterator iter = da->lists->begin(); iter != da->lists->end(); iter++)
	{
		Edge* e = (Edge*)(*iter);
		cout << e->asString() << ",";
	}
	cout << endl;
	cout << "size=" << da->size() << endl;
	cout << "contains:" << da->contains(e5) << endl;
	cout << "contains:" << da->contains(e7) << endl;
	cout << "contains:" << da->contains(new UndirectedEdge(new UndirectedNode(13, nullptr), new UndirectedNode(3, nullptr))) << endl;
}
void test_BinnedIntDistr()
{
	BinnedIntDistr * bid1 = new BinnedIntDistr("bid1");
	BinnedIntDistr * bid2 = new BinnedIntDistr("bid2",*new int(5));
	cout << bid1 ->getIndex(*new int(2))<<endl;
	cout << bid2->getIndex(*new int(11)) << endl;
	cout << bid1->getDistrType() << endl;
	cout << bid2->getDistrType()<< endl;
}
void test_instanceof_UndirectedClusteringCoefficientU()
{
	UndirectedClusteringCoefficientU * uccu = new UndirectedClusteringCoefficientU();

	IBeforeNA* ibna = uccu;
	IDynamicAlgorithm* ida = ibna;
	cout << " instanceof<IDynamicAlgorithm>(uccu)="<<instanceof<IDynamicAlgorithm>(uccu)<< endl;
	cout << " instanceof<IDynamicAlgorithm>(ida)="<<instanceof<IDynamicAlgorithm>(ida) << endl;
	cout <<"instanceof<IDynamicAlgorithm>(ibna)="<<instanceof<IDynamicAlgorithm>(ibna) << endl;
	cout << "instanceof<IBeforeNA>(uccu)="<<instanceof<IBeforeNA>(uccu) << endl;
	cout << "instanceof<IBeforeNA>(ibna)="<<instanceof<IBeforeNA>(ibna) << endl;
}
void testBigInteger()
{
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		BigInteger A;
		BigInteger B;
		BigInteger C = 888;
		cin >> A >> B;
		cout << "A-B:" << A - B << endl;
		cout << "A+B:" << A + B << endl;
		cout << "A*B:" << A*B << endl;
		cout << "A/B:" << A / B << endl;
		cout << "A%B:" << A%B << endl;
		cout << "A.pow(5)" << A.pow(5) << endl;
		A++;
		cout << "A++:" << A << endl;
		A--;
		cout << "A--:" << A << endl;
		cout << "++B:" << ++B << endl;
		cout << "--B:" << --B << endl;
		cout << "C:" << C << endl;
		cout << "C*C:" << C*C << endl;
		cout << "C>A:" << (C>A) << endl;
		BigInteger D = C - BigInteger(111);
		cout << "D:" << D << endl;
		cout << "D>BigInter::ZERO:" << (D>BigInteger::ZERO) << endl;
		cout << "D/2:" << D/2 << endl;
		cout << "D.IntValue()" <<D.IntValue() << endl;
	}
}
void testBatch_add()
{
	map<Node*, NodeAddition*,Node_less>* nodeAdditions = new map<Node*, NodeAddition*,Node_less>();
	Node* n1 = new UndirectedNode(0, nullptr);
	Node* n2 = new UndirectedNode(1, nullptr);
	NodeAddition* na1 = new NodeAddition(n1);
	NodeAddition* na2 = new NodeAddition(n2);

	pair< std::map< Node*, NodeAddition*, Node_less>::iterator, bool > ret1 = nodeAdditions->insert(pair<Node*, NodeAddition*>(n1, na1));
	pair< std::map< Node*, NodeAddition*,Node_less>::iterator, bool > ret2 = nodeAdditions->insert(pair<Node*, NodeAddition*>(n2, na2));

	map<Node*, NodeAddition*>::iterator iter = nodeAdditions->find(na2->getNode());
	cout << ret1.second << endl;
	cout << ret2.second << endl;

	if (iter != nodeAdditions->end())
	{
		cout << "node:"<<iter->first->getIndex() << ",asString=" << iter->second->asString() <<",toString="<< iter->second->toString() << endl;
	}
	else cout << "node NOT Found"<<endl;

	size_t t1 = nodeAdditions->erase(na1->getNode());
	size_t t2 = nodeAdditions->erase(na1->getNode());

	cout << "t1=" <<t1<< endl;
	cout << "t2="<<t2 << endl;
	for (map<Node*, NodeAddition*>::iterator it = nodeAdditions->begin(); it != nodeAdditions->end(); it++)
	{
		cout << "node:" << it->first->getIndex() << ",asString=" << it->second->asString() << ",toString=" << it->second->toString() << endl;
	}

	cout << "-----------------------------------------------" << endl;

	map<Edge*, EdgeAddition*,Edge_less>* edgeAdditions = new map<Edge*, EdgeAddition*, Edge_less>();

	Edge* e1 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));
	Edge* e2 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));

	EdgeAddition* ea1 = new EdgeAddition(e1);
	EdgeAddition* ea2 = new EdgeAddition(e2);
	edgeAdditions->insert(pair<Edge*, EdgeAddition*>(e1, ea1));
	edgeAdditions->insert(pair<Edge*, EdgeAddition*>(e2, ea2));
	
	for (map<Edge*, EdgeAddition*>::iterator it = edgeAdditions->begin(); it != edgeAdditions->end(); it++)
	{
		cout << "edge:" << it->first->asString() << ",asString=" << it->second->asString() << ",toString=" << it->second->toString() << endl;
	}

	map<Edge*, EdgeAddition*>::iterator iter1 = edgeAdditions->find(ea2->getEdge());


	if (iter1 != edgeAdditions->end())
	{
		cout << "find success: edge="<<iter1->first->asString() << ",asString=" << iter1->second->asString() << ",toString="<< iter1->second->toString()<< endl;
	}
	else cout << "edge NOT Found" << endl;

	int et1 = edgeAdditions->erase(ea1->getEdge());
	int et2 = edgeAdditions->erase(ea2->getEdge());
	cout << "et1=" <<et1 << endl;
	cout << "et2=" << et2 << endl;

	for (map<Edge*, EdgeAddition*>::iterator it = edgeAdditions->begin(); it != edgeAdditions->end(); it++)
	{
		cout << "edge:" << it->first->asString() << ",asString=" << it->second->asString() << ",toString=" << it->second->toString() << endl;
	}



	set<Edge*,Edge_less> s1;
	Edge* e3 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));
	Edge* e4 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));
	Edge* e5 = new UndirectedEdge(new UndirectedNode(2, nullptr), new UndirectedNode(3, nullptr));
	s1.insert(e3);
	s1.insert(e4);
	set<Node*, Node_less> s2;
	s2.insert(n1);
	s2.insert(n2);

	cout << "s1.size()="<<s1.size() << endl;
	cout << "s2.size()=" << s2.size() << endl;
}
void test_node_edge_update_set()
{
	Node* n1 = new UndirectedNode(0, nullptr);
	Node* n2 = new UndirectedNode(0, nullptr);
	NodeAddition* na1 = new NodeAddition(n1);
	NodeAddition* na2 = new NodeAddition(n2);
	set < NodeAddition*, NodeUpdate_less>* s1 = new set < NodeAddition*, NodeUpdate_less>();
	pair< std::set<NodeAddition*, NodeUpdate_less>::iterator, bool > p1 = s1->insert(na1);
	pair< std::set<NodeAddition*, NodeUpdate_less>::iterator, bool > p2 = s1->insert(na2);

	cout << p1.second << endl;
	cout << p2.second << endl;
	cout<<"s1.size()="<<s1->size()<<endl;

	Edge* e1 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));
	Edge* e2 = new UndirectedEdge(new UndirectedNode(1, nullptr), new UndirectedNode(2, nullptr));

	EdgeAddition* ea1 = new EdgeAddition(e1);
	EdgeAddition* ea2 = new EdgeAddition(e2);

	set < EdgeAddition*, EdgeUpdate_less>* s2 = new set < EdgeAddition*, EdgeUpdate_less>();

	pair< std::set<EdgeAddition*, EdgeUpdate_less>::iterator, bool > p3 = s2->insert(ea1);
	pair< std::set<EdgeAddition*, EdgeUpdate_less>::iterator, bool > p4 = s2->insert(ea2);

	cout << p3.second << endl;
	cout << p4.second << endl;
	cout << "s2.size()=" << s1->size() << endl;


}
void test_bitset()
{
	string strval("101");
	bitset<32> bint(strval);  // 32 bit 二进制数据
	cout << bint.to_ulong() << endl;
	string ss("aaa/sss/asa1");
	vector<string>* ret = ArrayUtils::split(ss, "/");
	for (size_t i = 0; i < ret->size(); i++)
	{
		cout << ret->at(i)<<endl;
	}
}
int main()
{
	//testParamter_ParamterList();
	
	//testConvert();

	//test_instanceof();
	//test_vector();
	//testMathHelper();
	
	//testGraph();
	//testGDS();
	//testParameterList_ArrayToVector();

	//testGraphGenerator();
	//testBatchGenerator();
	//testMetric();

	//testSortedList();
	//testLog();
	//testDArray();
	//testDArrayList();
	//testDHashArray();
	//testDArrayList_Edge();
	//cout << (numeric_limits<double>::max)() << endl;
	//testDNA_1();
	test_bitset();
	//test_node_edge_update_set();
	//testBatch_add();
	//test_BinnedIntDistr();
	//test_instanceof_UndirectedClusteringCoefficientU();
	//testBigInteger();
	return 0; 
}