#include <iostream>
#include <string>

// 모든 Stream 의 공통의 인터페이스
struct Stream
{
	virtual void write(const std::string& s) = 0;

	virtual ~Stream() {}

	// 그외에 read(), flush(), is_open() 등의 함수를 여기서 약속
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const std::string& name, const std::string& mode = "wt")
	{
		fopen_s(&file, name.c_str(), mode.c_str() );
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

	NetworkStream ns("100.100.100.100", 3000);
	ns.write("hello");

	PipeStream ps("named_pipe");
	ps.write("hello");
}
