// fopen() �� ������ �Լ� ����ص� �������� ����� ��ũ��
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
		printf("%s ����\n", s.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	// �Ʒ� ���� Ŭ������ �ִٰ� ������ ���ô�.

	PipeStream ps("my named pipe");
	ps.write("hello");

	NetworkStream ns("100.100.100.100", 4000);
	ns.write("hello");

}