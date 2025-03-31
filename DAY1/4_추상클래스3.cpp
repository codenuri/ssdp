#include <iostream>

// 추상 클래스 vs 인터페이스

// 인터페이스 : 지켜야 하는 규칙(순수 가상함수)만 가진 경우
// 추상클래스 : 지켜야 하는 규칙 + 다른 멤버도 있는 경우

// java, C# : abstract, interface 라는 별도의 키워드 제공
// C++      : 별도의 키워드 없음, 위 내용으로만 구분, 혼용되어 사용되기도함
//-------------------------------------------------------------

// 카메라와 사용자가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다. " 라고 하지 말고
//        "모든 카메라는 아래 인터페이스를 구현 해야 한다." 라고 표현합니다.

//#define interface struct   // 예전에 사용되던 기술

//class ICamera		// 접근지정자 생략시 디폴트가 private
struct ICamera		// 접근지정자 생략시 디폴트가 public
//inteface ICamera
{
//public:
	virtual void take() = 0;

	virtual ~ICamera() {}  // 인터페이스는 결국 문법적으로는 기반 클래스
						   // "가상소멸자" 로 해야 합니다.
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
	p.use_camera(&uhc); // ok.. People 을 수정하지 않아도
						// 미래에 나온 새로운 카메라 사용가능!!
						// OCP 만족
}

// 용어 정리

// 강한 결합(tightly coupling)
// => 클래스가 다른 클래스 사용시 클래스 이름을 직접 사용하는 것
// => 교체 불가능한 경직된 디자인
// => People::use_camera(HDCamera*)

// 약한 결합(loosely coupling)
// => 클래스가 다른 클래스 사용시 규칙을 담은 인터페이스로 사용하는 것
// => 교체 가능한 유연한 디자인
// => People::use_camera(ICamera*)




