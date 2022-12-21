#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

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
		printf("%s 쓰기\n", s.c_str() );
	}
};

int main()
{
	// C 언어는 자원을 직접 관리해야 하므로 위험하고, 불편합니다.
//	FILE* f = fopen("a.txt", "wt");
//	if (어떤일 발생) return 0;
//	fclose(f);


	// C++은 생성자와 소멸자로 자원관리를 하게 되므로 편리하고, 안전합니다.
	FileStream f("a.txt");

	f.write("hello world");

	// f의 소멸자가 파일을 안전하게 닫아 줍니다.
}