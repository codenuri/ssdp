//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p)   { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ???

}

// 객체지향 설계의 5개 원칙
// => SRP, OCP, LSP, ISP, DIP => 약자로 SOLID

// OCP
// 기능 확장에는 열려 있어야(Open, 새로운 클래스가 추가되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않게)
// 하라는 원칙(Principle)
// Open-Close Principle(개방 폐쇄의 법칙)

// 위 코드는 OCP 를 만족하지 않은 나쁜 디자인.





