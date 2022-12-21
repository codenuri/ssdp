#define _CRT_SECURE_NO_WARNINGS
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

int main()
{


	// 파일에 쓸때 암호화 해서 쓰는 기능을 요구할때..
	// 최선의 디자인을 생각해 봅시다.

	// 방법 1. 데이터를 먼저 암호화 하고 write 하자.
	// => 여러번 해야 한다면 매번 암호화 코드를 작성해야 하므로 불편하다.

	// 방법 2. FileStream 의 파생 클래스를 만들어서 encrypt_write()
	//		   멤버 함수를 제공하자.
	// => PipeStream, NetworkStream 등 모든 클래스에도 동일한 작업을해야합니다
	// => 암호화 방법은 같은데,, 여러곳에 있게 됩니다.


	// 방법 3. 모든 스트림 클래스의 기반 클래스인 Stream 에 추가 하자.
	// => 암호화 말고, 압축해서 쓰는 기능이 필요하다면 
	//    또 Stream 에 추가 ???  
	// => 요구 사항이 생길때 마다 Stream 변경. OCP 를 만족할수 없다!!

	// 방법 4. Decorator 패턴을 사용하자..

	FileStream fs("a.txt");
	fs.write("hello world"); // 파일에 직접 쓰기

	EncryptDecorator ed(&fs);
	ed.write("hello world"); // 1. 데이타를 암호화 하는 기능 수행후
							 // 2. 원래 기능 fs.write() 수행

	ZipDecorator zd(&ed);
	zd.write("hello world"); // 1. 압축 기능 수행
							 // 2. ed.write() 수행
}