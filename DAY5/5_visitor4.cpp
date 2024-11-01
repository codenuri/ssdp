#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list		: 모든 요소가 같은 타입.      선형적인 구조
// 메뉴예제  : 모든 요소가 같은 타입 아님. Tree 구조


class PopupMenu; // 전방 선언
class MenuItem;  

// 메뉴 방문자 인터페이스
struct IMenuVisitor
{
	virtual void visit(PopupMenu* m) = 0;
	virtual void visit(MenuItem* m) = 0;

	virtual ~IMenuVisitor() {}
};







class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;

	virtual void accept(IMenuVisitor* visitor) = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}


	void accept(IMenuVisitor* visitor)
	{
		// 자신만 방문자에 전달 하면 됩니다.
		// => 하위 메뉴 없음
		visitor->visit(this);
	}
};







class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:

	// 팝업메뉴에 방문자가 방문 할때 - 핵심.. 제일 중요!!
	void accept(IMenuVisitor* visitor)
	{
		// #1. 자신을 방문자에 전달
		visitor->visit(this);

		// #2. 자신이 가진 하위 메뉴 전달 하면 안됩니다.
		// => 아래 처럼하면 "직계자식메뉴만 전달됩니다."
		/*
		for (auto m : v)
			visitor->visit(m);
		*/

		// #2. 방문자를 하위메뉴에 전달해야 합니다.
		// => 방문자가 하위 메뉴를 다시 방문
		for (auto m : v)
			m->accept(visitor);

	}





	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command();
		}

	}

};

// 위 코드는 이제 "메뉴에 방문자 패턴을 사용할수 있도록 설계"
// 되었습니다.

// 이제 다양한 방문자(한개요소에 대한연산정의)를 만들면 됩니다.

class TitleDecorateVisitor : public IMenuVisitor
{
	std::string popup_deco;
	std::string item_deco;
public:
	TitleDecorateVisitor(const std::string& s1, const std::string& s2)
		: popup_deco(s1), item_deco(s2) {}

	void visit(PopupMenu* m) override 
	{
		auto s = m->get_title();

		s = s + popup_deco;

		m->set_title(s);
	}
	void visit(MenuItem* m) override 
	{
		auto s = m->get_title();

		s = s + item_deco;

		m->set_title(s);
	}
};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD",  11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	
	TitleDecorateVisitor tdv(" >", "");
	root->accept(&tdv);

	root->command();
}




