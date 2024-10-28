#include <iostream>
#include <vector>


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// 핵심 : 공통성과 가변성의 분리
	// => 변하지 않은 코드 흐름 속에 있는
	// => 변해야 하는 코드는 분리되어야 한다.
	// => 변하는 것을 별도의 가상함수로 분리한다.

	virtual void draw_imp()
	{

	}

	virtual void draw() 
	{ 
		std::cout << "lock mutex\n";

		std::cout << "draw shape\n";
		
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
	void draw() { std::cout << "draw rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }

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


