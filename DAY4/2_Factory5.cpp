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

	virtual Rect* clone() override { return new Rect(*this); }
};




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	virtual Circle* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;

public:
	void register_shape(int key, Shape* c)
	{
		prototype_map[key] = c;
	}


	Shape* create(int key)
	{
		Shape* p = nullptr;

		auto it = prototype_map.find(key);

		if (it != prototype_map.end())
		{
			p = it->clone();	
		}
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 아래 코드는 공장에 클래스를 등록하는 효과
	// => 객체를 생성하기위한 정보 등록
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


	// 공장에 클래스가 아닌 자주 사용되는 도형의 견본을 등록해 봅시다.
	Rect* redRect = new Rect; // 빨간색, 크기 10
	Rect* blueRect = new Rect; // 파란색색, 크기 20
	Circle* circle = new Circle; // gradient 의 복잡한 색상의 원

	factory.register_shape(1, redRect);
	factory.register_shape(2, blueRect);
	factory.register_shape(3, circle);





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




