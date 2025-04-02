#include <iostream>



// Ŭ���� ���ø��� ���鶧 T �� ������� ���� �����
// "���ø��� �ƴ� ��� Ŭ����"�� ���� �����ض�!!
// => "thin template", "template hoisting" �̶�� ���

class Window
{
public:
	void show() {}
	void move() {}

	void click() { std::cout << "window click\n"; }
	void keypress() {}
};

template<typename T>
class EventWindow : public Window
{
public:
	void event_loop()
	{
		static_cast<T*>(this)->click();
	}

};

class MainWindow : public EventWindow< MainWindow >
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};

class ImageView : public EventWindow< ImageView >
{
};

int main()
{
	MainWindow w;
	w.event_loop();
}