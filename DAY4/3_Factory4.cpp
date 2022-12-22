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

// ShapeFactory 이 위치에 놓으세요
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

// 공장에 도형을 등록하는 클래스
class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(type, f);
	}
};

// 전역변수의 생성자가 언제 실행되는지 생각해 보세요
// AutoRegister ar(1, &Rect::Create);







class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }


	// static 멤버 데이타가 언제 생성되는지 생각해 보세요
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);

// Rect::ar 의 생성자 => main 함수가 실행되기전 단 한번 호출됩니다.
// 
// new Rect() => Rect 생성자 호출
// new Rect() => Rect 생성자 호출

// 즉, 
// 1. Rect 생성자는 "객체를 만들때 마다 호출" - 인스턴스 생성자
// 2. Rect::ar 의 생성자는 "Rect" 타입에 대해 최초에 한번 호출
//    => C#의 static 생성자 입니다.
//    => C++ 에 이문법이 없어서, static 멤버로 유사한 효과를 만든것





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);







int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);



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





// 참고 C# 코드 
/*
class Car
{
	public Car() {}			// instance 생성자 - 객체를 만들때 마다 호출
	static public Car() {}  // static 생성자 - 최초에 1회만 호출
};
*/