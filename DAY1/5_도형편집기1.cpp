#include <iostream>
#include <vector>

// 파워포인트 같은 프로그램을 객체지향으로 설계해 봅시다.

// #1. 각 도형을 타입으로 설계하면 편리하다.

class Rect
{
	// int x, y, w, h 생성자 등은 생략
public:
	void draw() { std::cout << "draw rect\n"; }
};

int main()
{

}

