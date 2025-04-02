#include <iostream>



template<typename T>
class Window
{
public:
	void event_loop()
	{
//		click(); // this->click() 인데, this 가 Window* 이므로
				 // MainWindow 함수를 호출 못하는것

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