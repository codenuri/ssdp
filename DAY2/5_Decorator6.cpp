#include <iostream>
#include <string>

// ��� Stream �� ������ �������̽�
struct Stream
{
	virtual void write(const std::string& s) = 0;

	virtual ~Stream() {}

	// �׿ܿ� read(), flush(), is_open() ���� �Լ��� ���⼭ ���
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
		printf("%s ����\n", s.c_str());
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
