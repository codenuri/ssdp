//1_추상클래스2.cpp
#include <iostream>

// OCP
// 기능 확장에는 열려 있고(Open, 클래스가 나중에 추가되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않도록)
// 디자인 하라는 원칙

// Open Close Principle( 개방 폐쇄의 법칙 )

// 객체 지향 S/W 설계의 5대 원칙 : SRP, OCP, LSP, ISP, IDP ( SOLID )


class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};


class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc);
}





