#define USING_GUI
#include "cppmaster.h"
#include <map>

// this 도 자료구조에 보관했다가 사용가능합니다.

class Window;

std::map<int, Window*> this_map;  // [ 윈도우 번호, Window* ]


class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);

		// 핵심 : this 를 보관했다가 static 멤버함수에서 사용할수 있게
		this_map[handle] = this; 
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd]; 

		// 이제 self(this)만 있으면 static 멤버 함수에서도
		// 모든 멤버 접근가능합니다.

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


int main()
{
	Window w;
	w.create("Title");

	ec_process_message();

}

