#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그램
// => 필요한 타입을 먼저 만든다.
// => 메뉴 관련 프로그램을 작성한다면 "Menu" 라는 타입을 먼저 만든다

class MenuItem
{

};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 김밥 선택
}




