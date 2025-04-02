#include <iostream>


// CRTP 기술로
// => "non-virtual" 함수를 "virtual" 처럼 동작하게 하는 기술
// => 가상함수의 오버헤드를 없애기 위해 사용하는 C++ 만의 패턴!!(C++ IDioms)
// 

// MS office 를 만들때 사용한 "WTL" 이라는 라이브러리가 사용.
// => 그외에도 아주 많은 라이브러리가 사용

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