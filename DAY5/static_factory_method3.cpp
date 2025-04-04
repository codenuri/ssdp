#include <iostream>
#include <memory>

class Window
{
public:
	Window() {}

	virtual void init() { std::cout << "Window init\n"; }

	template<typename T>
	static std::unique_ptr<T> create()
	{
		std::unique_ptr<T> w = std::make_unique<T>();
								// ���������� new T �մϴ�.
		w->init();
		return w;
	}
};
class MainWindow : public Window
{
public:
	void init() override { std::cout << "MainWindow init\n"; }
};

int main()
{
	auto w = MainWindow::create<MainWindow>();
}


