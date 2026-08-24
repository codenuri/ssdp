#include <iostream>


// 무조건 제품(Camera) 를 만들지 말고

// 제품의 규칙을 먼저 설계하고, 규칙대로 사용합니다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 상속되어야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};

// 실제 카메라는 없지만 규칙이 있습니다.
// 사용자는 실제 카메라에 대해서는 몰라도 됩니다.
// 오직 규칙만 알면 되고, 규칙대로만 사용하면 됩니다.
// => 아래 People 은 실제 카메라 제품의 이름(클래스이름)은 사용하지 않습니다
class People
{
public:
	// 인자로 규칙의 이름을 사용합니다
	void use_camera(ICamera* p) { p->take(); }
};


// 이제 모든 카메라는 규칙대로 설계되어야 합니다.
// 1. ICamera 로 부터 상속 받고
// 2. take() 를 만들어야 한다

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
	p.use_camera(&hc); // ok

	UHDCamera uhc;		// 새로운 제품(UHDCamera) 가 나왔지만
	p.use_camera(&uhc); // ok   People 을 수정하지 않아도 사용가능하다
}





