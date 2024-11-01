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
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); ; }
};

// DLL 안에 있는 Proxy 클래스 이름은
// 클라이언트 개발자가 알수 없고, 알 필요도 없고, 사용해도 안됩니다.(강한결합)
// DLL 내부에 약속된 함수를 만들고, 그 안에서 객체를 생성해야 합니다.

extern "C" __declspec(dllexport)  // DLL 안에 함수 만들때 필요
ICalc* create()
{
	return new Calc;
}

// 새로운 Proxy DLL 을 만들때도 규칙("create" 함수가 있어야 한다는)
// 을 지켜야 합니다.

// C++ 컴파일러
// linux 용 : g++
// windows 용 visual studio 가 가진 컴파일러 : cl.exe

// 윈도우 시작버튼
// => 검색에서 "developer command ...."

// => 현재 소스가 있는 곳으로 이동
// cd \     => C:\ 로이동
// cd 폴더

// cl CalcProxy.cpp /LD     => /LD 가 DLL 로 빌드하라는 옵션입니다.