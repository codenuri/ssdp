#include <iostream>


// CRTP �����
// => "non-virtual" �Լ��� "virtual" ó�� �����ϰ� �ϴ� ���
// => �����Լ��� ������带 ���ֱ� ���� ����ϴ� C++ ���� ����!!(C++ IDioms)
// 

// MS office �� ���鶧 ����� "WTL" �̶�� ���̺귯���� ���.
// => �׿ܿ��� ���� ���� ���̺귯���� ���

template<typename T>
class Window
{
public:
	void event_loop()
	{
//		click(); // this->click() �ε�, this �� Window* �̹Ƿ�
				 // MainWindow �Լ��� ȣ�� ���ϴ°�

		static_cast<T*>(this)->click();
	}
	void click() { std::cout << "window click\n"; }
	void keypress() {}
};

class MainWindow : public Window< MainWindow >
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.event_loop();
}