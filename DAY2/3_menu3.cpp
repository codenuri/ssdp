#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << "메뉴 선택됨\n";

		_getch(); 			
	}
};
class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;

public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// 핵심 : 팝업메뉴 선택시, 자신이 보관중인 모든 MenuItem 출력하고, 선택 받기
	void command()
	{
		while (1)
		{
			system("cls"); // 화면 지우기

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}

			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1) // 종료 메뉴 선택
				? ;

			if (cmd < 0 || cmd > sz + 1) // 잘못된 입력
				? ;


			// 선택된 메뉴 실행
			v[cmd - 1]->command();

		}




	}

};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 점심 메뉴");

	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // 팝업메뉴 선택시 해야할 일을 생각해 보세요

}




