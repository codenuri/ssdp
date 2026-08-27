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

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;

public:

	void register_shape(int type, CREATOR c)
	{
		create_map[type] = c;
	}


	Shape* create(int type)
	{
		Shape* s = nullptr;

		auto it = create_map.find(type);

		if (it != create_map.end())
		{
			s = it->second();
		}
		return s;
	}
};

// 제품을 공장에 자동으로 등록하는 클래스
// => 생성자만 사용하기 위해 만든 클래스
class AutoRegister
{
public:
	AutoRegister(int type, Shape* (*f)())
	{
		// 아래 코드 때문에 ShapeFactory 가 위에 있어야 했던것!!
		ShapeFactory::get_instance().register_shape(type, f);
	}
};

// 전역변수의 생성자는 언제 호출되는지 생각해보세요
// => main 함수 이전에 호출
// => 즉, 아래 전역변수가 있다면 main 함수 이전에 공장에 Rect등록됩니다.
//AutoRegister ar(1, &Rect::create);












class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타에 대해서 생각해 보세요
	// => 객체를 여러개 만들어도 한개만 존재
	// => 객체를 만들지 않아도 메모리에 존재
	// => 결국 "전역변수와 동일"
	// => 결국 "Rect 용 전역변수" 만든것
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

// 아래 코드 생각해 보세요
					 // Rect::ar 의 생성자 호출 - Rect 타입에 대해서 1회 호출
											// 아래 C#의 static 생성자와 유사
Rect* r1 = new Rect; // Rect() 생성자 호출
Rect* r2 = new Rect; // Rect() 생성자 호출
Rect* r3 = new Rect; // Rect() 생성자 호출



/*
// C# 에는 static 생성자라는 문법이 있습니다
class Car
{
	public Car() {} // 인스 턴스 생성자 - 객체당 1회 호출
	static Car() {} // static 생성자- 최초 1회 호출. 즉, 클래스에대해서 1회 호출
};

Car c1 = new Car(); // static 생성자 호출  - 클래스 초기화
					// 생성자 호출
Car c2 = new Car(); // 생성자 호출	- 객체 초기화
Car c2 = new Car(); // 생성자 호출	- 객체 초기화
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
	ShapeFactory& factory = ShapeFactory::get_instance();

	// 이제 공장에 등록하는 코드는 
	// => Rect, Circle 클래스 내부의 static 멤버 데이터인 ar 이 자동으로 수행합니다.
	// => 아래 2줄 필요 없습니다
	// => main 실행전에 이미 등록 완료!
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);


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




