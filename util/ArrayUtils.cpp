#include "ArrayUtils.h"
const double ArrayUtils::Double_NaN = (numeric_limits<double>::max)();
double ArrayUtils::avgIgnoreNaN(vector<double>*values)
{
	double avg = 0;
	int counter = 0;
	for (vector<double>::iterator iter = values->begin(); iter != values->end(); iter++)
	{
		double v = *iter;
		if (v != Double_NaN) {
			avg += v;
			counter++;
		}
	}
	if (counter == 0) {
		return 0;
	}
	return avg / counter;

}

vector<string>* ArrayUtils::split(string& s, string delim)
{
	vector<string >* ret = new vector<string >();
	size_t last = 0;
	size_t index = s.find_first_of(delim, last);
	while (index != std::string::npos)
	{
		ret->push_back(s.substr(last, index - last));
		last = index + 1;
		index = s.find_first_of(delim, last);
	}
	if (index - last>0)
	{
		ret->push_back(s.substr(last, index - last));
	}
	return ret;
}