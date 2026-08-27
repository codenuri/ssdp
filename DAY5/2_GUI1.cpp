// 32bit 로 빌드해야 합니다.
// => 위 콤보에서 "x64" 아닌 "x86" 선택

#define USING_GUI
#include "cppmaster.h"


int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
	}
	return 0;
}

int main()
{
	int h1 = ec_make_window(foo,   // 윈도우에서 발생하는 이벤트를 처리할 함수
							"A");  // 캡션 문자열

	int h2 = ec_make_window(foo, "B");

	ec_set_window_rect(h1, 100, 100, 200, 200);

	ec_add_child(h2, h1); // h1 을 h2 의 자식 윈도우로

	ec_set_window_color(h1, Color::redColor());



	// 종료되지 말고, 이벤트발생시 이벤트 처리함수(foo)에 전달해 달라는 것
	ec_process_message();
}

