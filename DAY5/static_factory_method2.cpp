#include <iostream>

// 생성과정에서 다형성(가상함수 호출)이 필요 하면
// static factory method 를 활용해라!

class Window
{
public:
	Window() { init(); }

	virtual void init() { std::cout << "Window init\n"; }
};

class MainWindow : public Window
{
public:
	void init() override { std::cout << "MainWindow init\n"; }

	static MainWindow* create()
	{
		MainWindow* w = new MainWindow;
		w->init();
		return w;
	}
};

int main()
{
	MainWindow* w = MainWindow::create();
}


