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
	int h1 = ec_make_window(foo, "A");   

	ec_process_message();
}

