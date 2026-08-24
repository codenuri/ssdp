#include <iostream>


// 규칙 : 모든 카메라는 아래 클래스로 부터 상속되어야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};


class People
{
public:
	void use_camera(ICamera* p) { p->take(); }
};



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





