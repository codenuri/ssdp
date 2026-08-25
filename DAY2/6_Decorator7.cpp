#include <iostream>
#include <string>


struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}

};


class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const std::string& name, const std::string& mode = "wt")
	{
		fopen_s(&file, name.c_str(), mode.c_str());
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s 쓰기\n", s.c_str());
	}
};
// 다양한 Stream 계열 클래스에 기능을 추가하는 클래스
class EncryptDecorator : public Stream
{
	Stream* origin;
public:
	EncryptDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		std::string data = "[ " + s + "] 암호화됨";

		origin->write(data);
	}
};
class ZipDecorator : public Stream
{
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		std::string data = "[ " + s + "] 압축됨";

		origin->write(data);
	}
};


int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fs);
	ed.write("hello");  

	ZipDecorator zd(&ed);
	zd.write("hello"); 
}

// 구글에서 "C# Stream" 검색



