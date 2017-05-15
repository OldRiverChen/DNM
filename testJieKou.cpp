#include "util\Comparator.h"
#include <string>
using namespace std;
class MyNum :public Comparator<MyNum>
{
public:
	int x;
	int y;
public:
	MyNum();
	MyNum(const int x, const int y);
public:
	bool compare(Comparator<MyNum>& o1, Comparator<MyNum>& o2);
	string asString();
};

MyNum::MyNum()
{
	this->x = 0;
	this->y = 0;
}

MyNum::MyNum(const int x, const int y)
{
	this->x = x;
	this->y = y;

}

string MyNum::asString()
{
	string re("(");
	//re.append(to_string(this->x));
	//re.append(",");
	//re.append(to_string(this->y));
	//re.append(")");
	re += "" + to_string(this->x) + "," + to_string(this->y) + ")";
	return re;
}
/*
bool MyNum::compare(Comparator<MyNum>& o1, Comparator<MyNum>& o2)
{

	MyNum n1 = (MyNum)o1;

	return (MyNum)o1.x < o2.x;//ÉýÐòÅÅÁÐ
}*/