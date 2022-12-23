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

	int msg_handler(int hwnd, int msg, int a, int b)
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
