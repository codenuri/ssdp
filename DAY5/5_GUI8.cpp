#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window;

std::map<int, Window*> this_map;  


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);

		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->lbutton_down();
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};

class MainWindow : public Window
{
public:
	void lbutton_down() override 
	{ 
		std::cout << "MainWindow lbutton_down\n"; 
	}
};


int main()
{
	MainWindow w1;
	w1.create("MainWindow");

	ec_process_message();

}

