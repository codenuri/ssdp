#define USING_GUI
#include "cppmaster.h"
// 이벤트 처리 함수는 반드시 인자 모양이 int 타입 4개 이어야 합니다.
int foo(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
	}
	return 0;
}
// C 언어의 API(함수) 를 객체지향 라이브러리로 만들어 봅시다
class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&foo, title);
	}
};


int main()
{
	Window w;
	w.create("Hello");	// 이순간 윈도우가 생성되어야 합니다.

	ec_process_message();
}







