#include <iostream>

class Window
{
public:
	void event_loop()
	{
		// event �� �����ؼ� ��ӵ� �Լ��� ȣ���մϴ�.
		click();	// this->click() �Դϴ�.
					// �׷���, ���� this Ÿ���� Window*
					// click �� �����Լ��� �ƴϹǷ� staic binding
					// staic binding �� ������ Ÿ������ ȣ��
	}
	void click() { std::cout << "window click\n"; }
	void keypress() {  }
};

// Window : ���̺귯�� ���� �ڵ�
// ����ڴ� Window �κ��� �Ļ��� Ŭ������ ���� ���

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