#define USING_GUI
#include "cppmaster.h"

#include <map>

class Window;

// 윈도우 번호를 키값으로 this 를 자료구조에 보관하는 기술!!!
// => this를 자료구조에 보관후, static 멤버에서 사용하는 기술은
//    아주 널리 사용됩니다.
std::map<int, Window*> this_map;


class Window
{
	int handle;
public:

	void Create(const char* title)
	{
		handle = ec_make_window(&msg_handler, title);

		this_map[handle] = this;
	}


	static int msg_handler(int hwnd, int msg, int a, int b)
	{
		// 윈도우 번호를 키값으로 저장해둔 this를 꺼내오면
		// static 멤버 함수에서는 모든 멤버 접근 가능합니다.
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		case WM_KEYDOWN:     self->OnKeyDown(); break;  // this->OnKeyDown()
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};



//==================================================
// 위 클래스는 라이브러리 내부 클래스 입니다.
// 이제 라이브러리 사용자는 "Window" 에서 파생 클래스를 만들어서
// 이벤트 처리를 위해 약속된 가상함수를 재정의 합니다.
class MainFrame : public Window
{
public:
	virtual void OnLButtonDown() override
	{
		std::cout << "MainFrame OnLButtonDown" << std::endl;	
	}
};
int main()
{
	MainFrame w;
	w.Create("A");	

	ec_process_message();
}
