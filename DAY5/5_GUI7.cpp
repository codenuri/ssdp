#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>


class Window
{
	inline static std::map<int, Window*> this_map;

	int handle;

	Window* parent = nullptr;          
	std::vector<Window*> child_vector; 
public:
	void add_child(Window* child)
	{
		child->parent = this;

		child_vector.push_back(child);
		ec_add_child(this->handle, child->handle);

		ec_set_window_rect(child->handle, 100, 100, 200, 200); // 자식윈도우 크기변경
	}


	void create(const std::string& title)
	{
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);

		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			self->fire_lbutton_down();
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	// 아래 코드가 "책임의 고리 패턴" 의 핵심
	void fire_lbutton_down()
	{
		// #1. 자신이 먼저 처리
		if (lbutton_down() == true)
			return;

		// #2. 처리 되지 않은 경우 부모에 전달
		if (parent != nullptr)
			parent->fire_lbutton_down();
	}

	virtual bool lbutton_down() { return false; }
	virtual void key_down() {}
};





class MainWindow : public Window
{
public:
	bool lbutton_down() override
	{ 
		std::cout << "MainWindow lbutton_down\n"; 
		return true;
	}
};
class ImageView : public Window
{
public:
	bool lbutton_down() override 
	{ 
		std::cout << "ImageView lbutton_down\n"; 

		// return true;	// 이벤트 처리를 종료해 달라.

		return false;	// 이벤트를 부모윈도우에도 보내 달라.
	}

};


int main()
{
	MainWindow w1;
	w1.create("MainWindow");

	ImageView w2;
	w2.create("ImageView");

	w1.add_child(&w2);

	ec_process_message();

}

// C# WPF 는 위와 같은 이벤트 처리를
// "Bubbling Event" 라는 용어를 사용

// C++ MFC : Command Routing 이라고 하고

// Swift IOS : Responder Chain 이라고 합니다
