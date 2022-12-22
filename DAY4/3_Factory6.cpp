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

	static Shape* Create() { return new Rect; }

	virtual Rect* clone() override { return new Rect(*this); }

};



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	virtual Circle* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;

public:
	void Register(int key, Shape* sample)
	{
		prototype_map[key] = sample;
	}

	Shape* Create(int type)
	{
		Shape* p = nullptr;

		auto ret = prototype_map.find(type);

		if (ret != prototype_map.end())
		{
			p = ret->second->clone(); // 복사본 객체 생성
		}

		return p;
	}
};




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// 아래 코드는 결국 공장에 클래스를 등록 하는 의미 입니다.
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);


	// 공장에 "클래스" 가 아니라 자주 사용되는 "객체" 를 등록해 봅시다.
	Rect* redRect = new Rect;	// 빨간색 크기 5 사각형이라고 가정
	Rect* blueRect = new Rect;	
	Circle* redCircle = new Circle;

	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, redCircle);

	// 복습하다가 아래 함수 구현해 보세요
	factory.ShowRegisteredSample(); // 등록된 모든 견본 객체를 보여준다
									// 1. redRect
									// 2. blueRect
									// 3. redCircle







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




