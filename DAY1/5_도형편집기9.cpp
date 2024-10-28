#include <iostream>
#include <vector>


// 최종 버전
// => 코드 정리


class unsupported_operation {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";

	}
	void set_color(int c) { color = c; }

protected:
	virtual void draw_imp() = 0;


public:
	virtual Shape* clone() { throw unsupported_operation(); }

	virtual int get_area() { return -1; }

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


