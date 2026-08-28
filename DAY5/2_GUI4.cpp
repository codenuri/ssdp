#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window
{
	int handle;

	// this 를 자료구조 보관하는 아래 기술은 아주 유명합니다.
	// 흔히 "this map" 이라고 부르고
	// C++ 를 사용한 대부분의 GUI 라이브러리 내부에는 이 기술을 사용합니다
	inline static std::map<int, Window*> this_map;

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&foo, title);

		this_map[handle] = this; // 핵심
	}

	// 핵심 #1. 이벤트 처리를 사용자가 변경할수 있게 하기 위해
	// => template method 패턴 사용

	static int foo(int hwnd, int msg, int a, int b)
	{
		// 현재 foo 는 static 멤버 함수이므로 this 가 없어서 다른 멤버 에 접근안됩니다
		// 자료구조에 보관한 this 를 꺼내서 사용하면 모든 멤버 접근 가능합니다.
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			//lbutton_down(); // error. 왜 에러일까 ?
							// this->lbutton_down() 인데..
							// static 멤버 함수는 this 가 없습니다.
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
// 위 설계의 의도
// => 이벤트 처리를 하려면 파생 클래스를 만들어서 약속된 가상함수를 override 한다

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
//	Window w;
	MainFrame w;
	w.create("Hello");

	ec_process_message();
}







