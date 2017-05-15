#include "Files.h"

string Files::getValuesFilename(string name)
{
	string SUFFIX_VALUE = ".values";
	return name + SUFFIX_VALUE;
}

string Files::getRuntimesFilename(string name)
{
	string SUFFIX_RUNTIME = ".runtimes";
	return name+ SUFFIX_RUNTIME;
}

string Files::getLabelsFilename(string name)
{
	string SUFFIX_LABEL = ".labels";
	return name + SUFFIX_LABEL;
}

string Files::getDistributionFilename(string name, string distrType)
{
	string SUFFIX_DIST_INT;
	if (distrType.compare("BINNED_INT") == 0) {
		SUFFIX_DIST_INT = ".id";
	}
	
	return name + SUFFIX_DIST_INT;
}

string Files::getNodeValueListFilename(string name)
{
	string SUFFIX_NVL = ".nodevaluelist";
	return name + SUFFIX_NVL;
}

string Files::getNodeNodeValueListFilename(string name)
{
	string SUFFIX_NNVL = ".nodenodevaluelist";
	return name + SUFFIX_NNVL;
}

