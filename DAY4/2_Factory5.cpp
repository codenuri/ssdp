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


	static Shape* create() { return new Rect; }
};



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)(); 

	inline static std::map<int, CREATOR> create_map;

public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = create_map.find(key);

		if (it != create_map.end())
		{
			p = it->second(); 
		}
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	
	// 공장에 "생성함수 포인터"를 등록하는 코드
	// => 결국 "클래스"를 등록하는 의미
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

	
	// 공장에 자주 사용되는 도형 객체를 등록해 봅시다.
	Rect* red_rect = new Rect;
	Rect* blue_rect = new Rect;
	Circle* red_circle = new Circle;

	factory.register_shape(1, red_rect);
	factory.register_shape(2, blue_rect);
	factory.register_shape(3, red_circle);



	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8)
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




