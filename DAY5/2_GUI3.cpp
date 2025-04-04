// 32bit - "x86" 으로 실행
#define USING_GUI
#include "cppmaster.h"



class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&event_loop, title);
	}

	// 핵심 #1. 아래 함수가 static 이어야 되는 이유를 반드시 알아야 합니다
	// C 언어에서 "함수의 인자로 전달되는 함수(callback 함수)" 를
	// C++ 클래스로 만들때는 반드시 static 멤버함수로 해야 합니다.
	// => this 문제

	static int event_loop(int hwnd, int msg, int a, int b)
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
	w.create("A");

	ec_process_message();
}

