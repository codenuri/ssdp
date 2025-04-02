// 32bit 로 빌드해야 합니다.
// => 위에 콤보에서 "x64" 가 아닌 "x86" 선택


// Server1.cpp
#define USING_GUI
#include "cppmaster.h" 

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
	// 이 함수의 반환값은 client 에게 전달됩니다.
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b);
	}
	return 0;
}

int main()
{
	// IPC 서버로 시작
	ec_start_server("Calc",		// 서버이름
					&handler);	// 클라이언트 접속시 호출될 함수
								// => 클라이언트는 int 값 3개를 서버에전달
								//    하게 됩니다.
}




