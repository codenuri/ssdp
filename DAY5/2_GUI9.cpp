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

	void handle_lbutton_down()
	{
		// preview 贸府

		// #1.何葛俊 刚历 傈崔
		if (parent != nullptr)
			parent->handle_lbutton_down();

		if (preview_lbutton_down() == false)
			return;
		//-------------------------
		// lbutton_down() 贸府

		if (lbutton_down() == true)
			return;

		if (parent != nullptr)	
			parent->handle_lbutton_down();
	}

	virtual bool preview_lbutton_down() { return true; }
	virtual bool lbutton_down() { return false; }
	virtual void key_down() {}
};


class MainWindow : public Window
{
public:
	virtual bool preview_lbutton_down() 
	{ 
		std::cout << "MainWindow preview\n";
		return false; 
	}

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
		return false;   
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


