#include <iostream>
#include <vector>


class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};
class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw Triangle\n"; }
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
				// 해결책 #1. 캐스팅
				// => Shape* 인 s 를 Rect*, Circle* 로 캐스팅 후에 사용
				// => dynamic_cast 로 조사후 사용

				// 전통적인 if 문	   : if (조건식 조사)
				// C++17의 새로운 if 문 : if (초기화 구문; 조건식조사) 

				if (Rect* r = dynamic_cast<Rect*>(s); r != nullptr)
				{
					r->draw();
				}
				else if	(Circle* c = dynamic_cast<Circle*>(s); c != nullptr)
				{
					c->draw();
				}
			}		
		}
	}
}
// 위 코드는 컴파일/실행 문제 없습니다.
// => 좋은 디자인 일까요 ?

// 위 코드는 새로운 도형(Triangle) 이 추가되면
// => main 의 if 문이 추가되어야 합니다.
// => OCP 를 만족할수 없습니다.
// => if ~ else, switch ~ case 는 새로운 요소 추가시 항상 변해야 합니다..!
// => 더이상 추가될것이 없을때 사용해야 합니다

// 결국 위 코드는 좋은 디자인이 아닙니다




