#ifndef _FILES_H_

#define _FILES_H_

#include <string>
#include <iostream>
#include <vector>
using namespace std;
/**
* Gives the default storage path for data objects.
*
*/
class Files 
{
public:
	/*
	* VALUES
	*/
	static string getValuesFilename(string name);
	/*
	* RUNTIMES
	*/
	static string getRuntimesFilename(string name);
	/*
	* LABELS
	*/
	static string getLabelsFilename(string name);
	/*
	* DISTRIBUTION
	*/
	static string getDistributionFilename(string name, string distrType);
	/*
	* NODEVALUELISTS
	*/
	static string getNodeValueListFilename(string name);
	/*
	* NODENODEVALUELISTS
	*/
	static string getNodeNodeValueListFilename(string name);

};

#endif