#ifndef _I_COMPARATOR_H_

#define _I_COMPARATOR_H_

//一个接口

/*
模板比较器
若一个类实现了Comparator，就意味着“该类支持排序”
可以用<algorithm>里面的sort方法，具体方法自行百度
*/
template <class T> class Comparator
{
public:
	bool compare(T& o1, T& o2) 
	{
		return false;
	}
};

#endif

