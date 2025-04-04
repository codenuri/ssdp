#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window
{
	int handle;
	inline static std::map<int, Window*> this_map;

	std::vector<Window*> child_vec;
	Window* parent = nullptr;
public:

	void add_child(Window* child)
	{
		child->parent = this;

		child_vec.push_back(child);

		// 이제 C 함수로 실제 자식윈도우로 부착
		ec_add_child(this->handle, child->handle);

		//아래 코드는 테스트를 위해
		ec_set_window_rect(child->handle, 100, 100, 200, 200);
	}




	void create(const std::string& title)
	{
		handle = ec_make_window(&event_loop, title);

		this_map[handle] = this;
	}

	static int event_loop(int hwnd, int msg, int a, int b)
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


	virtual void lbutton_down() {}
	virtual void key_down() {}
};


class MainWindow : public Window
{
public:
	void lbutton_down() override
	{
		std::cout << "MainWindow lbutton_down\n";
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
	MainWindow w;
	w.create("MainWindow");

	ImageView v;
	v.create("ImageView");

	// 부모, 자식 윈도우 개념 추가
	w.add_child(&v);

	ec_process_message();
}

