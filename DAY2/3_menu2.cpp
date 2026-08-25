#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그램
// => 필요한 타입을 먼저 만든다.
// => 메뉴 관련 프로그램을 작성한다면 "Menu" 라는 타입을 먼저 만든다

class MenuItem
{
	std::string title;
//	std::string shortcut;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}
	
	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << "메뉴 선택됨\n";

		_getch(); // 아무 키나 누를때 까지 잠시 대기			
	}

};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 김밥 선택
}




