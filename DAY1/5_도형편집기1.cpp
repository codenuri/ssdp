#include <iostream>
#include <vector>

// 파워포인트 같은 프로그램을 객체지향으로 설계해 봅시다.

// #1. 각 도형을 타입으로 설계하면 편리하다.

// #2. 각 도형은 공통의 특징이 있다(color 등)
//     기반 클래스가 있다면
// => 공통의 클래스를 한곳에서 관리 할수 있고(기반 클래스인 Shape)
// => vector<Shape*> 를 사용하면 모든 도형을 하나의 컨테이너에 보관할수도있다

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
	// int x, y, w, h 생성자 등은 생략
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
	std::vector<Rect*>  v1; // 사각형만 보관 가능한 vector
	std::vector<Shape*> v2; // 모든 도형을 보관할수 있는 vector
}

