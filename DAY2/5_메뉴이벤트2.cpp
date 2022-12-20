#include "PopupMenu.h"

// 방법 1. 변하는 것을 가상함수로
// => 각 메뉴 한개당, 클래스 한개(MenuItem 파생 클래스)를 만들어야 한다.
// => 메뉴가 많아지만 클래스가 많아진다.

// => 작은 클래스가 너무 많이 생기는 특징이 있다.

class MenuItem : public BaseMenu
{
	int  id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		// 메뉴 선택시 공통으로 해야할 일이 있다면 
		// 여기서 공통작업을 하고
		// 다시 가상함수 호출.!
		do_command();
	}

	virtual void do_command() {}
};

class FHDMenu : public MenuItem
{
public:
//	FHDMenu(const std::string& title, int id) : MenuItem(title, id) {}

	// 위 생성자는 전달받은 인자를 기반 클래스에 보내기만 합니다.
	// 이 경우, C++11 부터는 아래 처럼하세요
	// "생성자 상속" 이라는 문법
	using MenuItem::MenuItem;  // MenuItem 의 모든 생성자를 상속해 달라.   

	virtual void do_command() override
	{
		std::cout << "FHD로 변경하는 코드" << std::endl;
		_getch();
	}
};

class UHDMenu : public MenuItem
{
public:
	using MenuItem::MenuItem;

	virtual void do_command() override
	{
		std::cout << "UHD로 변경하는 코드" << std::endl;
		_getch();
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add_menu(new FHDMenu("FHD", 11));
	root->add_menu(new UHDMenu("UHD", 12));
	
	root->command();
}





