#ifndef _WRITER_H_

#define _WRITER_H_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
/**
* Simple file writer that writes data to a file one line at a time.
*
* @author benni
*
*/
class Writer 
{
public:
	ofstream writer;
	bool fileExistedBefore;
public:
	Writer(string dir, string filename);
	Writer(string dir, string filename, bool append);
public:
	void write(string line);
	void writeln(string line);
	void close();
public:
	static Writer* getWriter(string dir, string filename);

};

#endif