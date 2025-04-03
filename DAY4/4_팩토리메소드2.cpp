// 5_팩토리메소드 - 148
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
//--------------------------------------


class Dialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();
		// btn->Move(); edit->Move();
		btn->Draw();
		edit->Draw();
	}
	// factory method
	// => 객체를 생성하기 위한 인터페이스를 정의하고, 사용도 하지만
	// => 어떤 객체를 생성할지는 파생 클래스가 결정한다.

	// => template method 와 동일한 모양이지만
	// => 가상함수가 하는일이 알고리즘의 교체가 아닌 객체를 생성(종류 결정)
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};

class WinDialog : public Dialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit()     override { return new WinEdit; }
};
class OSXDialog : public Dialog
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit()     override { return new OSXEdit; }
};

int main(int argc, char** argv)
{

}








