#include <iostream>

// C++ GUI ���̺귯���� MFC 1.0 ���� �Ʒ� ó�� �̺�Ʈ ó�� �Լ��� 
// "�����Լ��� ����"

// �����Լ��� �������� �����Լ� ���̺��� ũ�Ⱑ �����ϰ�
// (��� �����Լ��� �ּҸ� �޸𸮿� �����ؾ� �մϴ�.)
// 
// �����Լ��� ȣ��� �ణ�� ������尡 �ֽ��ϴ�(��ü Ÿ������)

class Window
{
public:
	void event_loop()
	{
		click();	
	}
	virtual void click() { std::cout << "window click\n"; }
	virtual void keypress() {}
};


class MainWindow : public Window
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.event_loop(); 
}