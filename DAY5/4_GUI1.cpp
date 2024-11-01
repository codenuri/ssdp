// GUI1.cpp
// => 32bit(x86) 으로 빌드해야 합니다

// 1. 대부분의 OS 는 GUI 를 만들기 위한 함수 제공(C 언어기능)
// 2. GUI 프로그램을 만드는 가장 기본적인 방법은 "C함수" 사용
// 3. 그런데, C함수 를 직접사용하면 아주 복잡합니다.

#define USING_GUI
#include "cppmaster.h"


// event 처리함수 조건 : 인자가 int 타입 4개  
int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(foo, "A"); 
	int h2 = ec_make_window(foo, "B");

	ec_set_window_rect(h1, 0, 0, 400, 400);

	ec_add_child(h1, h2); // h2 윈도우를 h1 의 자식으로

	ec_set_window_rect(h2, 100, 100, 200, 200);



	ec_process_message();
		// => 종료되지 말고, 윈도우에서 발생하는
		//    이벤트를 처리해 달라.
}

