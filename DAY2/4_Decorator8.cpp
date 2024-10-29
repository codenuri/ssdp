#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s 쓰기\n", s.c_str());
	}
};

class ZipDecorator : public Stream
{
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		auto s2 = "[ " + s + "] 압축됨"; // 압축기능 수행

		origin->write(s2);				// 원본 객체에 전달
	}
};

class EncryptDecorator : public Stream
{
	Stream* origin;
public:
	EncryptDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s)
	{
		auto s2 = "[ " + s + "] 암호화됨"; 

		origin->write(s2);				
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fs);
	ed.write("hello");  // 1. 데이타를 암호화 하고
						// 2. fs.write(암호화된데이타)

	ZipDecorator zd(&ed);
	zd.write("hello");	// 1. 압축하고
						// 2. ed.write(압축된데이타)를 암호화
						// 3. fs.write(압축암호화된데이타)
}

// 구글에서 "C# Stream" 검색후 "이미지 보기" 해보세요
// 
//