#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

// 핵심 : 자식윈도우 개념을 추가해 봅시다.

class Window
{
	inline static std::map<int, Window*> this_map;

	int handle;

	Window* parent = nullptr;          // 부모윈도우는 한개
	std::vector<Window*> child_vector; // 자식윈도우는 여러개
public:

	void add_child(Window* child)
	{
		child->parent = this;

		child_vector.push_back(child);

		// 실제 GUI의 자식윈도우 부착은 C함수사용
		ec_add_child(this->handle, child->child_vector);
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
	void lbutton_down() override { std::cout << "MainWindow lbutton_down\n"; }
};

class ImageView : public Window
{
public:
	void lbutton_down() override { std::cout << "ImageView lbutton_down\n"; }
};

int main()
{
	MainWindow w1;
	w1.create("MainWindow");

	ImageView w2;
	w2.create("ImageView");

	ec_process_message();

}

