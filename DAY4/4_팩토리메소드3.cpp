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
// 문법 이야기 
#include <memory>

class Dialog
{
public:
	void init()
	{
		auto btn = CreateButton();
		auto edit = CreateEdit();
		btn->Draw();
		edit->Draw();
	}
	virtual std::unique_ptr<IButton> CreateButton() = 0;
	virtual std::unique_ptr<IEdit> CreateEdit() = 0;
};
// 실전에서는 아래처럼 스마트 포인터를 사용하는게 가장 좋습니다.
// => 메모리 해지를 위해서. 
class WinDialog : public Dialog
{
public:
	std::unique_ptr<IButton>  CreateButton() override
	{
		return std::make_unique<WinButton>();
	}
	std::unique_ptr<IEdit> CreateEdit()     override 
	{ 
		return std::make_unique<WinEdit>();
	}
};

int main(int argc, char** argv)
{

}








