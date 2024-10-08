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

	void command()
	{
		while (1)
		{
			system("cls"); 

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}

			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)	
				break; 

			if (cmd < 1 || cmd > sz + 1)
				continue;



			v[cmd - 1]->command();
		}
	}
};



int main()
{
	MenuItem m1("참치김밥",   11);
	MenuItem m2("소고기김밥", 12);

	MenuItem m9("라면", 21);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);


	PopupMenu pm("오늘의 점심 메뉴");

	pm.add(&kimbab);	// 핵심!!! 현재는 error. 
						// 어떻게 해야 할까요 ??
						// => 해결은 다음 소스에서
	pm.add(&m9);	// ok..!

	pm.command(); 
}




