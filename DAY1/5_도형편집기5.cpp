#include <iostream>
#include <vector>



class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	virtual int get_area() { return -1; }
	virtual void draw() { std::cout << "draw Shape\n"; }

	virtual Shape* clone() { return new Shape(*this); }
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
	Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
	Shape* clone() { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw();
			}
		}

		else if (cmd == 8)
		{
			std::cout << "몇 번째 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());	

		}

	}
}






