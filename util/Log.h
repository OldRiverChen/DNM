#ifndef _LOG_H_

#define _LOG_H_
#include <string>
#include <iostream> 
using namespace std;
// log levels
enum LogLevel
{
	Off, Error, Warn, Info, Debug
};
class Log
{
public:
	// output prefixes
	static const string debugPrefix;
	static const string warningPrefix;
	static const string errorPrefix;
	static const string infoPrefix;
private:
	static LogLevel loglevel;

public:
	static string getLogLevel()
	{
		return enumToString(loglevel);
	}
	static void setLogLevel(LogLevel ll)
	{
		loglevel = ll;
	}
	static void error(string msg)
	{
		if (loglevel == Error || loglevel == Warn || loglevel == Info || loglevel == Debug)
			cout << errorPrefix<<replace(msg,"\n","\n error : ") << endl;
	}
	static void warn(string msg)
	{
		if (loglevel == Warn || loglevel == Info )
			print(msg, warningPrefix);

	}
	static void info(string msg)
	{
		if ( loglevel == Info || loglevel == Debug)
			print(msg, infoPrefix+" ");
	}
	static void infoSep()
	{
		if (loglevel == Info || loglevel == Debug)
			print("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~", "");
	}
	static void debug(string msg)
	{
		if (loglevel == Debug)
			print(msg, debugPrefix);
	}
protected:
	static void print(string msg, string pre)
	{
		cout << pre << replace(msg,"\n", "\n"+pre) << endl;
	}

public:
	static string enumToString(LogLevel ll);
	static string replace(const string& str, const string& src, const string& dest)
	{
		string ret;

		string::size_type pos_begin = 0;
		string::size_type pos = str.find(src);
		while (pos != string::npos)
		{
			//cout << "replacexxx:" << pos_begin << " " << pos << "\n";
			ret.append(str.data() + pos_begin, pos - pos_begin);
			ret += dest;
			pos_begin = pos + 1;
			pos = str.find(src, pos_begin);
		}
		if (pos_begin < str.length())
		{
			ret.append(str.begin() + pos_begin, str.end());
		}
		return ret;
	}

};

#endif