#include <iostream>
#include <vector>

// 핵심 #7. 디자인 패턴이란 ?
// => 1994년 발간된 책의 제목
// => 4명의 개발자가 당시 유명한 "오픈소스를 분석후"
// => 공통으로 사용되는 코딩 스타일에 "이름 을 부여" 한것
// => 23개의 이름이 있습니다.(23개의 코딩 스타일이 있다는 의미)
// => 다른 사람의 소스를 훔친 사람들 이라는 의미로 "Gang's Of Four" 라는 의미로
//    "GOF's Design Pattern" 이라고 합니다


// 핵심 #8. Prototype 디자인 패턴
// => 견본이 되는 객체를 만들고, 복사를 통해서 객체를 생성한다.
// => "clone()" 가상함수 만드는 기술
// => 제대로 된 예제는 "목요일(4일차)"에 등장
// => 지금은 용어만 알아 두세요









class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }
	virtual void draw() { std::cout << "draw Shape\n"; }

	virtual Shape* clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
	Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
	Shape* clone() { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw(); 
			}
		}

		else if (cmd == 8)
		{
			std::cout << "몇 번째 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			// k 번째 만든 도형을 복사한 새로운 도형을 만들어서 v에 추가
			// => 어떻게 구현해야 할까요 ?
			// => k 번째 도형은 어떤 도형일까요 ?

			// 방법 #1. k 번째 도형인 어떤 종류인지 조사하자
			// => OCP 을 만족할수 없는 좋지 않은 디자인
			/*
			if (Rect* r = dynamic_cast<Rect*>(v[k]); r != nullptr)
			{
				v.push_back(new Rect(*r));
			}
			else if (Circle* c = dynamic_cast<Circle*>(v[k]); c != nullptr)
			{
				v.push_back(new Circle(*c));
			}
			*/

			// 방법 #2. 다형성 활용
			// => Don't ask Do It(물어보지(조사하지) 말고 시켜라
			// => k 번째 도형을 조사할 필요 없다.
			// => 그냥, 해당 객체에게 "복사본 좀 만들어줘" 라고 시켜라!
			v.push_back(v[k]->clone());	// 다형성 사용 !!!
										// 새로운 도형이 추가 되어도 수정되지 않는다

		}

	}
}






