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
	MenuTitleChangeVisitor v(" >", "*"); // 팝업메뉴 : " >", 메뉴아이템:"" 추가
	root->accept(&v);


	root->command();

}




// std::list : 모두 같은 타입을 보관하고 iterator 로 순회 가능하고, range-for 사용가능
//             => 외부에서 모든 요소 순회 가능합니다.
//             => 방문자 사용할 필요 없습니다.
//             => 그냥 range-for 사용하세요

// 메뉴 시스템 : 외부에서 요소 열거 안되고
//				타이틀 변경등의 가상함수 추가가 복잡해 지는 경우
//				최초 부터 "visitor" 패턴으로 만들어 놓으면
//				다양한 방문자 클래스 활용이 가능해 집니다.


/*
//-----------------------------
class Shape {};
class Rect   : public Shape {};
class Circle : public Shape {};

// 디자인 패턴을 사용해서 잘 설계된 시스템에서
// 
// 1. 타입을 추가하는 일은 "쉽다"  
// => OCP 를 잘 사용했다면 "새로운 도형을 추가" 하는 일은 어렵지 않다

// 2. 연산(가상함수)를 추가하는 일 - "어렵다"
// => 모든 도형에 크기를 줄이는 deflate() 함수 추가 ?
// => Shape 에도 추가하고, 모든 클래스에도 추가해서 각각 구현해야 한다.
// => 즉, 모든 클래스가 변경된다


// 그런데. 처음부터 Visitor 패턴으로 디자인 했다면
// => deflate() 를 가상함수로 추가하지 말고
// => DeflateVisitor 를 만들어서 shape_vector.accept(&v) 했다면
//                              menu_root.accept(방문자) 처럼

// 방문자 패턴의 의미
// 1. 시스템에 "연산(가상함수)" 의 추가가 쉬워 진다
// => 실제 가상함수를 추가하는 것이 아니라
// => 가상함수가 할일을 수행하는 "visitor" 를 설계 하라는 것

// 2. 타입의 추가 - 어렵다
// => 현재 메뉴는 "MenuItem", "PopupMenu" 이고 방문자 인터페이스는 아래 코드 입니다.
/*
struct IMenuVisitor
{
	virtual void visit(MenuItem * mi) = 0;
	virtual void visit(PopupMenu * pm) = 0;
	virtual ~IMenuVisitor() {}
};
*/
// => 이때 새로운 메뉴 타입 "SpecialMenu" 가 추가되면 위 인터페이스가 수정됩니다.
// => 만들었던 모든 방문자를 수정되어야 합니다.
// => 사실상 타입의 추가능 불가능 합니다


// 전통적인 패턴 : 타입추가는 쉽지만, 연산의 추가가 어렵다(Shape 이하 모든 타입에 함수추가)
// Visitor 도입 : 연산의 추가가 쉽지만(연산을 방문자로 구현), 타입추가가 어렵다
