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

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;

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

// 제품(도형)을 공장에 등록하기 위한 클래스
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().register_shape(key, f);
	}
};

// 전역변수의 생성자가 호출되는 시점을 생각해 보세요
// => main 함수가 실행되기전, 프로그램 처음시작될때 호출
//AutoRegister ar(1, &Rect::create);






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타가 언제 생성되는지 생각해 보세요
	// => 결국 전역변수와 유사하므로, main 함수 이전에 생성자가 호출됩니다
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

/*
						// Rect::ar 의 생성자 호출
Rect* r1 = new Rect; // Rect 생성자 호출
Rect* r2 = new Rect; // Rect 생성자 호출
Rect* r3 = new Rect; // Rect 생성자 호출
					 // 즉, Rect 생성자는 "객체당 한번씩" 호출

// C#
class Car
{
	public Car() {} // 인스턴스 생성자
	static Car() {} // static 생성자
};
	
Car c1 = new Car();	// static 생성자가 먼저 호출되고
					// instance 생성자 호출
Car c2 = new Car();	// instance 생성자 호출
*/







class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	inline static AutoRegister ar{ 2, &Circle::create };
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	// main 함수 실행전에 이미 도형은 공장에 등록되었습니다.
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


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




