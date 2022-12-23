#define USING_GUI
#include "cppmaster.h"

class Window
{
	int handle;
public:
	void Create(const char* title)
	{
		handle = ec_make_window(&msg_handler, title);
	}

	static int msg_handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: OnLButtonDown(); break;
		case WM_KEYDOWN:     OnKeyDown(); break;
		}
		return 0;
	}

	virtual void OnLButtonDown() {}
	virtual void OnKeyDown() {}
};
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
