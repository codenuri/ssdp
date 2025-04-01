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
		printf("%s ����\n", s.c_str());
	}
};

// Stream �� ����� �߰��ϴ� �پ��� Decorator ��
class ZipDecorator : public Stream
{
	Stream* origin; // �ٽ� : �ܺο� �̹� ������ �پ��� Stream ��ü
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s) override
	{
		auto s2 = "[( " + s + " ) �����]";
		origin->write(s2);
	}
};


int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs);
	zd.write("hello");	// 1. "hello" �� �����ϴ� ����� �����ϰ�
						// 2. fs.write(����ȵ���Ÿ) ����

	EncryptDecorator ed(&zd);
	ed.write("hello");	// 1. "hello" �� ��ȣȭ �ϰ�
						// 2. zd.write(��ȣȭ�� ����Ÿ)
}
