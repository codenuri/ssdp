// 32bit - "x86" 으로 실행
#define USING_GUI
#include "cppmaster.h"



class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&event_loop, title);
	}

	// 아래 코드는 왜?? 에러가 발생할까요 ??
	// 해결책은 뭘까요 ?
	// => 다음소스에서 해결
	static int event_loop(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: 
	//		x = 0;   // this->x = 0
			lbutton_down();		// this->lbutton_down(); 인데
								// 현재는 static 멤버 함수안에 있으므로
								// this 가 없습니다.
			break;

		case WM_KEYDOWN:     key_down(); break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};



int main()
{
	Window w;
	w.create("A");

	ec_process_message();
}

