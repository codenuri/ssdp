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
	void use_camera(Camera* p) { p->take(); }
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


// OCP
// 기능확장에는 열려 있고(Open, 새로운 클래스(모듈)가 추가되어도)
// 코드수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않도록)
// 한다는 이론(Priciple )

// Open Close Principle 
// => 개방 폐쇄의 법칙

// 객체지향 S/W 설계의 5대 원칙 ( SOLID )
// SRP
// OCP
// LSP
// ISP
// DIP

// 위 코드는 OCP 위반
// => "HDCamera" 추가시 기존 클래스 "People" 이 수정되고 있다.

