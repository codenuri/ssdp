#include <iostream>

class Window
{
public:
	void event_loop()
	{
		// event �� �����ؼ� ��ӵ� �Լ��� ȣ���մϴ�.
		click();
	}
	void click() { std::cout << "window click\n"; }
	void keypress() {  }
};
class MainWindow : public Window
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.event_loop(); // ��� ������ ������
}