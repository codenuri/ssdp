#include <iostream>

// 객체지향 디자인에서 널리 사용되는 용어
// 인터 페이스 : 지켜야 하는 규칙만 담고 있는 것
// 추상 클래스 : 지켜야 하는 규칙 + 다른 멤버 를 포함한것(위 color 같은 멤버)
// C#, Java : interface, abstract 라는 별도의 키워드 있음
// C++      : 별도 키워드 없음. 순수 가상함수와 추상 클래스 문법만 존재


// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시 클래스이름을 직접 사용하는것
// => People::use_camera(HDCamera*) <= HDCamera 직접 사용
// => 교체 불가능한 경직된 디자인

// 약한 결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시 규칙을 담은 인터페이스 이름을 사용하는 것
// => People::use_camera(ICamera*) 
// => 교체 가능한 유연한 디자인



// 규칙 : "모든 카메라는 아래 클래스로 부터 상속되어야 한다." 라고 하지 말고
//		  "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현	

// struct : 접근 지정자 생략시 디폴트값이 public
// class  : 접근 지정자 생략시 디폴트값이 private
// => 위 차이점 외에는 완전히 동일합니다.
// => 인터페이스 만들때 class 도 전혀 문제 없지만 struct 를 사용하는 경우가 많습니다

struct ICamera	
//class ICamera
{
//	int color;
//public:
	virtual void take() = 0;
	virtual ~ICamera() {}   // 인터페이스도 결국 "기반 클래스"
							// 소멸자를 가상함수로 해야 한다
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





