#include <iostream>


// 구체적인 Camera 를 먼저 만들지 말고
// 모든 카메라가 지켜야 하는 규칙을 먼저 설계한다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.

class ICalc
{
public:
	virtual void take() = 0;
};









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


