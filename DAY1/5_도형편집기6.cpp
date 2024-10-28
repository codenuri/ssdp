#include <iostream>
#include <vector>

// #1. 디자인 패턴이란 ?
// => 1994년 발간된 책의 제목
// => 4명의 저자가 "당시에 유행하던 코딩 스타일" 에 "이름을 부여" 한것
// => 총 23개의 이름. 
// => GoF's 의 디자인 패턴이라고 합니다.
// => "Gangs Of Four" : 4명의 갱단

// #2. prototype 패턴 : 객체의 복사본을 만들기 위해
//						clone() 가상함수를 만드는 기술
//						제대로 된 예제는 "목요일날"


// #3. 리팩토링에서 사용되는 용어 입니다. 의미를 이해해 보세요

// "replace conditional with polymorphism"
// "당신의 코드에 제어문(if, switch) 가 있다면 다형성(가상함수) 로 변경해 봐라"
//  도형편집기3.cpp => 도형편집기4.cpp
//  도형편집기5.cpp => 도형편집기6.cpp


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape\n"; }

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }


	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 사용됩니다.
	virtual Shape* clone()
	{
		Shape* p = new Shape;   // 새로운 도형을 만들고
		p->color = this->color; // 자신의 모든 멤버를 복사
								// 물론, 위 작업을 복사생성자로해도됩니다
		return p;
	}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto e : v)
			{
				e->draw();
			}
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// 다형성은 OCP를 만족하는 아주 좋은 코드이다.!!
			// => 다형성의 결국 "가상함수" 이다.

			v.push_back( v[k]->clone() ); // 다형성
							// k번째 도형이 뭔지 알필요 없다.
							// 새로운 도형이 추가되어도 이코드는
							// 변경되지 않는다.(OCP)
							// don't ask do it.
		}
	}
}


