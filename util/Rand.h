#ifndef _RAND_H_

#define _RAND_H_

#include "Util.h"
#include "Log.h"
#include <stdio.h>
#include<stdlib.h>
class Rand
{
public:
	static long long seed;
public:
	static void init(long long s)
	{
		seed = s;
		srand(s);//设置rand函数的种子
		Log::debug("initializing Rand with seed " + to_string(seed));
	}
	/*
	要取得[a,b)的随机整数，使用(rand() % (b-a))+ a;
	要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a;
	要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1;
	通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。
	要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。
	要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。

	*/
	static int nextInt(int n)//生成一个随机的int值，该值介于[0,n)的区间
	{
		return (rand() % n);
	}
};

#endif

