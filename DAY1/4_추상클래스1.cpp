// 1_추상클래스1.cpp - 10page

// 추상클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 만들수 없다. 단 포인터 타입의 변수는 선언 가능. 
// 의도 : 

class Shape
{
public:
	virtual void draw() = 0; // 순수 가상함수(pure virtual function)
							 // 구현이 없고, "=0" 으로 표기
};

class Rect : public Shape
{
	// draw 의 구현을 제공하지 않으면 Rect 도 추상
	// draw 의 구현을 제공하면 Rect 는 추상 아님(구체, concreate)

public:
	void draw() override {} // 구현이 있으므로 추상 클래스 아님.
};

int main()
{
	Shape  s; // error
	Shape* p; // ok
	Rect  r;
}
