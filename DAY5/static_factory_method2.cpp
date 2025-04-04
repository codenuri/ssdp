#include <iostream>

// ������������ ������(�����Լ� ȣ��)�� �ʿ� �ϸ�
// static factory method �� Ȱ���ض�!

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


