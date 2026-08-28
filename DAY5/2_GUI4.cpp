#define USING_GUI
#include "cppmaster.h"




class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&foo, title);
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			lbutton_down(); // 왜 에러일까 ?
			break;

		case WM_KEYDOWN:    
			key_down();     
			break;
		}
		return 0;
	}
	
	virtual void lbutton_down() {}
	virtual void key_down() {}
};

int main()
{
	Window w;
	w.create("Hello");

	ec_process_message();
}







