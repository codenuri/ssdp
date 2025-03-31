#include <iostream>
#include <vector>

// #3-2. 해결책 2. 다형성 활용

// => 모든 도형(파생 클래스)의 공통의 특징은 반드시 Shape 에도 있어야 한다.
//    문법적인 제약이 아닌 디자인 원칙

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void draw() { std::cout << "draw shape\n"; }
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
	}
}

