// SOLID : SRP, OCP, LSP, ISP, DIP
// => 객체지향 프로그램시 지켜야하는 5가지 원칙
// => 디자인 패턴은 이 원칙을 지키기 위한 코딩 기술

// OCP(Open Close Principle)
// => 기능이 나중에 추가되어도 기존 코드는 수정되지 않게 하라
// => 기능확장에 열려 있고(Open), 코드 수정에는 닫혀라(Close)


// DIP(Dependency Inversion Principle)
// => 구현에 의존하지 말고 추상에 의존해라
// => 상위 모듈은 하위모듈에 "직접(directly)" 의존하면 안된다.
// => People::use_camera(HDCamera*); // bad - 강한 결합
// => People::use_camera(ICamera*);  // good - 약한결합



// SRP(Single Responsibility Principle )
// => 하나의 "클래스"에는 하나의 책임만 있어야 한다.


// ISP(Interface Segregation Principle)
// => "인터페이스"는 기능별로 "격리(분리)"되어야 한다.
struct IMP3
{
	virtual void play();
	virtual void stop();

	// 아래 처럼 하지 말라는 의미
	virtual void take_picture();
};

struct IMP3
{
	virtual void play();
	virtual void stop();
};

struct Capture
{
	virtual void take_picture();
};

// C++ 은 다중 상속 되는데, Java, C# 은 안되지 않나요 ??
// Java, C# 도 interface 의 다중 상속(다중구현)은 허용
class GoodMP3 : public IMP3, public Capture
{

};




// LSP(Liskov Substitution Principle)
// => Listkov 라는 사람이 만든 치환의 법칙
// => 기반 클래스가 필요한 곳에 파생 클래스를 보낼수 있어야 한다.

void foo(Base* p)
{
}

Derived d;
foo(&d); // 이렇게 사용가능해야 한다는것

// 당연히 되지 않나요 ?
// => SOLID2.cpp 참고
