#define USING_GUI
#include "cppmaster.h"
#include <map>

// 클래스 템플릿 만들때
// => "T" 를 사용하지 않는 멤버는
// => 템플릿이 아닌 기반 클래스를 만들고
// => 그곳에서 작성해야 합니다.
// => "Thin Template" 또는 "Template hositing" 이라는 이름을 가지는 기술
//    템플릿 사용시 코드메모리를 줄이기 위해 사용되는 기술

class Window  // 핵심 tempate 아님.
{
protected:
	inline static std::map<int, Window*> this_map;
	int handle;
public:
	void move() {}
	void show() {}
	void set_window_title() {}

	void lbutton_down() {}
	void key_down() {}
};

template<typename T>
class MsgWindow : public Window
{
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
		this_map[handle] = this;
	}
	static int msgproc(int hwnd, int msg, int a, int b)
	{
		T* self = static_cast<T*>(this_map[hwnd]);

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

};

class MainWindow : public MsgWindow< MainWindow>
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

