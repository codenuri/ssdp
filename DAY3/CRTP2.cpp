#include <iostream>

// C++ GUI 라이브러리중 MFC 1.0 에서 아래 처럼 이벤트 처리 함수를 
// "가상함수로 제공"

// 가상함수가 많아지만 가상함수 테이블의 크기가 증가하고
// (모든 가상함수의 주소를 메모리에 보관해야 합니다.)
// 
// 가상함수는 호출시 약간의 오버헤드가 있습니다(객체 타입조사)

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