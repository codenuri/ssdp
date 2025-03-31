#include <iostream>

// �߻� Ŭ���� vs �������̽�

// �������̽� : ���Ѿ� �ϴ� ��Ģ(���� �����Լ�)�� ���� ���
// �߻�Ŭ���� : ���Ѿ� �ϴ� ��Ģ + �ٸ� ����� �ִ� ���

// java, C# : abstract, interface ��� ������ Ű���� ����
// C++      : ������ Ű���� ����, �� �������θ� ����, ȥ��Ǿ� ���Ǳ⵵��
//-------------------------------------------------------------

// ī�޶�� ����ڰ� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�. " ��� ���� ����
//        "��� ī�޶�� �Ʒ� �������̽��� ���� �ؾ� �Ѵ�." ��� ǥ���մϴ�.

//#define interface struct   // ������ ���Ǵ� ���

//class ICamera		// ���������� ������ ����Ʈ�� private
struct ICamera		// ���������� ������ ����Ʈ�� public
//inteface ICamera
{
//public:
	virtual void take() = 0;

	virtual ~ICamera() {}  // �������̽��� �ᱹ ���������δ� ��� Ŭ����
						   // "����Ҹ���" �� �ؾ� �մϴ�.
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
	p.use_camera(&uhc); // ok.. People �� �������� �ʾƵ�
						// �̷��� ���� ���ο� ī�޶� ��밡��!!
						// OCP ����
}

// ��� ����

// ���� ����(tightly coupling)
// => Ŭ������ �ٸ� Ŭ���� ���� Ŭ���� �̸��� ���� ����ϴ� ��
// => ��ü �Ұ����� ������ ������
// => People::use_camera(HDCamera*)

// ���� ����(loosely coupling)
// => Ŭ������ �ٸ� Ŭ���� ���� ��Ģ�� ���� �������̽��� ����ϴ� ��
// => ��ü ������ ������ ������
// => People::use_camera(ICamera*)




