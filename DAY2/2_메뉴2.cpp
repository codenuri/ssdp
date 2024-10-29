#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그래밍
// => "모든 것은 객체이다."
// => 프로그램에서 필요한 타입을 먼저 설계한다.

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 11);

	m1.command(); // 김밥 메뉴를 선택했을때 호출되는 함수.
}




