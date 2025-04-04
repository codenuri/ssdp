// SOLID : SRP, OCP, LSP, ISP, DIP

// SRP(Single Responsibility Principle )
// => 하나의 클래스는 하나의 책임만 있어야 한다.

// OCP(Open Close Principle)
// => 확장에 열려 있고, 수정에는 닫혀야 한다.

// LSP(Liskov Substitution Principle)
// => 리스코프 라는 사람이 만든 치환의 법칙
// => 기반 클래스가 사용되는 곳에는 파생 클래스를 보낼수 있어야 한다.

// ISP(Interface Segregation Principle)
// => 인터페이스 분리의 원칙
struct IMP3
{
	virtual void play();
	virtual void stop();

	// 아래 함수는 새로운 인터페이스로 만들라는 것.
	virtual void take_picture();
};

// DIP(Dependency Inversion Principle)
// => 의존 관계 역전의 원칙
// => 구체에 의존하지 말고 추상에 의존해라
// => use_camera(HDCamera*); // bad - 구체에 의존
// => use_camera(ICamera*);  // good - 추상에 의존
//-----------------------------------------------------

// LSP 위반 예제 

class Car
{
public:
	virtual void go() { std::cout << "go\n"; }
};

// user 는 기반 클래스 Car 를 요구합니다.
// 이 위치에는 Car 의 파생 클래스를 보낼수 있어야 합니다.
// => 이 규칙이 LSP
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
	virtual void go() { throw 1; } // 기반 클래스 기능 제거
};

int main()
{
	use(new Car);		//
	use(new SuperCar);	//
	use(new FlyingCar); // LSP 위반. 
						// FlyingCar 는 go 기능 제거..
						// 이렇게 만들지 말라는 것이 LSP 원칙.
}