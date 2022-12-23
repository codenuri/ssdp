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
int main()
{
	int h1 = ec_make_window(&foo, "A"); 
	int h2 = ec_make_window(&foo, "B");

	// h2 를 h1 윈도우의 자식윈도우로 부착하기
	ec_add_child(h1, h2);


	ec_process_message(); // 프로그램을 종료 하지 말고 
						// 윈도우에서 발생하는 이벤트를 
						// 등록된 함수(foo)로 전달해 달라.
}

