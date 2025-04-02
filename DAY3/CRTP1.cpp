#include <iostream>

class Window
{
public:
	void event_loop()
	{
		// event 를 조사해서 약속된 함수를 호출합니다.
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
	w.event_loop(); // 결과 예측해 보세요
}