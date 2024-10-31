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

	// 자신의 객체를 만드는 "static 멤버 함수" 는 아주 유명한 기술입니다.
	// => 장점이 너무 많습니다.

	static Shape* create() { return new Rect; }
};

// Rect 를 만드는 2가지 방법
// 1. Shape* rc = new Rect;			// 반드시 클래스 이름(Rect)을 알아야 합니다.
// 2. Shape* rc = Rect::create();	// 클래스이름을 몰라도
									// 함수 포인터만 알면 객체 생성가능

// C++ 언어는 "클래스이름"을 자료구조에 보관할수 없습니다.
//v.push_back("Rect"); // 클래스이름이 아닌 문자열 보관
	   					// 문자열로는 객체생성 안됨.

// 하지만 함수 포인터는 자료구조에 보관가능하고, 인자로 전달도 가능
//v.push_back(&Rect::create); // 보관된 주소로 Rect 객체 생성가능.
							// 결국 "클래스"를 보관한것도 비슷한 의미






class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape* (*)(); // 함수 포인터 타입
	
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
			p = it->second();  // map 의 반복자는 std::pair 포인터
							   // pair 의 first 는 키값(int)
								// pair second 는 value(함수포인터)
		}
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에 제품을 등록합니다.
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);

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




