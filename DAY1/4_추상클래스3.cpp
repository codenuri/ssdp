#include <iostream>


// 무조건 제품(Camera) 를 만들지 말고

// 제품의 규칙을 먼저 설계하고, 규칙대로 사용합니다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 상속되어야 한다.

class ICamera
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





