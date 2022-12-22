// 3_추상팩토리 - 147
#include <iostream>

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
	// 각 System 별 컨트롤 클래스에 대한
	// 공통의 기반 클래스가 필요 하다.
	IButton* btn;

	if (strcmp(argv[0], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;

	// 그런데, 프로그램에서 "버튼을 한번만 만들게 될까 ????"
	// 컨트롤을 만들때 마다 위처럼 조사할수는 없습니다.
}








