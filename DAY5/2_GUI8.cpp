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
		ec_add_child(this->handle, child->handle);
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
			self->handle_lbutton_down();
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	// 아래 코드가 chain of responsibility 
	void handle_lbutton_down()
	{
		if (lbutton_down() == true)
			return;

		if (parent != nullptr)				// parent 가 결국 next
			parent->handle_lbutton_down();
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
	//	return true;	// 이벤트 처리를 종료해 달라.
		return false;   // 이벤트를 고리에 따라 계속 전달해달라.
						// 즉, 부모윈도우에도 전달
	}
	
};

int main()
{
	MainWindow w;
	w.create("MainWindow");

	ImageView v;
	v.create("ImageView");

	w.add_child(&v);

	ec_process_message();
}

// 위처럼 자식 윈도우 이벤트를 부모윈도우에도 보내는 기술을

// IOS (cocoa touch) : responder chain 이라고 하고
// WPF : bubbling event

// MFC : command routing 이라고 합니다.

// 모두 "chain of responsibility" 의 응용입니다.
