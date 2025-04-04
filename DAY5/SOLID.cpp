// SOLID : SRP, OCP, LSP, ISP, DIP

// SRP(Single Responsibility Principle )
// => �ϳ��� Ŭ������ �ϳ��� å�Ӹ� �־�� �Ѵ�.

// OCP(Open Close Principle)
// => Ȯ�忡 ���� �ְ�, �������� ������ �Ѵ�.

// LSP(Liskov Substitution Principle)
// => �������� ��� ����� ���� ġȯ�� ��Ģ
// => ��� Ŭ������ ���Ǵ� ������ �Ļ� Ŭ������ ������ �־�� �Ѵ�.

// ISP(Interface Segregation Principle)
// => �������̽� �и��� ��Ģ
struct IMP3
{
	virtual void play();
	virtual void stop();

	// �Ʒ� �Լ��� ���ο� �������̽��� ������ ��.
	virtual void take_picture();
};

// DIP(Dependency Inversion Principle)
// => ���� ���� ������ ��Ģ
// => ��ü�� �������� ���� �߻� �����ض�
// => use_camera(HDCamera*); // bad - ��ü�� ����
// => use_camera(ICamera*);  // good - �߻� ����
//-----------------------------------------------------

// LSP ���� ���� 

class Car
{
public:
	virtual void go() { std::cout << "go\n"; }
};

// user �� ��� Ŭ���� Car �� �䱸�մϴ�.
// �� ��ġ���� Car �� �Ļ� Ŭ������ ������ �־�� �մϴ�.
// => �� ��Ģ�� LSP
void use(Car* c)
{
	c->go();
}

class SuperCar : public Car
{
public:
	virtual void go() { std::cout << "fast go\n"; }
};

class FlyingCar : public Car
{
public:
	void fly() {}
	virtual void go() { throw 1; } // ��� Ŭ���� ��� ����
};

int main()
{
	use(new Car);		//
	use(new SuperCar);	//
	use(new FlyingCar); // LSP ����. 
						// FlyingCar �� go ��� ����..
						// �̷��� ������ ����� ���� LSP ��Ģ.
}