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


	// 자신의 객체를 생성하는 static 멤버 함수는 아주 다양하게 활용됩니다.
	static Shape* create() { return new Rect; }
};

// Rect 객체를 생성하는 방법
// 1. Rect* r = new Rect;
// 2. Rect* r = Rect::create();













class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


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

		if (cmd >= 1 && cmd <= 7) 
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




