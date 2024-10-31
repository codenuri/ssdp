// 3_추상팩토리 - 147
#include <iostream>

// QT 라이브러리 : 프로그램실행시 look and feel 변경 기능있습니다.
// 



// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};

int main(int argc, char** argv)
{
	IButton* btn; // 모든 종류 버튼의 기반 클래스

	if (strcmp(argv[1], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;

	// 그런데, 프로그램에서 버튼은 한개만 만들게 될까 ?
	// => 매	번 위처럼 코딩할수는 없다.
	// => 공장을 통해서 만들면 되지 않을까 ?
}








