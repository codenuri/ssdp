#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window
{
	int handle;
	inline static std::map<int, Window*> this_map;
	Window* parent = nullptr;			
	std::vector<Window*> child_vector;	
public:

	void add_child(Window* child)
	{
		child->parent = this;
		child_vector.push_back(child);
		ec_add_child(this->handle, child->handle);
	}



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
		case WM_LBUTTONDOWN:self->fire_lbutton_down(); break;
		case WM_KEYDOWN:	self->key_down();	 break;
		}
		return 0;
	}

	// Chain Of Responsibiliy 패턴을 구현한 코드 입니다.
	// => 앞에서 배운 "Handler::handle" 과 거의 동일합니다.
	void fire_lbutton_down()
	{
		// #1. 자신이 먼저 이벤트를 처리할 기회 제공
		if (lbutton_down() == true)
			return;

		// #2. 자신이 처리 하지 않은 경우 부모 윈도우가 있다면 전달
		if (parent != nullptr)
			parent->fire_lbutton_down();
	}


	virtual bool lbutton_down() { return false; }
	virtual void key_down() {}
};
//------------------------


class MainFrame : public Window
{
public:
	void lbutton_down() override
	{
		std::cout << "MainFrame lbutton_down\n";
	}
};
class ImageView : public Window
{
public:
	void lbutton_down() override
	{
		std::cout << "ImageView lbutton_down\n";
	}
};
int main()
{
	MainFrame w;
	w.create("MainFrame");

	ImageView iv;
	iv.create("ImageView");

	w.add_child(&iv);

	ec_process_message();
}







