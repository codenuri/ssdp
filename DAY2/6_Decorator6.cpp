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

int main()
{


	// 사용자가 파일에 쓸때 암호화 하는 기능을 요구합니다.
	// 최선의 설계는 뭘까요 ?

	// 1. 그냥 사용자 보고 직접 암호화 하게 한다
	// => 매번 직접 하면 불편하다

	// 2. 기반 클래스인 Stream 에 암호화 기능 추가
	// => 요구 사항이 생길때 마다 Stream 변경 ?? - OCP 위반

	// 3. FileStream 의 파생 클래스를 만들어서 암호화 기능 추가
	// class EncrpytFileStream : public FileStream { 여기에 추가};
	// => 모든 Sream 에 필요하고
	// => 암호화 뿐 아니라, 압축 도 필요 하고, 동시에도 필요하다..
	// => 파생 클래스가 너무 많아진다

	// 4. Decorator 패턴을 사용하면 어떨까 ?
	
	FileStream fs("a.txt");
	fs.write("hello");

	EncryptDecorator ed(&fs);
	ed.write("hello"); // 1. 먼저 "hello" 를 암호화 하고
						// 2. fs.write()에 전달

	ZipDecorator zd(&ed);
	zd.write("hello"); // 1. 먼저 "hello" 압축
						// 2. ed.write() 에 전달
}



