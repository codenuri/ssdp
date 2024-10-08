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
		std::cout << get_title() << " 메뉴 선택됨\n";
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

	// main 의 주석을 참고해서 아래 코드를 생각해 보세요
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


			if (cmd == sz + 1)	// 종료 메뉴
				break ; // 또는 return

			if (cmd < 1 || cmd > sz + 1)	// 잘못된 입력
				continue ;



			v[cmd - 1]->command(); // 메뉴 선택시 MenuItem 의 command() 호출
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

	pm.command();  // 팝업메뉴 선택시 동작을 생각해 보세요
					// 1. 김밥
					// 2. 라면
					// 3. 종료
					// 메뉴를 선택하세요 >>
}




