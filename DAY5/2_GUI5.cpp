#define USING_GUI
#include "cppmaster.h"


#include <map>

class Window;

std::map<int, Window*> this_map;  // <window번호, this> 를 보관하는 맵


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&event_loop, title);

		// this 를 자료구조에 보관합니다.
		this_map[handle] = this;
	}

	static int event_loop(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];
							
		// 이제 self 가 this 이므로 
		// 모든 멤버(데이타, 함수)에 접근 가능합니다.
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

