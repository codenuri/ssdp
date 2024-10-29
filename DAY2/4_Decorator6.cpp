// fopen() 등 오래된 함수 사용해도 에러내지 말라는 매크로
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
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
	fs.write("hello");

	// 아래 같은 클래스도 있다고 가정해 봅시다.

	PipeStream ps("my named pipe");
	ps.write("hello");

	NetworkStream ns("100.100.100.100", 4000);
	ns.write("hello");

}
