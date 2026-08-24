// 1_추상클래스1.cpp - 10page
// 추상 클래스(abstract class)
// 정의 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 생성할수 없다
// 의도 : 약속된 함수를 반드시 만들라고 지시하기 위해 사용하는 문법
//		  "일종의 규칙을 만드는 문법"
class Shape
{
public:
	virtual void draw() = 0; // 순수 가상함수(pure virtual function)
							 // => 구현이 없고, "= 0" 으로 표기							 
};
class Rect : public Shape
{
	// Shape 에서 draw() 순수 가상함수 물려 받음
	// 1. draw() 의 구현부를 제공하지 않으면 Rect 도 추상(abstract)
	// 2. draw() 의 구현부를 제공하면       Rect 는 추상아님, 구체(concrete)

	void draw() override {} // 이렇게 구현을 제공하면 Rect 는 추상 아님
};
int main()
{
	Shape  s; // error. 추상 클래스는 객체 생성 안됨
	Shape* p; // ok. 포인터 변수는 가능
	Rect  r;
}
