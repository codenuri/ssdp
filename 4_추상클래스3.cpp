#include <iostream>


// ī�޶�� ����ڰ� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�.

class ICamera
{
public:
	virtual void take() = 0;
};

// ���� ī�޶�� ������, ��Ģ�� �ִ�.
// ����ڴ� ��Ģ ��θ� ����ϸ� �ȴ�.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// ��� ī�޶�� ��Ģ��� ���� �Ǿ�� �մϴ�.

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






