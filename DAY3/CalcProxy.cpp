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

// client 제작자는 
// 이 DLL 에 있는 proxy class 이름을
// 알수도없고, 사용해도 안됩니다. => 약한 결합을 위해서

// DLL 내부에 약속된 함수를 만들고 proxy 객체를 생성합니다.
// => 새로운 proxy dll 을 만들어도 아래 함수는 반드시 제공되어야 합니다.

extern "C" __declspec(dllexport)  // dll 에서 함수 만들때 필요
ICalc* create()
{
	return new Calc;
}

// 새로운 DLL 이 나와도 이름 한개를 약속한다면..
// 그냥 proxy class 이름을 "Calc" 로 약속하면 안되나요 ??
// => new Calc 하려면 "클래스 헤더" 가 필요하고, 클라이언트 자체를 다시 빌드
//    해야 합니다.

// 함수 이름은 "이름"으로 함수를 찾을수 있습니다.!!
// => 다시 빌드 필요 없습니다.
//----------------------------------------
// 빌드 하는 법
// linux 용 c++ 컴파일 : g++
// visual studio 가 제공하는 c++ 컴파일러 : cl.exe 

// 윈도우 시작 버튼 - "developer ...." 입력
// => developer command prompt for vs2022 실행
// => "calcproxy.cpp" 소스가 있는 폴더로 이동후

// => cl calcproxy.cpp /LD     로 빌드하면 "CalcProxy.dll" 생성됩니다.
//							   /LD 옵션이 DLL 로 빌드하라는 옵션
//								경고는 무시하고, "calcproxy.dll" 생성만확인	
