﻿#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
// std::list : 모든 요소가 동일 타입, 선형 자료구조
// PoupMenu  : 요소의 타입이 다를수 있고, Tree 구조

class MenuItem;
class PopupMenu;

struct IMenuVisitor
{
	virtual void visit(MenuItem* m) = 0;
	virtual void visit(PopupMenu* m) = 0;
	virtual ~IMenuVisitor() {}
};



class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& t) { title = t; }


	virtual void command() = 0;

	virtual void accept(IMenuVisitor* visitor) = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:
	void accept(IMenuVisitor* visitor)
	{
		// 자신만 전달하면 됩니다.
		visitor->visit(this);

	}



	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:

	// PopupMenu 에 방문자가 방문할때
	// => 이 부분이 이예제의 핵심
	void accept(IMenuVisitor* visitor)
	{
		// #1. 자신을 먼저 방문자에 전달
		visitor->visit(this);


		// #2. 하위 메뉴도 방문자에 전달하면 안됩니다.
		// => 직계자식만 전달되고, 손자는 전달 안됩니다.
		for (auto m : v)
		{
			// visitor->visit(m); // 이렇게 하지 말라는 것

			// 자식메뉴에 방문자를 방문 시켜야 합니다.
			m->accept(visitor);
		}
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



// 실제 메뉴 방문자
class MenuTitleChangeVisitor : public IMenuVisitor
{
	std::string pstring;
	std::string mstring;
public:
	MenuTitleChangeVisitor(const std::string& s1, const std::string& s2)
		: pstring(s1), mstring(s2) {	}

	void visit(MenuItem* m) override
	{
		auto s = m->get_title() + mstring;
		m->set_title(s);
	}

	void visit(PopupMenu* m) override
	{
		auto s = m->get_title() + pstring;
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


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	MenuTitleChangeVisitor v(" >", " *"); // 메뉴 타이틀을 변경하는 방문자
	
	root->accept(&v);


	root->command();

}




