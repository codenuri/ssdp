#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	int  get_color() { return color; }
	void set_color(int c) { color = c; }

	virtual int get_area() { return -1; }


	virtual void draw() { std::cout << "draw Shape" << std::endl; }
};




class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw Triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)       v.push_back(new Rect);
		else if (cmd == 2)	v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}

		else if (cmd == 8)
		{
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// 해결책 1. dynamic_cast로 타입 조사하자.
			Rect* pr;
			Circle* pc;
			if ( (pr = dynamic_cast<Rect*>(v[k])) != nullptr )
			{
				v.push_back(new Rect); // 정확히는 p와 동일하게 설정후
			}
			else if ((pc = dynamic_cast<Circle*>(v[k])) != nullptr)
			{
				v.push_back(new Circle);
			}
		}
	}
}






