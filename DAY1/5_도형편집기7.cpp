#include <iostream>
#include <vector>

// 코드 정리

class unsupported_operation {};

class Shape
{
	int color = 0;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "mutex.lock\n";
		draw_imp();
		std::cout << "mutex.unlock\n";
	}
	virtual void draw_imp() = 0;	

	virtual Shape* clone() { throw unsupported_operation(); }

	virtual int get_area() { return -1; }

};

class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }
	Shape* clone()  override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle\n"; }
	Shape* clone()  override { return new Circle(*this); }
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

		else if (cmd == -1) break;
	}

	for (auto s : v)
		delete s;
}






