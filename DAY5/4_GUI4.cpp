// GUI1.cpp
// => 32bit(x86) 으로 빌드해야 합니다

// 1. 대부분의 OS 는 GUI 를 만들기 위한 함수 제공(C 언어기능)
// 2. GUI 프로그램을 만드는 가장 기본적인 방법은 "C함수" 사용
// 3. 그런데, C함수 를 직접사용하면 아주 복잡합니다.

#define USING_GUI
#include "cppmaster.h"

class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			lbutton_down();		// 멤버 함수는 "객체.함수()" 가되어야합니다
								// 따라서 이코드는
								// "this->lbutton_down()" 되어야 합니다.
								// 그런데, static 멤버 함수에서는
								// this가 없기때문에 에러
								// error.
								// 해결책은 "다음소스"
			break;

		case WM_KEYDOWN:     key_down();      break;
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

