#include <iostream>

class Window
{
public:
	void event_loop()
	{
		// event 를 조사해서 약속된 함수를 호출합니다.
		click();	// this->click() 입니다.
					// 그런데, 현재 this 타입은 Window*
					// click 이 가상함수가 아니므로 staic binding
					// staic binding 은 포인터 타입으로 호출
	}
	void click() { std::cout << "window click\n"; }
	void keypress() {  }
};

// Window : 라이브러리 내부 코드
// 사용자는 Window 로부터 파생된 클래스를 만들어서 사용

class MainWindow : public Window
{
public:
	void click() { std::cout << "MainWindow click\n"; }
};
int main()
{
	MainWindow w;
	w.event_loop(); // 결과 예측해 보세요
}