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

// 각 style 의 컨트롤의 이름만 담고 있는 타입 설계
struct Windows
{
	using Button = WinButton; // typedef WinButton Button 입니다.
	using Edit = WinEdit;
};

struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;

	// 수십개의 컨트롤 이름 관리
	// => 이 구조체는 멤버데이타, 함수가 없으므로 오버헤드 없습니다.
	// => 타입이름만 있으므로 컴파일 시간에만 사용
};

template<typename T > 
class Dialog
{
public:
	void init()
	{
		IButton* btn = new typename T::Button;
		IEdit*  edit = new typename T::Edit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};


int main(int argc, char** argv)
{
	Dialog<Windows> dlg1;
	Dialog<OSX> dlg2;
}








