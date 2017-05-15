#ifndef _UTIL_H_

#define _UTIL_H_


#include <stdio.h>  
#include <time.h>  
#include <windows.h>
#include <string>
#include <sstream> 
#include <vector>
#include "..\metrics\IMetric.h"
using namespace std;
class LogSystemTime
{

	static int gettimeofday(struct timeval *tp, void *tzp)
	{
		time_t clock;
		struct tm tm;
		SYSTEMTIME wtm;
		GetLocalTime(&wtm);
		tm.tm_year = wtm.wYear - 1900;
		tm.tm_mon = wtm.wMonth - 1;
		tm.tm_mday = wtm.wDay;
		tm.tm_hour = wtm.wHour;
		tm.tm_min = wtm.wMinute;
		tm.tm_sec = wtm.wSecond;
		tm.tm_isdst = -1;
		clock = mktime(&tm);
		tp->tv_sec = clock;
		tp->tv_usec = wtm.wMilliseconds * 1000;
		return (0);
	}
public:
	static long long _getTime(void)
	{
		struct timeval  now;
		gettimeofday(&now, NULL);
		long long a = now.tv_sec;
		long long b = now.tv_usec;
		return a * 1000 + b / 1000;
	}

};




//���߷����򹤾���

/*��ȡ���鳤��*/
template<class T> 
int getArrayLen(T& array)

{
	if(array!=NULL)
		return (sizeof(array) / sizeof(array[0]));
	else return 0;
}

//ģ�庯������string���ͱ���ת��Ϊ���õ���ֵ���ͣ��˷��������ձ������ԣ�  
template <class Type>
Type stringToNum(const string& str)
{
	istringstream iss(str);
	Type num;
	if(iss >> num)
		return num;
	cout << "invalid string to num !" << endl;
	exit(1);
}

/*�ж������� �൱��java��instanceof
 ���ǻ���(Base)һ��Ҫ��virtual����
*/
template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
	const Base* b = dynamic_cast<const Base*>(ptr);
	bool f1 = (b != nullptr);
	return f1;
}



//����Double.NAN





#endif