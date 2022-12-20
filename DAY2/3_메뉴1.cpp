// 2_메뉴1.cpp  - 55 page
#include <iostream>

// C 언어에서 프로그램은
// 1. main 함수의 1번째 줄부터 순차적으로 실행되는 실행흐름이다.
// 2. 실행흐름을 변경하려면 제어문 사용
// 3. 실행흐름을 반복하려면 반복문 사용
// 4. 기능별로 분리하려면 함수 사용
// 5. 프로그램의 기본 단위는 함수!!

// 아래 코드는
// 장점 : 쉽다.
// 단점 : 메뉴가 추가된다면?, 하위 메뉴가 존재하면 ?

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}

}


