#include <iostream>


// 구체적인 Camera 를 먼저 만들지 말고
// 모든 카메라가 지켜야 하는 규칙을 먼저 설계한다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.

class ICalc
{
public:
	virtual void take() = 0;
};

// 실제 카메라가 없어도, 규칙이 있다.
// 사용하는 코드를 작성할수도 있다.
// 규칙대로만 사용하면된다.
class People
{
public:
	void use_camera(ICalc* c) { c->take(); }
};

// 모든 카메라는 규칙을 지켜야 한다.

class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc);
}


