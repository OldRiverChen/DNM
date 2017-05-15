#include "Update.h"

const string Update::EdgeSeparator = "-";
const string Update::TypeDelimiter = "_";

string Update::UpdateTypeToString(UpdateType ut)
{
	string rs("");
	switch (ut)
	{
	case NA:
		rs = "NA";
		break;
	case NR:
		rs = "NR";
		break;
	case EA:
		rs = "EA";
		break;
	case ER:
		rs = "ER";
		break;
	}
	return rs;
}

bool Update::apply(Graph * g)
{
	return this->apply_(g);
}

string Update::asString()
{
	return this->getType()+ Update::TypeDelimiter+this->asString_();
}

string Update::toString()
{
	return this->getType() + ": " + this->asString_();
}
