#include <iostream>

// 강한 결합(tightly coupling) vs 약한 결합( loosely coupling )

// 강한 결합 : 하나의 클래스가 다른 클래스사용시 클래스이름을 직접 사용
//			   교체 불가능한 경직된 디자인

// 약한 결합 : 하나의 클래스가 다른 클래스사용시 기반 클래스인 추상 클래스 이름
//			  (인터페이스) 을 사용해서 접근.
//			  교체 가능한, 확장성 있는, 유연한 디자인


//=====================================
// 추상 클래스 vs 인터페이스 

// 인터 페이스 : 지켜야 하는 규칙(순수가상함수) 만 있는 경우
// 추상 클래스 : 지켜야 하는 규칙(순수가상함수) + 다른 멤버도 있는 경우

// Java, C# : interface, abstract 라는 별도의 키워드 존재
// C++ 별도의 키워드 없습니다. 그냥, 순수 가상함수 문법만 존재합니다.

//==========================================


// 사람이나 카메라를 먼저 만들지 말고..
// 카메라와 카메라 사용자 사이에 지켜야 하는 규칙을 먼저 설계 합니다.

// 규칙 : "모든 카메라는 아래 클래스로 부터 파생 되어야 한다." 라고 하지말고
//        "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현 합니다.

// 인터페이스 만들때 "class" 보다는 "struct" 로 하는 경우가 많습니다.
// => 접근지정자 를 표기하지 않아도 public 이므로
struct ICamera
{
	virtual void Take() = 0;
	virtual ~ICamera() {}   // 인터페이스도 문법적으로는 결국 기반 클래스입니다.
							// 소멸자는 반드시 가상함수이어야 합니다
};			








// 이제 규칙이 생겼으므로 카메라가 없어도 
// 카메라를 사용하는 코드를 만들수 있습니다.
// 규칙 대로만 사용하면 됩니다.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// 모든 카메라는 규칙을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc);

	UHDCamera uhc;
	p.UseCamera(&uhc);

}





