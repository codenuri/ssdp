// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"
// 
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
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b);  // 이함수 반환값은 클라이언트에 전달됩니다.
	}
	return 0;
}
int main()
{
	// IPC 서버로 시작
	ec_start_server("Calc",    // 서버 이름. 
					&handler); // 클라이언트 접속시 이함수가 호출됩니다.
							   // 클라이언트는 서버에게 int 값 3개를 전달
							   // 하게 됩니다.
}




