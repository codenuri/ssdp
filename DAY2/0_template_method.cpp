#include <iostream>
#include <vector>


class unsupported_operation {};

class Shape
{
	int color = 0;

protected:
	Shape() {}

public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }


	// template method 패턴
	// => 변하는 것을 가상함수로!
	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";
	}

protected:
	virtual void draw_imp() = 0;





public:
	virtual Shape* clone() { throw unsupported_operation(); }

	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect\n"; }

	Shape* clone()  override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw circle\n"; }

	Shape* clone() override { return new Circle(*this); }
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

			v.push_back(v[k]->clone()); // 다형성, OCP 만족

		}
	}
}


