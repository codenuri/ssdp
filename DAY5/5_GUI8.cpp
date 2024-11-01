#define USING_GUI
#include "cppmaster.h"
#include <map>


// event 처리를 가상함수로 하면
// => 가상함수 테이블의 오버헤드가 있습니다.
// => 200개 가상함수 * 함수주소크기(8바이트) => 1600 바이트.


class Window;

std::map<int, Window*> this_map;  


template<typename T>
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
//		Window* self = this_map[hwnd];
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->lbutton_down();
					// 함수 호출
					// 가상함수 : dynamic binding (실행시간에 메모리조사)
					// 비가상   : static binding(포인터 타입)
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	void lbutton_down() {}
	void key_down() {}
};

class MainWindow : public Window< MainWindow>
{
public:
	void lbutton_down() 
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

