#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.

// 1. 모든 도형을 타입화 하면 편리합니다

// 2. 모든 도형의 공통의 기반 클래스가 있다면 모든 도형을 하나의 
//    컨테이너(vector)에 보관할수 있다.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// 멤버데이타, 생성자는 생략(int left, top, right, bottom등)
public:
	void draw() { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle" << std::endl; }
};
int main()
{
//	std::vector<Rect*> v; // Rect 만 보관 가능
	std::vector<Shape*> v; // 모든 도형을 보관 가능
}


