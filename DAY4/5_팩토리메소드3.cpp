// 5_팩토리메소드
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
	void Draw() { std::cout << "Draw OSXEdit" << std::endl; }
};
//--------------------------------------
// 각 System 별 컨트롤의 이름을 알려주는 구조체를 먼저 설계
struct Window
{
	using Button = WinButton;  // typedef WinButton Button; 의미
	using Edit   = WinEdit;
};

struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;
};

template<typename T>
class Dialog
{
public:
	void init()
	{
		IButton* btn = new typename T::Button;
		IEdit* edit = new  typename T::Edit;

		// btn->Move(); edit->Move();
		btn->Draw();
		edit->Draw();
	}
};
int main(int argc, char** argv)
{
//	Dialog<Window> dlg;
	Dialog<OSX> dlg;
	dlg.init();
}








