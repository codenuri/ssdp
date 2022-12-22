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

	// 자신의 객체를 만드는 "static 멤버 함수"는 아주 유용하게 
	// 활용될수 있습니다.
	static Shape* Create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* r1 = new Rect;
// 2. Rect* r2 = Rect::Create();

// 함수 인자에 따라 다른 도형의 객체를 만들려고 합니다.
// => 단, 미래에 만들어질 도형까지 포함
// => 미래에 만들어질 도형은 클래스 이름을 모르므로 "new ??" 할수 없습니다.
void make_shape(Shape*(*f)() )
{
	Shape* p = f(); // 인자에 따라 다른 도형 생성
					// MFC, QT, wxWidget 등의 라이브러리에서 이 기능을
					// "동적 생성" 이라고 불렀습니다.
}

// 방법 1. 문자열로 클래스 이름을 알려주면 어떻까 ?
// => C++ 은 클래스 이름을 문자열로 알아도 객체를 생성할수 없다.
// => C#, swift 등은 가능
//make_shape("Rect");
//make_shape("Triangle");

// 방법 2. 클래스이름을 보내지 말고 클래스의 객체를 만드는 약속된 함수를
// 보내면 ?? "결국 클래스를 보내는 것과 같은 효과 아닐까 ?"
make_shape(&Rect::Create);
make_shape(&Triange::Create);









class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* Create(int type)
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




