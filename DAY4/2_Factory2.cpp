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
// 1. Shape* r = new Rect;		 // 객체 생성을 위해 반드시 클래스 이름을 알아야 합니다
// 2. Shape* r = Rect::create(); // 클래스 이름 몰라도 됩니다. create 함수 주소만 알면됩니다.

// C++ 에서 "자료구조에 클래스 이름을 보관" 할수 없습니다 - C# 등은 가능
// v.push_back("Rect"); // "Rect" 라는 문자열을 보관 한것. "Rect" 문자열로 Rect 객체 생성 못함

// 하지만 함수 포인터는 보관 가능합니다.
// v.push_back(&Rect::create); // 보관된 함수 포인터로 Rect 객체 생성 가능합니다.
	   						   // 결국 객체 생성을 위한 클래스 정보를 보관하는 기능
								// 결국 클래스를 보관하는 것과 유사한 기능을 할수 있습니다









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

	std::map<int, CREATOR> create_map; // <도형번호, 생성함수주소>
	
public:

	void register_shape(int type, CREATOR c)
	{
		create_map[type] = c;
	}


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




