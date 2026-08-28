#define USING_GUI
#include "cppmaster.h"
#include <map>

// 윈도우 이벤트 처리기술에 대한 구현 방식
// #1. 가상함수 기반 - template method 패턴 : GUI4.cpp 참고. 예전 스타일
// #2. 

template<typename T> 
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
//		Window* self = this_map[hwnd];
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->lbutton_down(); // self 가 Window* 라면 Window::lbutton_down() 호출
								  //        MainFrame* 라면 MainFrame::lbutton_down()
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	void lbutton_down() { std::cout << "Window lbutton_down\n"; }
	void key_down() {}
};

class MainFrame : public Window<MainFrame>
{
public:
	void lbutton_down() { std::cout << "MainFrame lbutton_down\n"; }
};

int main()
{
	MainFrame w;
	w.create("Hello");

	ec_process_message();
}







