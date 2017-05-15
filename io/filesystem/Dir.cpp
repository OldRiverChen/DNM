#include "Dir.h"
const string Dir::delimiter = "/";
const string Dir::tempSuffix = "_";

void Dir::CreateDir(const char * dir, string delimiter)
{
	int m = 0, n;
	string str1, root;

	str1 = dir;
	if (str1.at(str1.size() - 1) != '/')//�����һλ����'/'�������
		str1.append("/");
	m = str1.find(delimiter);
	root = str1.substr(0, m);
	str1 = str1.substr(m + 1, str1.size());
	while (m >= 0)
	{
		n = _access(root.c_str(), 0); //�жϸ�Ŀ¼�Ƿ����
		if (n == -1)
		{
			_mkdir(root.c_str());     //����Ŀ¼
		}
		m = str1.find(delimiter);
		root += delimiter + str1.substr(0, m);//��һ��Ŀ¼
		str1 = str1.substr(m + 1, str1.size());
	}

}

bool Dir::isDirExist(string dir)//�ж�Ŀ¼�Ƿ����
{
	if (dir.at(dir.size() - 1) != '/')//�����һλ����'/'�������
		dir.append("/");
	int n = _access(dir.c_str(), 0); //�жϸ�Ŀ¼�Ƿ����
	if (n == -1)//Ŀ¼������
		return false;
	else return true;
}

bool Dir::isFileExist(string dir, string filename)//�ж��ļ��Ƿ���ڣ�Ҫ����·��
{
	if (dir.at(dir.size() - 1) != '/')//�����һλ����'/'�������
		dir.append("/");
	filename = dir + filename;
	int n = _access(filename.c_str(), 0); //�жϸ��ļ��Ƿ����
	if (n == -1)//�ļ�������
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
	//�ļ���Ϣ      
	struct _finddata_t fileinfo;//�����洢�ļ���Ϣ�Ľṹ��  
	if ((hFile = _findfirst(p.assign(dir).append("/*").c_str(), &fileinfo)) != -1)  //��һ�β���    
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))  //������ҵ������ļ���    
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)  //�����ļ��в���    
				{
					string name(fileinfo.name);
					string prefix_name = name.substr(0, prefix.size());
					if (prefix_name.compare(prefix) == 0)
						files->push_back(fileinfo.name);
				}
			}
			else //������ҵ��Ĳ������ļ���     
			{
				continue;
			}

		} while (_findnext(hFile, &fileinfo) == 0);


		_findclose(hFile); //��������    
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
