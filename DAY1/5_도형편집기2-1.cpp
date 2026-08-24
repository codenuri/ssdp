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






