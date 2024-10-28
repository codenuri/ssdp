#include <iostream>
#include <vector>

// #1. 모든 파생 클래스의 공통의 특징은 반드시
//     기반 클래스에도 있어야 한다.
//     문법적인 규칙이 아닌 "디자인 규칙"!!

//     그래야 기반 클래스 포인터로 해당 기능을 사용할수 있다.

// #2. 기반 클래스가 가진 함수중에서
//	   파생 클래스가 override 하는 것은 반드시 virtual 이어야 한다.
//     (문법적 규칙이 아닌 디자인 규칙)


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape\n"; }
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
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
	}
}


