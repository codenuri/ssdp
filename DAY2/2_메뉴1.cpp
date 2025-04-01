﻿// 2_메뉴1.cpp  - 55 page
#include <iostream>

// C 언어에서 프로그램 이란 ?
// 1. main 함수의 1번째 문장 부터 순차적으로 실행되는 실행흐름이다.

// 2. 실행흐름을 변경하려면 조건문(if, switch) 을 사용한다.
// 3. 실행흐름을 반복하려면 반복문(for, while) 을 사용한다.
// 4. 프로그램의 기본단위는 "함수" 이다.

// => 프로그램을 바로 보는 관점이 위와 같은 언어가 "strutural programming"
//    이라고 합니다.
//    대표적언어가 C 언어.. 

// 장점 : CPU 가 동작하는 방식과 동일하다.
//	      빠르고, 메모리 사용량도 적다.

// 단점 : 유지보수가 어렵고, 유연성, 확장성이 부족하다.
//        아래 예제에서 새로운 메뉴가 추가되면 ?
//        각 메뉴의 하위메뉴가 존재하면 ?

int main()
{
	// C 언어 스타일의 메뉴를 만든 코드 
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


