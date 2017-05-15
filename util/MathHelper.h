#ifndef _MATHHELPER_H_

#define _MATHHELPER_H_

class MathHelper
{
	/**
	* Parse a String that is known to contain an integer to an integer
	*
	* @param s
	* @return
	*/
public:
	static int parseInt(const string& s)
	{
		int result = 0;

		for (int i = 0; i < s.size(); i++)
		{
			if (s.at(i) - '0'>9 || s.at(i) - '0' < 0)
				break;
			result = result * 10;
			result += (s.at(i) - '0');
		}

		return result;
	}

};

#endif