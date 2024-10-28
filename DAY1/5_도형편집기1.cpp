// 15page ~ 
#include <iostream>
#include <vector>

// 파워 포인트 같은 프로그램을 만드는 것을 생각해 봅시다.

// #1. 모든 도형을 타입화 하는 것이 편리합니다.

// #2. 모든 도형은 공통의 특징(color등)이 있습니다.
//     기반 클래스로 제공.
//     기반 클래스가 있으면 모든 도형을 하나의 컨테이너에 보관할수 있습니다.

class Shape
{
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// int x, y, w, h 와 생성자 등은 생략
public:
	void draw() { std::cout << "draw rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

int main()
{
//	std::vector<Rect*> v; // Rect 객체만 보관 가능한 컨테이너
	std::vector<Shape*> v; // 모든 도형을 보관 가능한 컨테이너
}

