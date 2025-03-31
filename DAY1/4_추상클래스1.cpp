// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 생성할수 없다.
// 의도 : 
class Shape
{
public:
	virtual void draw() = 0;// 순수 가상함수(pure virtual function)
							// => 구현이 없고, "=0" 으로 표기
};
class Rect : public Shape
{
	// draw() 의 구현부를 제공하지 않으면 Rect 도 추상(abstract)입니다.
	// draw() 의 구현부를 제공하면       Rect 는 추상 아닙니다
public:
	void draw() override {} 
};
int main()
{
	Shape  s; // error
	Shape* p; // ok 
	Rect  r;  // ok 
}
