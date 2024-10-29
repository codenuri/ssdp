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

int main()
{
	// 파일에 쓸때 "암호화" 하는 기능이 필요 합니다.
	// 라이브러리 설계자 입장에서 "최선의 디자인"을 생각해 봅시다.

	// #1. FileStream 의 파생 클래스인 "EncrpytStream" 을 만들자
	// 단점 1. FileStream 뿐 아니라 NetworkStream 의 파생 클래스도 필요
	// 단점 2. 암호화 뿐 아니라 압축도 필요 하다면 다시 파생클래스 필요
	//        => 암호화 압축이 동시에 필요하면 다시 상속(다중상속) 필요

	// #2. 기반 클래스인 Stream 에 "암호화 기능" 추가
	// 단점 : 필요없는 Stream 에도 모두 물려 받게 되고
	//        기반 클래스의 변경은 모든 소스를 다시 컴파일
	//        그리고, OCP 위반
	//        새로운 요구조건이 생길때마다 "기존 코드 수정"

	// #3. Decorator 패턴을 사용하면 어떨까 ?

	FileStream fs("a.txt");
	fs.write("hello");
	
	EncrpytDecorator ed(&fs);
	ed.write("hello");  // 1. 데이타를 암호화 하고
						// 2. fs.write(암호화된데이타)

	ZipDecorator zd(&ed);
	zd.write("hello");	// 1. 압축하고
						// 2. ed.write(압축된데이타)를 암호화
						// 3. fs.write(압축암호화된데이타)
}
