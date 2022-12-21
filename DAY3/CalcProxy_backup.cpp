// CalcProxy.cpp 
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Proxy 사용자는 DLL 안에 있는 Proxy 의 클래스 이름을 모르고,
// 알 필요도 없고, 사용해도 안됩니다.

// 미리 약속된 함수로 Proxy 객체를 생성해 줍니다.
extern "C" __declspec(dllexport)
ICalc * Create()
{
	return new Calc;
}

// Proxy 가 Update 되어서 새로운 동적 모듈이 나와도
// 반드시 "Create" 는 있어야 합니다.



// 1. "윈도우 시작버튼" 누르세요
// 2. "Visual Studio 폴더" 찾으세요
// 3. 폴더열고 "개발자 명령프롬프트(Develop command prompt) 실행하세요"

// 리눅스 C++ 컴파일러     : g++
// visual C++ 컴파일러이름 : cl.exe 

// D:          => 드라이브 이동
// cd 폴더명    => 폴더 안으로 이동

// cl CalcProxy.cpp /LD /link user32.lib  gdi32.lib kernel32.lib 

// => CalcProxy.dll 생성되면 됩니다.
// => "/LD" 가 "DLL" 로 빌드 옵션입니다.

