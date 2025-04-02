#include <iostream>



// 클래스 템플릿을 만들때 T 를 사용하지 않은 멤버는
// "템플릿이 아닌 기반 클래스"를 만들어서 제공해라!!
// => "thin template", "template hoisting" 이라는 기술

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