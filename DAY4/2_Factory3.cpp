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



// 공장에 도형을 자동등록하는 클래스 
// => 생성자만 사용
struct AutoRegister
{
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// 전역 변수의 생성자가 언제 호출되는지 생각해 보세요
// => 모든 전역변수의 생성자는 main 함수 이전에 호출
// AutoRegiter ar(1, &Rect::create);





class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타의 특징을 생각해 보세요
	// => 객체를 한개도 만들지 않아도 메모리에 생성됩니다
	// => 프로그램 처음 실행시 생성됩니다.(결국 전역변수)
	// => 즉, main 함수 이전에 ar 생성자 호출. 
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

/*
// 아래 내용 생각해 보세요
						// Rect::ar 의 생성자 호출
						//		(결국 클래스에 대해서 한번 호출)	
Rect* r1 = new Rect;	// Rect 생성자 호출
Rect* r2 = new Rect;	// Rect 생성자 호출
Rect* r2 = new Rect;	// Rect 생성자 호출
						// 생성자는 객체당 한번씩 호출

// C# 에는 static 생성자라는 문법이 있습니다.
class Car
{
	public Car() {} // instance 생성자
	static Car() {} // static 생성자, 접근지정자 표기 안함
};

Car c1 = new Car(); // static 생성자 호출
					// instance 생성자 호출
Car c2 = new Car(); // instance 생성자 호출
*/

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }


	// C++17 inline static 으로 하면 외부 선언 없어도 됨
	// 단, 클래스 안에서는 () 가 아닌 {} 초기화 사용
	inline static AutoRegister ar{ 2, &Circle::create };
};





int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 이미 각 도형의 static 멤버인 ar 의 생성자에서 공장에 등록 완료!!
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

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




