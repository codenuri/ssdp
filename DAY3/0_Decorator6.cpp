#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>




// 다양한 입출력 Stream 클래스의 사용법이 동일함을 보장하기 위해
// 인터페이스를 설계 합니다.
struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}
	
	// write 외에도, read(), is_open(), close(), flush() 등
	// 기본 입출력 함수의 모양을 약속!!
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
	FileStream fs("a.txt");
	fs.write("hello world");


	// 다양한 입출력 Stream 클래스를 생각해 봅시다.
//	PipeStream ps("my_named_pipe");
//	ps.write("hello, world");


//	NetworkStream ns("100.100.200.200", 4000);
//	ns.write("hello, world");
}