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
// 위 코드는 아무 문제 없이 잘 컴파일/실행 됩니다.
// 그런데.. 단점은
// => 새로운 제품(HDCamera) 때문에 기존에 있던 People 코드가 수정됩니다.
// => 앞으로 새로운 제품이 나오면 계속 수정해야 합니다.

// 객체지향 프로그램의 5개 원칙 : SOLID

// SRP, OCP, LSP, ISP, DIP 의 첫글자를 모아서 "SOLID"

// 이중 OCP

// 기능 확장에 열려 있고(Open, 새로운 모듈/클래스 가 추가되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않게)
// 한다는 원칙(Priciple)

// Open-Close Principle(개방 폐쇄의 법칙)

// 위 코드는 OCP를 만족하지 못하는 코드. 좋지 않은 디자인




