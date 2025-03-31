#include <iostream>
#include <vector>


// #6. 디자인 패턴이란 ?
// => 1994년 발간된 책의 제목
// => 4명의 저자가 C++ 오픈소스 분석후 당시 유행하던 코딩 기법에 
//    "이름을 부여" 한것
// 
// => 23개의 이름

// => 4명의 강도들(Gang's Of Four) 라는 의미로 GOF 라고 합니다.
//    GOF 의 디자인 패턴

// #7. prototype 패턴
// => 기존 객체를 복사해서 새로운 객체를 만드는 기법
// => clone() 가상함수
// => 보다 좋은 예제는 목요일날 배우게 됩니다.


// #8. 리팩토링 서적에 있는 용어 입니다. 의미를 이해 해보세요

// => "Replace Conditional With Polymorphism"
// => "당신의 코드에 제어문(if, switch)가 있다면 다형성(가상함수)
//    로 변경하는 것을 생각해 보라"
//    "도형편집기3.cpp" 을 "도형편집기4.cpp" 로 변경해라



class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	virtual int get_area() { return -1; }

	virtual void draw() { std::cout << "draw shape\n"; }

	// 자신의 복사본을 만드는 가상함수는 아주 유용하게 활용 됩니다.
	virtual Shape* clone() { return new Shape(*this); }
};



class Rect : public Shape
{
public:
	void draw() override  { std::cout << "draw rect\n"; }

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle\n"; }

	Shape* clone() override { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();	
		}
		else if (cmd == 0)
		{
			std::cout << "몇번째 도형을 복제 할까요 ?";

			int k;
			std::cin >> k;

			// k번째 도형을 복제본을 만들어서 v에 추가합니다.
			// 어떻게 구현해야 할까요 ?
			// k번째 도형은 어떤 도형일까요 ?
			
			// 해결책 #1. 타입 조사 !!
			// => OCP 를 만족하지 못하는 나쁜 디자인..
			/*
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				v.push_back(new Rect(*(static_cast<Rect*>(v[k])));
			}
			else if((dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				v.push_back(new Circle((*(static_cast<Rect*>(v[k])));
			}
			*/

			// 해결책 #2. 다형성 활용 - 좋은 코드
			v.push_back(v[k]->clone()); // ok 다형성
										// OCP 만족
										// 새로운 도형 추가해도 
										// 코드 수정 안됨.
										
			// java 진영에서는 위 기술을
			// "don't ask, do it" 이라고 합니다. 
			// 
			// 의미를 생각해 보세요
		}
	}
}

