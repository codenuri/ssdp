#include <iostream>


// 카메라와 사용자가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};

// 실제 카메라는 없지만, 규칙이 있다.
// 사용자는 규칙 대로만 사용하면 된다.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// 모든 카메라는 규칙대로 설계 되어야 합니다.

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

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

}






