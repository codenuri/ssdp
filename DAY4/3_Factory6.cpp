#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

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

	static Shape* Create() { return new Rect; }
};



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)(); 

	std::map<int, CREATOR> creator_map;

public:
	void Register(int key, CREATOR create)
	{
		creator_map[key] = create;
	}


	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = creator_map.find(type);

		if (ret != creator_map.end())
		{
			p = (ret->second)();
		}

		return p;
	}
};




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);



	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
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




