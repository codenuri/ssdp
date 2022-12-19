// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스.
// 특징        : 객체를 만들수 없다, 단, 포인터 변수는 가능
// 의도 : 파생 클래스가 특정 함수(Draw) 를 반드시 만들어야 한다고
//       "지시" 하는 것

class Shape
{
public:
	virtual ~Shape() {}
	virtual void Draw() = 0; // 순수 가상 함수(pure virtual function)
							 // 특징 : 구현부가 없고, "=0" 으로 표기
							 
};
class Rect : public Shape
{
	// 핵심 : Draw의 구현부를 제공하지 않으면 Rect도 추상 클래스 이다.
	//       Draw의 구현부를 제공하면 Rect는 추상이 아니다.
public:
	virtual void Draw() override {}
};
int main()
{
	Shape  s;  // error.
	Shape* p;  // ok. 
	Rect  r;   // ok. 
}
