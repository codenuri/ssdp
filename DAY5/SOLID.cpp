// SOLID.CPP 

#include <iostream>

// SOLID 
// SRP : Single Responsibility Principle => 하나의 클래스는 하나의 책임(기능)만!!
// OCP : Open Close Principle            => 기능확장에 열려 있고, 코드 수정에는 닫혀 있어야!!
// LSP : Liskov Substitution Principle
// ISP : Interface Segregation Principle
// DIP : Dependency Inversion Principle        


//-------------------------------------------------------
// LSP ( Liskov Substitution Principle )
// => 리스코프 라는 사람이 만든 치환의 법칙
// => 기반 클래스가 필요한 곳은 파생 클래스로 치환할수 있어야 한다.

class Car
{
	// 다양한 멤버 들.. 
public:
	virtual void Go() { std::cout << "Go\n"; }
};

class SuperCar : public Car
{
public:
	void Go() override { std::cout << "fast Go\n"; }
};

class FlyingCar : public Car
{
public:
	void Fly() {}
	void Go() override { throw UnsupportedOperation(); } // 기반 클래스 기능
										// 제거!!
};

void foo(Car* c) // 기반 클래스가 사용되는 곳
{
	c->Go();
}

foo(new SuperCar);	// LSP 위반 아님.
foo(new FlyingCar); // LSP 위반!!! 기반 클래스 기능이 제거 되었다
					// 나쁜 코드!!
					// 컴파일 에러는 아니지만 Go 기능이 없다.

//---------------------------------------------------
// ISP ( Interface Segregation Principle )
// => 인터페이스의 격리(분리)의 원칙
// => 각 클라이언트가 필요로 하는 인터페이스들을 분리함으로써, 
//    클라이언트가 사용하지 않는 인터페이스에 변경이 발생하더라도 
//    영향을 받지 않도록 만들어야 하는 것이 핵심이다.

// 아래 코드는 나쁜 인터페이스
/*
struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual void upload_sns() = 0;
	virtual ~IMP3() {}
};
*/

// 아래 코드가 좋은 인터페이스
struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};

struct ISNS
{
	virtual void upload_sns() = 0;
	virtual ~ISNS() {}
};

void only_listening_music(IMP3* mp3)
{
	mp3->play();
	mp3->stop();
}

//----------------------------------------------
// DIP ( Dependency Inversion Principle )
// => 의존 관계 역전의 법칙
// => 상위 모듈은 하위 모듈의 세부 구현에 의존하면 안된다.
// => 상위 모듈은 하위 모듈의 추상에 의존해야 한다.
// => 세부 사항에 의존하지 말고, 추상에 의존하라는 것
class People
{
public:
	void use(HDCamera* c) { c->take(); }  // DIP 위반
	void use(ICamera* c) { c->take(); }  // DIP 준수

	// People 은 카메라가 필요하지만, 
	// 1. 구체적인 하위 모듈(HDCamera)에 의존하지 않고
	// 2. 추상(ICamera) 에 의존하게 된다.
};

