#include "NodeNodeValueList.h"
#include <limits>
double NodeNodeValueList::emptyValue = (numeric_limits<double>::max)();



NodeNodeValueList::NodeNodeValueList(string name, int size) :Data(name)
{
	this->values = new vector<vector<double>*>();
	for (int i = 0; i < size; i++)
	{
		vector<double>* va1 = new vector<double>();
		for (int j = 0; j < size; j++)
		{
			va1->push_back(NodeNodeValueList::emptyValue);
		}
		values->push_back(va1);
	}
}

NodeNodeValueList::NodeNodeValueList(string name, vector<vector<double>*>* values):Data(name)
{
	this->values = values;
}

vector<vector<double>*>* NodeNodeValueList::getValue()
{
	return this->values;
}

void NodeNodeValueList::write(string dir, string filename)
{
	Log::debug("WRITING NodeNodeValueList '" + filename + "' to " + dir);
	if (this->values == NULL)
	{
		cout << "no values for nodenodevaluelist \"" << Data::getName() << "\" set to be written to " << dir << endl;
		exit(1);
	}
	Writer* w = Writer::getWriter(dir, filename);
	for (int i = 0; i < this->values->size(); i++) {
		string DATA_DELIMITER = "\t";
		string line = to_string(i) + DATA_DELIMITER;
		for (int j = 0; j < this->values->at(i)->size(); j++)
		{
			line += to_string(this->values->at(i)->at(j)) + DATA_DELIMITER;
		}
		w->writeln(line);
	}
	w->close();
}
