// GUI1.cpp
// => 32bit(x86) 으로 빌드해야 합니다

// 1. 대부분의 OS 는 GUI 를 만들기 위한 함수 제공(C 언어기능)
// 2. GUI 프로그램을 만드는 가장 기본적인 방법은 "C함수" 사용
// 3. 그런데, C함수 를 직접사용하면 아주 복잡합니다.

#define USING_GUI
#include "cppmaster.h"


class Window
{
	int handle; 
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
	}

	// 핵심 : 왜 아래 함수가 static 이어야 하는지 이해 해야 합니다.
	// => ec_make_window() 의 1번째 인자는 인자가 4개인 함수주소 요구
	// => 하지만 일반 멤버 함수는 this 가 추가되므로 5개가 됩니다.
	// => static 이어야만 인자가 4개
	// => 결론, "C언의 call back 함수"를 클래스로 만들때는 static 이어야한다.

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
		}
		return 0;
	}

};

int main()
{
	Window w;
	w.create("Title");	

	ec_process_message();

}

