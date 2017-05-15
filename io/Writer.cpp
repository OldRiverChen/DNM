#include "Writer.h"
#include "filesystem\Dir.h"

Writer::Writer(string dir, string filename)
{
	new(this)Writer(dir,filename,false);
}
Writer::Writer(string dir, string filename,bool append)
{
	if (!Dir::isDirExist(dir)) {
		//创建路径
		Dir::CreateDir(dir.c_str(), "/");
	}
	//创建文件
	if (append)//以追加的方式打开
		writer.open(dir + filename, ios::app);
	else writer.open(dir + filename);

	this->fileExistedBefore = writer.is_open();
}

void Writer::write(string line)
{
	if (this->writer.is_open()) {
		this->writer << line;
	}
}
void Writer::writeln(string line)
{
	if (this->writer.is_open()) {
		this->writer << line+"\n";
	}
}
void Writer::close()
{
	this->writer.close();
}
Writer* Writer::getWriter(string dir, string filename)
{
	return new Writer(dir, filename);
}