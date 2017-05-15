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
		srand(s);//����rand����������
		Log::debug("initializing Rand with seed " + to_string(seed));
	}
	/*
	Ҫȡ��[a,b)�����������ʹ��(rand() % (b-a))+ a;
	Ҫȡ��[a,b]�����������ʹ��(rand() % (b-a+1))+ a;
	Ҫȡ��(a,b]�����������ʹ��(rand() % (b-a))+ a + 1;
	ͨ�ù�ʽ:a + rand() % n�����е�a����ʼֵ��n�������ķ�Χ��
	Ҫȡ��a��b֮��������������һ�ֱ�ʾ��a + (int)b * rand() / (RAND_MAX + 1)��
	Ҫȡ��0��1֮��ĸ�����������ʹ��rand() / double(RAND_MAX)��

	*/
	static int nextInt(int n)//����һ�������intֵ����ֵ����[0,n)������
	{
		return (rand() % n);
	}
};

#endif

