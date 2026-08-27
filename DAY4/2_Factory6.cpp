#include <iostream>
#include <vector>
#include <map>
#include "singleton.h"

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

	// 이제 공장에는 견본 도형이 보관 됩니다.
	std::map<int, Shape*> prototype_map; 

public:

	void register_shape(int type, Shape* sample)
	{
		prototype_map[type] = sample;
	}


	Shape* create(int type)
	{
		Shape* s = nullptr;

		auto it = prototype_map.find(type);

		if (it != prototype_map.end())
		{
			// 등록된 복사본의 견본을 생성해서 반환
			// => prototype 디자인 패턴의 핵심!
			s = it->second->clone(); 
		}
		return s;
	}

};


int main()
{
	ShapeFactory& factory = ShapeFactory::get_instance();

	// 아래 코드는 공장에 함수 포인터를 등록하지만
	// => 결국 "클래스"를 등록하는 효과 입니다.
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

	// 공장에 "자주사용하는 제품" 을 등록해 봅시다

	Rect* blueRect  = new Rect;
	Rect* redRect   = new Rect;
	Circle* redCircle = new Circle;

	factory.register_shape(1, blueRect);
	factory.register_shape(2, redRect);
	factory.register_shape(3, redCircle);




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




