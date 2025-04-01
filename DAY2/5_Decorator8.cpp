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

// Stream 에 기능을 추가하는 다양한 Decorator 들
class ZipDecorator : public Stream
{
	Stream* origin; // 핵심 : 외부에 이미 생성된 다양한 Stream 객체
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s) override
	{
		auto s2 = "[( " + s + " ) 압축됨]";
		origin->write(s2);
	}
};


int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs);
	zd.write("hello");	// 1. "hello" 를 압축하는 기능을 수행하고
						// 2. fs.write(압축된데이타) 수행

	EncryptDecorator ed(&zd);
	ed.write("hello");	// 1. "hello" 를 암호화 하고
						// 2. zd.write(암호화된 데이타)
}
