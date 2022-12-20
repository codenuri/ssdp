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
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;

		_getch(); // 아무키나 누를때까지 대기
	}
};



int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command();	// 메뉴 선택시 호출되는 함수!
}




