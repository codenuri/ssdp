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

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;

public:

	void register_shape(int type, CREATOR c)
	{
		create_map[type] = c;
	}


	Shape* create(int type)
	{
		Shape* s = nullptr;

		auto it = create_map.find(type);

		if (it != create_map.end())
		{
			s = it->second();
		}
		return s;
	}
};

// 제품을 공장에 자동으로 등록하는 클래스
class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*f)())
	{
		// 아래 코드 때문에 ShapeFactory 가 위에 있어야 했던것!!
		ShapeFactory::get_instance().register_shape(type, f);
	}
};

// 전역변수의 생성자는 언제 호출되는지 생각해보세요
AutoRegister ar(1, &Rect::create);












class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }


	static Shape* create() { return new Rect; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};





int main()
{
	ShapeFactory& factory = ShapeFactory::get_instance();

	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


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




