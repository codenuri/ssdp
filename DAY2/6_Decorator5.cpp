#include <iostream>
#include <string>

// 다양한 H/W 에 쓰는 클래스(Stream) 의 사용법을 동일시 하기 위한 인터페이스

struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}

	// write 외에 read(), close(), open(), flush() 등 다양한 IO  위한
	// 함수를 인터페이스로 약산
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
	FileStream fs("a.txt");
	fs.write("hello");

	/*
	NetworkStream ns("100.100.100.100", 3000);
	ns.write("hello");

	PipeStream ps("named_pipe");
	ps.write("hello");
	*/
}
