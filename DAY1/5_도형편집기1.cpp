// 15page ~ 
#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.

// #1. 모든 도형을 타입화 하는 것이 편리합니다.

class Rect
{
	// int x, y, w, h 와 생성자 등은 생략
public:
	void draw() { std::cout << "draw rect\n"; }
};
class Circle
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

int main()
{
	std::vector<Rect*> v;
}

