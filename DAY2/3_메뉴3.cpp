#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그램에서 모든 것은 "객체"이다.

class MenuItem
{
	std::string title;
	int  id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;

		_getch(); // 아무키나 누를때까지 대기
	}
};


class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add_menu(MenuItem* p) { v.push_back(p); }

	// 팝업 메뉴를 선택할때!!
	void command()
	{
		std::size_t sz = v.size();

		for (int i = 0; i < sz; i++)
		{
			std::cout << i + 1 << ". " << v[i]->get_title() << "\n";
		}
		std::cout << sz + 1 << ". 종료\n";

		std::cout << "메뉴를 선택하세요 >> ";
		int cmd;
		std::cin >> cmd;

		// 선택된 메뉴 실행
		v[cmd - 1]->command();
	}
};




int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();	// 팝업 메뉴를 선택할때 해야 할일을 생각해 보세요 ?
					// 1. 김밥
					// 2. 라면
					// 3. 종료
					// 메뉴를 선택하세요 >>
}




