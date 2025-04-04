#define USING_GUI
#include "cppmaster.h"


#include <map>

class Window;

std::map<int, Window*> this_map;  // <window��ȣ, this> �� �����ϴ� ��


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&event_loop, title);

		// this �� �ڷᱸ���� �����մϴ�.
		this_map[handle] = this;
	}

	static int event_loop(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];
							
		// ���� self �� this �̹Ƿ� 
		// ��� ���(����Ÿ, �Լ�)�� ���� �����մϴ�.
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
//------------------------
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
	Window w;
	w.create("A");

	ec_process_message();
}

