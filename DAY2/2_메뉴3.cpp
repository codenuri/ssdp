#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 여기까지 핵심
// => 메뉴 프로그램을 만들때도
// => 모든 것을 타입으로 먼저 설계한다는 점
// => "MenuItem", "PopupMenu" 등... 


class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택\n";
		_getch();	
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title)
		: title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// 핵심 : PopupMenu 가 선택될때 동작을 생각해 보세요
	// 1. 김밥
	// 2. 라면
	// 3. 종료
	// 메뉴를 선택하세요 >>
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

			if (cmd == sz + 1)	// 종료 메뉴 선택
				break;

			if (cmd < 1 || cmd > sz + 1) // 잘못된 입력
				continue;


			v[cmd - 1]->command();

		}
	}

};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 11);
	
	PopupMenu pm("오늘의 점심 메뉴");

	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // 팝업메뉴를 선택할때 동작을 생각해보세요

}




