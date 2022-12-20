#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class InvalidOperation : std::exception {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title; }

	virtual void command() = 0;

	// BaseMenu 가 아래 처럼 제공한다면.
	// 
	// root->get_sub_menu(0)->add_item( ....) 처럼 사용가능합니다.
	// 단, "root->get_sub_menu(0)" 가 Popup 이 아니면 예외 발생

	virtual void add_item(BaseMenu*) { throw InvalidOperation(); }
	virtual BaseMenu* get_sub_menu(int idx) { throw InvalidOperation(); }
};




class MenuItem : public BaseMenu
{
	int  id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;

		_getch();
	}
};


class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}


	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command()
	{
		while (1)
		{
			system("cls");

			std::size_t sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << "\n";
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";
			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				return;


			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}


	}

	BaseMenu* get_sub_menu(int idx)	{ return v[idx];}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	
	MenuItem* mi1 = new MenuItem("열기", 11);

	root->add_menu(&pm1);
	root->add_menu(&mi1);

	// 하위 메뉴를 얻는 get_sub_menu() 를 생각해 봅시다.
	root->get_sub_menu(0); // ok

	root->get_sub_menu(0)->add_item(new MenuItem("HD", 21));


	// 이제 시작하려면 ?
	root->command();
}





