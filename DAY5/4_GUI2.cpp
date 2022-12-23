#define USING_GUI
#include "cppmaster.h"

class Window
{
	int handle;
public:
	void Create(const char* title)
	{
		handle = ec_make_window(&msg_handler, title);
	}

	// 핵심 : 아래 함수를 static 멤버 함수로 해야 하는 이유를 반드시 이해 해야 합니다.
	// => ec_make_window 는 C언어 기반 함수 인데, 1번째 인자로 인자가 4개인 함수를
	//    요구 합니다.
	// => 클래스 멤버 함수로 인자가 "int 4개" 인 함수를 만들려면
	//    static 멤버 함수 밖에 없습니다
	// => static 이 아니면 "this" 추가 됩니다.

	static int msg_handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON" << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN" << std::endl; break;
		}
		return 0;
	}

};

int main()
{
	Window w;
	w.Create("A");	// 이순간 윈도우가 생성되어야 합니다.				 
					// 마우스 누르면 "LBUTTON" 나와야 합니다.

	ec_process_message();
}
