// 이 프로그램은 32bit(x86) 으로 컴파일 해야 합니다.

// Server1.cpp
#define USING_GUI
#include "cppmaster.h" // IPC 를 위한 함수가 있습니다
					   // => 내부적으로 windows API 사용

class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;

int handler(int code, int a, int b)
{
	printf("메세지 도착 : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b); // 이 함수의 반환 값은 Client 에게 전달됨.
	case 2: return server.Sub(a, b); 
	}
	return 0;
}
int main()
{
	// IPC 서버로 시작
	ec_start_server("Calc",		// 서버 이름, 클라이언트가 서버 검색시 "Calc" 사용
					&handler);  // 클라이언트 접속시 호출될 함수
								// 클라이언트가 전달한 3개의 int 값이 전달됨
}
// 클라이언트가 1, 2, 3 을 전달시 "2+3" 의 결과를 돌려 받게 됩니다.




