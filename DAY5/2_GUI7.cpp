#define USING_GUI
#include "cppmaster.h"
#include <map>

// 아래 코드는 "자식 윈도우를 만들기 전의 코드" 입니다.

// 윈도우 이벤트 처리기술에 대한 구현 방식
// #1. 가상함수 기반 - template method 패턴 : GUI4.cpp 참고. 예전 스타일
// => 발생하는 이벤트를 수백개가 됩니다. 
// => 모두 가상함수로 하면 "가상함수 테이블이 커집니다."
// => 추가로 호출의 오버헤드도 약간 있습니다.

// #2. 

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
		case WM_LBUTTONDOWN:
			self->lbutton_down();
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	void lbutton_down()  { std::cout << "Window lbutton_down\n"; }
	void key_down() {}
};

class MainFrame : public Window
{
public:
	void lbutton_down() 
	{
		std::cout << "MainFrame lbutton_down\n";
	}
	void key_down()
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







