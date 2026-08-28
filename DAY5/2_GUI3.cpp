#define USING_GUI
#include "cppmaster.h"




class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&foo, title);
	}

	// 핵심 #1. 아래 함수를 static member 로 하는 이유를 알아야 합니다
	// => C 언어에서 사용하는 "콜백 함수(다른 함수의 인자로 보내는 함수)" 는
	//    인자 모양이 약속되어 있습니다.
	//    ec_make_window(함수) 에서 함수는 인자가 int 4개 이어야 합니다.

	// => 이때 callback 함수로 "멤버 함수를 보낼수 없습니다(this 추가 때문에)"
	// => 그래서 static 멤버 함수로 해야 합니다.

	// => 핵심 : C 언어의 콜백함수를 클래스로 의 멤버 함수로 한다면
	//			"반드시 static 멤버 함수 이어야 한다"

	static int foo(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
		}
		return 0;
	}
};


int main()
{
	Window w;
	w.create("Hello");	

	ec_process_message();
}







