#include <iostream>

// 아래 2개의 용어가 혼용되어 사용되곤 합니다. 차이점은
// 추상 클래스 : 지켜야 하는 규칙(순수가상함수) + 다른 멤버
// 인터 페이스 : 지켜야 하는 규칙(순수가상함수) 만 있는 경우

// java, C# : 별도의 inteface, abstract 키워드 존재
// C++ : 별도의 키워드 없이, 추상클래스 문법으로만 모두 만들게 된다.

//---------------------------------------------
// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 "클래스이름을 직접" 사용하는것
// => People::use_camera(Camera*)
// => 교체 불가능한 경직된 디자인


// 약한 결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시 "규칙을 담은 인터페이스 이름" 
//    을 통해서 접근하는것
// => People::use_camera(ICamera*)
// => 교체 가능한 유연한 디자인





//------------------------------------------------------------
// 구체적인 Camera 를 먼저 만들지 말고
// 모든 카메라가 지켜야 하는 규칙을 먼저 설계한다.

// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다."  라고 표현하지 말고
//       "모든 카메라는 아래 인터페이스를 구현해야한다." 라고 표현합니다.

// class 와 struct 의 차이는 단 한가지 입니다.
// class  : 접근지정자 생략시 private 이 디폴트
// struct : 접근지정자 생략시 public  이 디폴트

#define interface struct

struct ICamera
//interface ICamera   // 옛날에 한때 유행했던 기술
{

	virtual void take() = 0;
	virtual ~ICamera() {}   // 인터페이스도 결국 기반 클래스 입니다.
							// 반드시 "소멸자를 가상" 으로!!
};



// 실제 카메라가 없어도, 규칙이 있다.
// 사용하는 코드를 작성할수도 있다.
// 규칙대로만 사용하면된다.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// 모든 카메라는 규칙을 지켜야 한다.

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


