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
	ShapeFactory& factory = ShapeFactory::get_instance();

	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7) // 1 ~ 7 까지를 도형 번호로 예약
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




