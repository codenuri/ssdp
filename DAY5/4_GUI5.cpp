#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window;

std::map<int, Window*> this_map;


class Window
{
	int handle;

	Window* parent = nullptr;		
	std::vector<Window*> child_vec; 

public:

	void AddChild(Window* child)
	{
		child_vec.push_back(child);
		child->parent = this;

		ec_add_child(this->handle, child->handle);
	}





	void Create(const char* title)
	{
		handle = ec_make_window(&msg_handler, title);

		this_map[handle] = this;
	}


	static int msg_handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->HandleLButtonDown(); break;
		case WM_KEYDOWN:     self->OnKeyDown(); break;
		}
		return 0;
	}

	// 아래 함수가 "책임의 고리" 패턴의 핵심 구현입니다.
	// => chain_of_responsiblity1.cpp 소스의 Handler::Handle 과 동일합니다.

	void HandleLButtonDown()
	{
		// 1. 자신이 먼저 요청의 처리를 시도
		if (OnLButtonDown() == true)	// 요청을 처리한 경우
			return;						// 요청 처리 종료!

		// 2. 요청(LBUTTONDOWN)을 처리하지 않은 경우
		// 부모 윈도우가 있다면 부모 윈도우로 전달
		if (parent != nullptr)
			parent->HandleLButtonDown(); // 주의! OnLButtonDown이 아닙니다.
	
	}




	virtual bool OnLButtonDown() { return false; }
	virtual bool OnKeyDown() { return false; }
};





//==================================================

class MainFrame : public Window
{
public:
	virtual bool OnLButtonDown() override
	{
		std::cout << "MainFrame OnLButtonDown" << std::endl;
		return true;
	}
};

class ImageView : public Window
{
public:
	virtual bool OnLButtonDown() override
	{
		std::cout << "ImageView OnLButtonDown" << std::endl;
		return true;
	}
};


int main()
{
	MainFrame w;
	w.Create("A");

	ImageView iv;
	iv.Create("image view");

	w.AddChild(&iv);

	ec_process_message();
}







