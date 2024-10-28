#include <iostream>
#include <vector>

// #1. template method 패턴
// => 변하지 않은 전체적인 흐름속에 담긴 변해야 하는 것을 찾아서
//    별도의 가상함수로 분리하는 패턴

// => 파생클래스에게
// => 공통의 규칙을 물려 주지만
// => 변해야 하는 것만 변경할수 있게 하는 디자인 패턴





class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// 핵심 : 공통성과 가변성의 분리
	// => 변하지 않은 코드 흐름 속에 있는
	// => 변해야 하는 코드는 분리되어야 한다.
	// => 변하는 것을 별도의 가상함수로 분리한다.

protected:
	virtual void draw_imp()
	{
		std::cout << "draw shape\n";
	}
	// 아래 함수는 변하지 않은 공통의 규칙이므로 override 하지 않게된다
	// non-virtual 
public:
	void draw() 
	{ 
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}







	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }


	virtual Shape* clone()
	{
		Shape* p = new Shape;   
		p->color = this->color; 
		return p;
	}
};

class Rect : public Shape
{
public:
	void draw_imp() { std::cout << "draw rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() { std::cout << "draw circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto e : v)
			{
				e->draw();
			}
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;


			v.push_back(v[k]->clone()); 

		}
	}
}


