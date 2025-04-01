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


	// 파일에 쓸때 암호화 하는 기능이 필요 합니다
	// 최선의 설계를 생각해 봅시다.

	// #1. FileStream 자체에 암호화 기능을 추가하자. 
	// => OCP 위반, 라이브러리 내부 코드를 수정할수 없다.

	// #2. FileStream 의 파생 클래스를 만들고 암호화 기능추가하자.
	// 단점 #1. NetworkStream, PipeStream 도 모두 파생 클래스 만들어야 한다.
	// 단점 #2. 압축 기능도 필요하고, 암호화+압축 기능이 모두 필요하면
	//			다중상속까지 등장하게된다.

	// #3. Decorator 패턴을 사용하면 어떨까 ?

	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs);
	zd.write("hello");	// 1. "hello" 를 압축하는 기능을 수행하고
						// 2. fs.write(압축된데이타) 수행

	EncryptDecorator ed(&zd);
	ed.write("hello");	// 1. "hello" 를 암호화 하고
						// 2. zd.write(암호화된 데이타)
}
