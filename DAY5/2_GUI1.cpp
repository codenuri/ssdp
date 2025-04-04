// 32bit - "x86" 으로 실행
#define USING_GUI
#include "cppmaster.h"

// event 처리함수는 인자가 반드시 int 4개 이어야 합니다.
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
	int h1 = ec_make_window(foo, "A"); 
	int h2 = ec_make_window(foo, "B");

	// 자식 윈도우로 부착
	ec_add_child(h1, h2); // h2를 h1 의 자식 윈도우로 부착

	ec_set_window_rect(h2, 100, 100, 200, 200);


	ec_process_message(); // 종료 되지 말고 event 를 처리해 달라는것
}

