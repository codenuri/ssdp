// GUI1.cpp
// => 32bit(x86) 으로 빌드해야 합니다

// 1. 대부분의 OS 는 GUI 를 만들기 위한 함수 제공(C 언어기능)
// 2. GUI 프로그램을 만드는 가장 기본적인 방법은 "C함수" 사용
// 3. 그런데, C함수 를 직접사용하면 아주 복잡합니다.

#define USING_GUI
#include "cppmaster.h"

int foo(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}

class Window
{
	int handle; // 윈도우 번호(핸들)
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(foo, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
	}
};

int main()
{
	Window w;
	w.create("Title");	// 이순간 윈도우가 생성되어야 합니다.

	ec_process_message();

}

