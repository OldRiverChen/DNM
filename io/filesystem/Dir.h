#ifndef _DIR_H_

#define _DIR_H_

#include <string>
#include <iostream>
#include <vector>
#include <direct.h> //_mkdir函数的头文件
#include <io.h>     //_access函数的头文件
#include <fstream>
using namespace std;
/**
* Gives the default storage path for data objects.
*
*/
class Dir 
{
public:
	static const string delimiter;
	static const string tempSuffix;
public:
	static void CreateDir(const char *dir, string delimiter);//创建多级路径，可完整，可相对
	static bool isDirExist(string dir);
	static bool isFileExist(string dir, string filename);

	
public:
	/*
	* RUN data
	*/
	static vector<string>* getRuns(string dir);
	static string getRunDataDir(string dir, int run);

	static string getBatchDataDir(string dir, int run, long long timestamp);

	/*
	* METRIC data
	*/

	static string getMetricDataDir(string dir, string name);



};

#endif