#include "NodeValueList.h"
#include <limits>
double NodeValueList::emptyValue = (numeric_limits<double>::max)();

NodeValueList::NodeValueList(string name, int size) : Data(name)
{
	this->values = new vector<double>();
	for (int i = 0; i < size; i++)
		this->values->push_back(NodeValueList::emptyValue);
}

NodeValueList::NodeValueList(string name, vector<double>* values) :Data(name)
{
	this->values = values;
}

NodeValueList::NodeValueList(string name, vector<long>* values)
{
	new(this)NodeValueList(name, values->size());
	for (int i = 0; i < values->size(); i++)
		this->values->at(i) = values->at(i);
}

vector<double>* NodeValueList::getValues()
{
	return this->values;
}

void NodeValueList::setValue(int index, double value)
{
	if (index >= this->values->size())
	{
		for (int i = this->values->size(); i < index + 1; i++)
			this->values->push_back(emptyValue);
	}
	this->values->at(index) = value;
}

void NodeValueList::write(string dir, string filename)
{
	Log::debug("WRITING NodeValueList '" + filename + "' to " + dir);
	if (this->values == NULL)
	{
		cout << "no values for nodevaluelist \""<<Data::getName()<<"\" set to be written to "<<dir<< endl;
		exit(1);
	}
	Writer* w = Writer::getWriter(dir, filename);
	for (int i = 0; i < this->values->size(); i++) {
		string DATA_DELIMITER = "\t";
		w->writeln(to_string(i) + DATA_DELIMITER + to_string(this->values->at(i)));
	}
	w->close();
}



