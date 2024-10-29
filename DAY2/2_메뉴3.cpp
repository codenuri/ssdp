#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


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

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 11);

	
	PopupMenu pm("오늘의 점심 메뉴");

	pm.add(&m1);
	pm.add(&m2);

	pm.command(); // 팝업메뉴를 선택할때 동작을 생각해보세요

}




