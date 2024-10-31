#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	static Shape* create() { return new Rect; }

	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	Shape* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	inline static std::map<int, Shape*> sample_map;

public:
	void register_shape(int key, Shape* c)
	{
		sample_map[key] = c;
	}

	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = sample_map.find(key);

		if (it != sample_map.end())
		{
			p = it->second->clone(); // 이렇게 사용하는 것이
									 // "prototype" 패턴
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
	Circle* red_circle = new Circle; // 이 원을 만들려면
									 // 생성자 인자가 복잡하고
									  // 생성후 많은 추가작업 필요

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




