#include "Writer.h"
#include "filesystem\Dir.h"

Writer::Writer(string dir, string filename)
{
	new(this)Writer(dir,filename,false);
}
Writer::Writer(string dir, string filename,bool append)
{
	if (!Dir::isDirExist(dir)) {
		//����·��
		Dir::CreateDir(dir.c_str(), "/");
	}
	//�����ļ�
	if (append)//��׷�ӵķ�ʽ��
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