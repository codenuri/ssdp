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

int main()
{


	// ���Ͽ� ���� ��ȣȭ �ϴ� ����� �ʿ� �մϴ�
	// �ּ��� ���踦 ������ ���ô�.

	// #1. FileStream ��ü�� ��ȣȭ ����� �߰�����. 
	// => OCP ����, ���̺귯�� ���� �ڵ带 �����Ҽ� ����.

	// #2. FileStream �� �Ļ� Ŭ������ ����� ��ȣȭ ����߰�����.
	// ���� #1. NetworkStream, PipeStream �� ��� �Ļ� Ŭ���� ������ �Ѵ�.
	// ���� #2. ���� ��ɵ� �ʿ��ϰ�, ��ȣȭ+���� ����� ��� �ʿ��ϸ�
	//			���߻�ӱ��� �����ϰԵȴ�.

	// #3. Decorator ������ ����ϸ� ��� ?

	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs);
	zd.write("hello");	// 1. "hello" �� �����ϴ� ����� �����ϰ�
						// 2. fs.write(����ȵ���Ÿ) ����

	EncryptDecorator ed(&zd);
	ed.write("hello");	// 1. "hello" �� ��ȣȭ �ϰ�
						// 2. zd.write(��ȣȭ�� ����Ÿ)
}
