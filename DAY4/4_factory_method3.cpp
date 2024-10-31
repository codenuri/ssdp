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
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
// factory method 가 아닌 template 버전

// 각 스타일별 컨트롤 이름만 관리하는 타입 설계
struct WinStyle
{
	using Button = WinButton;  // typedef WinButton Button
	using Edit   = WinEdit;

	// 그외 모든 컨트롤의 이름 제공
};
struct OSXStyle
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
		// 이제 T 는 컨트롤의 이름이 아닌
		// 컨트롤의 이름만 관리하는 타입
		// => 즉, 여러 이름을 한개의 타입으로 전달 받은것
		IButton* btn = new typename T::Button; 
		IEdit* edit = new typename  T::Edit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};

int main(int argc, char** argv)
{
	Dialog<OSXStyle> dlg1;
	Dialog<WinStyle> dlg2;

	dlg1.init();
	dlg2.init();
}








