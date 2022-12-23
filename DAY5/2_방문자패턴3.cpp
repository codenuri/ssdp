#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list      : 보관하는 모든 요소가 동일한 타입입니다. visit(int& value)
// PopupMenu : 보관하는 요소의 타입이 다릅니다.( PopupMenu, MenuItem)


// 메뉴 방문자의 인터페이스
class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	virtual void visit(MenuItem* mi) = 0;
	virtual void visit(PopupMenu* pm) = 0;
	virtual ~IMenuVisitor() {}
};

struct IAcceptor
{
	virtual void accept(IMenuVisitor* visitor) = 0;
	virtual ~IAcceptor() {}
};










class BaseMenu : public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() { return title; }
	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;
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

	virtual void accept(IMenuVisitor* visitor) override
	{
		visitor->visit(this); // 자신 전달

	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:

	virtual void accept(IMenuVisitor* visitor) override 
	{
		visitor->visit(this); // 자신 전달

		for (auto e : v)
			e->accept(visitor);
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



class PopupMenuTitleChangeVisitor : public  IMenuVisitor
{
	virtual void visit(MenuItem* mi) {}

	virtual void visit(PopupMenu* pm)
	{
		auto s = pm->get_title();

		s = "[ " + s + " ]";

		pm->set_title(s);
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

	// 메뉴 복합객체를 방문해서 "팝업메뉴만" 타이틀을 변경하는 방문자
	PopupMenuTitleChangeVisitor pmv;
	root->accept(&pmv);

	root->command();

}




