#include <iostream>
#include <vector>

// 파워 포인트 값은 "도형을 편집"하는 프로그램을 만들어 봅시다.

// 핵심 #1. 모든 도형을 타입으로 설계 합니다.

// 핵심 #2. 모든 도형의 공통의 기반 클래스가 있다면
// => 장점 #1. color 같은 공통의 특징을 한곳에서 관리 할수 있게 된다.
// => 장점 #2. 모든 도형을 하나의 컨테이너에 보관할수있게 된다.

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {} // 가상 소멸자
};

class Rect : public Shape
{
	// x, y, w, h 생성자등은 생략
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
//	std::vector<Rect*> v;	// Rect 만 보관 가능한 vector
	std::vector<Shape*> v;	// 모든 도형을 보관 가능한 vector
}

