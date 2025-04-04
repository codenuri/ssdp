// static_factory_method1
#include <iostream>

class Window
{
public:
	Window() { init(); }

	virtual void init() {std::cout << "Window init\n";}
};

class MainWindow : public Window
{
public:
	void init() override { std::cout << "MainWindow init\n"; }
};
int main()
{
	MainWindow w;
}

