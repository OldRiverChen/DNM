#include "Dir.h"
const string Dir::delimiter = "/";
const string Dir::tempSuffix = "_";

void Dir::CreateDir(const char * dir, string delimiter)
{
	int m = 0, n;
	string str1, root;

	str1 = dir;
	if (str1.at(str1.size() - 1) != '/')//若最后一位不是'/'则添加上
		str1.append("/");
	m = str1.find(delimiter);
	root = str1.substr(0, m);
	str1 = str1.substr(m + 1, str1.size());
	while (m >= 0)
	{
		n = _access(root.c_str(), 0); //判断该目录是否存在
		if (n == -1)
		{
			_mkdir(root.c_str());     //创建目录
		}
		m = str1.find(delimiter);
		root += delimiter + str1.substr(0, m);//下一级目录
		str1 = str1.substr(m + 1, str1.size());
	}

}

bool Dir::isDirExist(string dir)//判断目录是否存在
{
	if (dir.at(dir.size() - 1) != '/')//若最后一位不是'/'则添加上
		dir.append("/");
	int n = _access(dir.c_str(), 0); //判断该目录是否存在
	if (n == -1)//目录不存在
		return false;
	else return true;
}

bool Dir::isFileExist(string dir, string filename)//判断文件是否存在，要加上路径
{
	if (dir.at(dir.size() - 1) != '/')//若最后一位不是'/'则添加上
		dir.append("/");
	filename = dir + filename;
	int n = _access(filename.c_str(), 0); //判断该文件是否存在
	if (n == -1)//文件不存在
		return false;
	else return true;
}

vector<string>* Dir::getRuns(string dir)
{
	string PREFIX_RUNDATA_DIR = "run.";
	string prefix = PREFIX_RUNDATA_DIR;
	vector<string>* files = new vector<string>();
	string p;
	long   hFile = 0;
	//文件信息      
	struct _finddata_t fileinfo;//用来存储文件信息的结构体  
	if ((hFile = _findfirst(p.assign(dir).append("/*").c_str(), &fileinfo)) != -1)  //第一次查找    
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))  //如果查找到的是文件夹    
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)  //进入文件夹查找    
				{
					string name(fileinfo.name);
					string prefix_name = name.substr(0, prefix.size());
					if (prefix_name.compare(prefix) == 0)
						files->push_back(fileinfo.name);
				}
			}
			else //如果查找到的不是是文件夹     
			{
				continue;
			}

		} while (_findnext(hFile, &fileinfo) == 0);


		_findclose(hFile); //结束查找    
	}


	return files;
}

string Dir::getRunDataDir(string dir, int run)
{
	return dir + "run." + to_string(run) + Dir::delimiter;
}

string Dir::getBatchDataDir(string dir, int run, long long timestamp)
{
	return Dir::getRunDataDir(dir, run) + "batch." + to_string(timestamp) + Dir::delimiter;
}

string Dir::getMetricDataDir(string dir, string name)
{
	string PREFIX_METRICDATA_DIR = "metric.";
	return dir + PREFIX_METRICDATA_DIR + name + Dir::delimiter;
}
