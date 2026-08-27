#include <iostream>
#include <vector>
#include <map>
#include "singleton.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// 도형을 만드는 공장을 만들어 봅시다
class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

public:
	Shape* create(int type)
	{
		Shape* s = nullptr;

		switch (type)
		{
		case 1: s = new Rect; break;
		case 2: s = new Circle; break;
		}
		return s;
	}
	
};


int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if		(cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




