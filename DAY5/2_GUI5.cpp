#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window
{
	int handle;
	inline static std::map<int, Window*> this_map;

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&foo, title);

		this_map[handle] = this; 
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:self->lbutton_down();break;
		case WM_KEYDOWN:	self->key_down();	 break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};
//------------------------


class MainFrame : public Window
{
public:
	void lbutton_down() override
	{
		std::cout << "MainFrame lbutton_down\n";
	}
	void key_down() override
	{
		std::cout << "MainFrame key_down\n";
	}
};

int main()
{
	MainFrame w;
	w.create("Hello");

	ec_process_message();
}







