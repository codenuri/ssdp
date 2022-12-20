#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 모든 메뉴의 공통의 기반 클래스
class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title; }

	// 모든 메뉴는 선택될수 있다.
	// 모든 파생 클래스(메뉴)의 공통의 특징은 반드시 기반 클래스에도 있어야한다.
	virtual void command() = 0;

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

			v[cmd - 1]->command(); // 다형성!!
									// 어떤 종류의 메뉴인지 조사할 필요 없다.
		}


	}
};




int main()
{
	MenuItem m1("소고기김밥", 11);
	MenuItem m2("참치김밥",   12);

	PopupMenu pmkimbam("김밥류");
	pmkimbam.add_menu(&m1);
	pmkimbam.add_menu(&m2);

	MenuItem m3("라면", 21);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add_menu(&pmkimbam); // 핵심!!!
	pm.add_menu(&m3);

	pm.command();	
}




