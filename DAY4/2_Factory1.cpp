#include <iostream>
#include <vector>
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
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// 도형을 만드는 팩토리

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if      (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8)  // 1 ~ 7 을 도형의 번호로 예약
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);		

			//이제 새로운 도형이 추가되어도 이 코드는 변경되지 않습니다.
		}



		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw(); // OCP 만족, 새로운 도형이 추가되어도
							  // 이 코드는 수정되지 않음.
			}
		}
	}
}




