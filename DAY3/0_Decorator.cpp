#include <iostream>
#include <string>
#include <vector>

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


// Decorator

// 모든 Decorator 들의 공통의 기반 클래스가 있다면
// => 모든 Decorator 의 공통의 특징을 한곳에서 관리 가능
// => std::vector<Decorator*> 같은 기술로 Decorator 만 따로 보관 가능

class Decorator : public Stream
{
	Stream* origin;
public:
	Decorator(Stream* s) : origin(s) {}

	Stream* get_origin() { return origin; }
};

// 이제 모든 Decorator들은 "Decorator 클래스로 부터 상속"
class EncryptDecorator : public Decorator
{
public:
	EncryptDecorator(Stream* s) : Decorator(s) {}

	void write(const std::string& s)
	{
		std::string data = "[ " + s + " 암호화됨]";
		get_origin()->write(data);
	}
};
class ZipDecorator : public Decorator
{
public:
	ZipDecorator(Stream* s) : Decorator(s) {}

	void write(const std::string& s)
	{
		std::string data = "[ " + s + " 압축됨]";

		get_origin()->write(data);
	}
};


int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fs);	// fs 객체에 "암호화 기능" 을 추가하는 Decorator
	ed.write("hello");  

	ZipDecorator zd(&ed);		// 기능이 추가된 객체에 다시 기능 추가
	zd.write("hello"); 


// Decorator 들만 따로 보관하고 싶다
//	std::vector<Stream*> v;  // Decorator 뿐 아니라 FileStream 도 보관
	std::vector<Decorator*> v;

	v.push_back(&zd); // ok
	v.push_back(&ed); // ok
//	v.push_back(&fs); // error

}

