#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


// list : 모든 요소가 동일타입, 선형적으로 데이터를 보관
// Menu : 요소의 타입이 다름.   Tree 구조. 

// 방문자 : 요소 한개에 대한 연산을 정의 하는 클래스
// => 그런데, 요소의 타입이 다를수 있고
// => 각 타입마다 다르게 처리해야 한다면.. 아래 처럼

class MenuItem;
class PopupMenu;

struct IMenuVisitor
{
	// 아래 처럼 만들면, MenuItem, PopupMenu 모두 한개의 함수에서
	// 동일하게 처리하겠다는 의미
//	virtual void visit(BaseMenu* mi) = 0;

	// 다르게 동작하려면 아래 처럼
	virtual void visit(MenuItem* mi) = 0;
	virtual void visit(PopupMenu* pm) = 0;
	virtual ~IMenuVisitor() {}
};

// 방문의 대상의 인터페이스
struct IAcceptor
{
	virtual void accept(IMenuVisitor* v) = 0;
	virtual ~IAcceptor() {}
};



class BaseMenu :  public IAcceptor
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;
};




class MenuItem : public BaseMenu
{
	int id;
public:

	void accept(IMenuVisitor* visitor)
	{
		// MenuItem 은 하위메뉴가 없으므로
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

	// 방문자를 받아들이는 함수 - 이 예제의 핵심
	void accept(IMenuVisitor* visitor)
	{
		// 자신을 먼저 방문자에 전달
		visitor->visit(this);
		
		for (auto m : v)
		{
			// 하위 메뉴도 방문자에 전달하면, 직계 자신만 전달된다.
			// visitor->visit(m); // ?

			// 아래 처럼, 하위 메뉴에게 다시 방문자를 accept 한다
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



// 이제 Menu 시스템에서 사용할 다양한 방문자 을 설계하면 됩니다.

class MenuTitleChangeVisitor : public IMenuVisitor
{
	std::string popupmenu_tag;
	std::string menuitem_tag;	
public:
	MenuTitleChangeVisitor(const std::string& s1, const std::string& s2)
		: popupmenu_tag(s1), menuitem_tag(s2) {
	}
	void visit(MenuItem* mi) 
	{
		std::string title = mi->get_title();
		title += menuitem_tag;
		mi->set_title(title);
	}
	void visit(PopupMenu* pm)
	{
		std::string title = pm->get_title();
		title += popupmenu_tag;
		pm->set_title(title);
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

	// 메뉴의 타이틀을 꾸미는 방문자
	MenuTitleChangeVisitor v(" >", ""); // 팝업메뉴 : " >", 메뉴아이템:"" 추가

	root->accept(&v);


	root->command();

}




