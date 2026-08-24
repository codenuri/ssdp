#include <iostream>
#include <vector>

// 핵심 #3. 모든 도형의 공통의 특징(draw)이 있다면 기반 클래스에도 있어야 한다
// => 그래야 기반 클래스(Shape*) 타입으로 해당 특징을 사용할수 있다
// => 문법적인 규칙이 아닌 디자인 규칙



class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void draw() { std::cout << "draw Shape\n"; }
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
				s->draw();		

		}
	}
}






