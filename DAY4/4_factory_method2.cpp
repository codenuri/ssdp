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
// 결국 각 OS 별 다이얼로그 박스 클래스는 내부에서 사용하는 객체의 종류만 다를뿐
// 기본 동작은 동일합니다.

class BaseDialog
{
public:
	void init()
	{
		IButton* btn = create_button();
		IEdit* edit = create_edit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}

	// 객체를 생성하기 위한 인터페이스를 제공하고 사용하지만
	// 실제 어떤 타입의 객체를 만들지는 파생 클래스가 결정한다.
	// => 객체의 종류를 파생클래스가 결정하게 한다
	// => template method 와 동일한 모양이지만 
	//    파생 클래스가 "알고리즘 이나 정책" 을 결정하는 것이 아니라
	//    객체의 종류를 결정..
	// "Factory Method" 라는 패턴

	virtual IButton* create_button() = 0;
	virtual IEdit* create_edit() = 0;
};




class WinDialog : public BaseDialog
{
public:
	IButton* create_button() override { return new WinButton; }
	IEdit* create_edit() override { return new WinEdit; }
};

class OSXDialog : public BaseDialog
{
public:
	IButton* create_button() override { return new OSXButton; }
	IEdit* create_edit() override     { return new OSXEdit; }
};

// 디자인 패턴 23개는 "행위/구조/생성" 으로 분류 됩니다.
// 
// 객체를 생성하는 방법에 대한 패턴은 5개 입니다.
// 그중에서 "4개"를 배웠습니다.
// 
// 오직 한개만 만들자				: 싱글톤
// 
// 견본을 먼저 만들고 복사하자		: 프로토타입(prototype)
// 
// 공장을 통해서 만들자			: abstract factory
// 
// 하위 클래스에서 타입을 결정하자 : factory method

// 복잡한 객체를 만드는 방법과 표현하는 방법의 분리 : builder





int main(int argc, char** argv)
{

}








