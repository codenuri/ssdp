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
//-----------------
// 추상 팩토리 패턴(abstract factory)
// => "제품의 군" 을 만들기 위한 인터페이스를 정의 하지만
// => 어떤 제품의 군을 만들지는 파생 클래스가 결정한다.
// => 교체 가능한 공장을 설계 하자는 의도!!

// 흔히 "Factory" 라는 용어를 사용하지만, 
// 디자인 패턴의 분류에 "Factory 패턴"은 없습니다. 
// "abstract factory" 가 있습니다.

struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
	virtual ~IFactor() {}
};





//  style 별로 각 콘트롤을 만드는 공장
class WinFactory : public IFactory
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
	virtual ~WinFactory() {}
};
class OSXFactory : public IFactory
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit() { return new OSXEdit; }
	virtual ~OSXFactory() {}
};


int main(int argc, char** argv)
{
	// 공장도 인터페이스를 먼저 설계해서 교체 가능한 공장을 만들자
	// => 추상 팩토리 패턴!!
	IFactory* factory;

	if (strcmp(argv[0], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// 컨트롤이 필요하면 공장을 사용해서 생성
	IButton* btn = factory->CreateButton();
	btn->Draw();
}











