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

	// 자신의 "객체를 생성하는 static 멤버 함수"는 아주 유용하게 활용됩니다.
	static Shape* create() { return new Rect; }
};

// Rect 객체를 생성하는 방법
// 1. Rect* rc = new Rect;			// new 사용.   클래스이름을 알아야 한다.
// 2. Rect* rc = Rect::create();	// static 멤버함수 사용
									// => 함수 주소만 알아도 된다.

// C++ 에서 클래스 이름을 컨테이너에 보관할수 없다.
// v.push_back("Rect"); // 클래스 이름이 아닌 문자열을 보관한것
		    			 // 문자열 "Rect" 로는 Rect 객체 생성 안됨

// 하지만 함수 포인터는 보관 가능합니다
// v.push_back(&Rect::create); // ok. 보관된 주소로 객체 생성가능합니다.















class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape * (*)(); // 함수 포인터 타입
	
	std::map<int, CREATOR> create_map;

public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

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




